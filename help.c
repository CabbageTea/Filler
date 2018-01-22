#include "filler.h"

void	ft_setenemy(t_map *grid)
{
	if (grid->mine == 'O')
	{
		grid->enemy = 'X';
		grid->senemy = 'x';
	}
	else
	{
		grid->enemy = 'O';
		grid->senemy = 'o';
	}
}

void	ft_setplayer(t_map *grid)
{
	char *line;

	line = NULL;
	ft_bzero(grid, sizeof(t_map));
	get_next_line(0, &line);
	if (ft_strstr(line, "p1"))
	{
		grid->plnum = 1;
		grid->mine = 'O';
		grid->smine = 'o';
	}
	else
	{
		grid->plnum = 2;
		grid->mine = 'X';
		grid->smine = 'x';
	}
	ft_setenemy(grid);
	free(line);
}

void	ft_setboardsize(t_map *grid)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (line[9] == '5')
	{
		grid->height = 15;
		grid->width = 17;
	}
	if (line[9] == '4')
	{
		grid->height = 24;
		grid->width = 40;
	}
	if (line[9] == '0')
	{
		grid->height = 100;
		grid->width = 99;
	}
	free(line);
}

void	ft_readboard(t_map *grid)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	//I"M NOT SKIPPING ONE LINE
	get_next_line(0, &line);
	while (i < grid->height)
	{
		ft_strdel(&line);
		get_next_line(0, &line);
		grid->board[i] = ft_strdup(line + 4);
		i++;
	}
	grid->gameover = 1; // take this out 
}

void	ft_psizey(char *line, t_map *grid)
{
	int i;
	int x;
	char ret[2];

	i = 7;
	x = 0;
	if (ft_isdigit(line[i]))
		i++;
	i++;
	while (ft_isdigit(line[i]))
	{
		ret[x] = line[i];
		x++;
		i++;
	}
	ret[x] = '\0';
	grid->psizey = ft_atoi(ret);
}

void	ft_psizex(char *line, t_map *grid)
{
	int i; 
	int x;
	char ret[2];

	i = 6;
	x = 0;
	while (ft_isdigit(line[i]))
	{
		ret[x] = line[i];
		i++;
		x++;
	}
	ret[x] = '\0';
	grid->psizex = ft_atoi(ret);
}

int		ft_countstars(t_map *grid)
{
	int x;
	int y;
	int stars;

	stars = 0;
	x = 0;
	while (x < grid->psizex)
	{
		y = 0;
		while (y < grid->psizey)
		{
			if (grid->piece[x][y] == '*')
				stars++;
			y++;
		}
		x++;
	}
	grid->stars = stars;
	return (stars);
}

void	ft_therest(int stars, t_map *grid, int x, int y)
{
	int i;
	i = 0;
	fprintf(stderr, "In the rest:");
	while (x < grid->psizex && i < stars)
	{
		y = 0;
		while (y < grid->psizey)
		{
			if (grid->piece[x][y] == '*')
			{
				if (x != grid->firstpx || y != grid->firstpy)
				{
					grid->pcoordy[i] =  x - grid->firstpy;
					grid->pcoordx[i] = y - grid->firstpx;
					fprintf(stderr, "\nthis is pcoordy%d", grid->pcoordy[i]);//
					i++;
					fprintf(stderr, "\n y = :%d", y);///
				}
			}
			y++;
		}
		x++;
	//	fprintf(stderr, "the pcoordy 2 %d", grid->pcoordy[1]); //
	}
}

void	ft_savefirstcoords(t_map *grid)
{
	int stars;
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	x = 0;
	stars = ft_countstars(grid);
	while (i < stars)
	{
		while (x < grid->psizex)
		{
			y = 0;
			while (y < grid->psizey)
			{
				if (grid->piece[x][y] == '*')
				{
					grid->firstpx = y;
					grid->firstpy = x;
					ft_therest(stars, grid, y, x);
					return ;
				}
				y++;
			}
			x++;
		}
	}
}

void	ft_savepiece(t_map *grid)
{	
	char *line;
	int i;

	line = NULL;
	i = 0;
	while (i < grid->psizex)
	{
		ft_strdel(&line);
		get_next_line(0, &line);
		grid->piece[i] = ft_strdup(line);
		i++;
	}
	free(line);
	ft_savefirstcoords(grid);
}

void	ft_readpiece(t_map *grid)
{
	char *line;
	
	line = NULL;
	get_next_line(0, &line);
	ft_psizey(line, grid);
	ft_psizex(line, grid);
	free(line);
	ft_savepiece(grid);
}

int		ft_splitquad(int wmin, int wmax, int hmin, int hmax, t_map *grid)
{
	int i;
	int x;
	int ret;

	ret = 0;
	x = wmin;
	i = hmin;

	while (i <= hmax)
	{
		x = wmin;
		while (x <= wmax)
		{
			if (grid->board[i][x] == '.')
				ret++;
			x++;
		}
		i++;
	}
	return (ret);
}
void	ft_findtarget(t_map *grid, int a, int b, int c, int d)
{
	a = grid->quad_a;
	b = grid->quad_b;
	c = grid->quad_c;
	d = grid->quad_d;
	fprintf(stderr, "in target");

	if (d <= a && d <= b && d <= c)
	{
		grid->targety = grid->height - 1;
		grid->targetx = grid->width - 1;
	}
	if (c <= d && c <= b && c <= a)
		grid->targety = grid->height - 1;
	if (b <= d && b <= c && b <= a)
		grid->targetx = grid->width - 1;
}

int		ft_isfree(t_map *grid, int x, int y, int i)
{
	int overlap;
//	fprintf(stderr, "in is free");//
	overlap = 0;
	if (grid->board[y][x] == grid->mine || grid->board[y][x] == grid->smine)
		overlap++;
	while(i < grid->stars)
	{
		if (grid->board[y + grid->pcoordy[i]][x + grid->pcoordx[i]] == grid->enemy
			   || grid->board[y + grid->pcoordy[i]][x + grid->pcoordx[i]] == grid->senemy
			|| overlap > 1 || y + grid->pcoordy[i] > grid->height || x + grid->pcoordx[i] > grid->width)
		{
	//	fprintf(stderr,"returning 0");	
		   return (0);
		}
		if (grid->board[y + grid->pcoordy[i]][x + grid->pcoordx[i]] == grid->mine ||
				grid->board[y + grid->pcoordy[i]][x + grid->pcoordx[i]] == grid->smine)
		{
			overlap++;
	//		fprintf(stderr, "OVERLAP = 1");
		}
//		fprintf(stderr, "am I returning 0 everytime?");
		i++;
	}
	if (overlap == 1)
		return (1);
	return (0);
}

void	ft_findbestplace(t_map *grid, int x, int y)
{
//	fprintf(stderr, "in find best");///
	y = grid->targety;
	x = grid->targetx;
//	fprintf(stderr, "this is x : %d, this is y :%d", x, y);
	while (y > -1)
	{
		x = grid->targetx;
		fprintf(stderr, "\n");
		while (x > -1)
		{	
			fprintf(stderr, "%c", grid->board[y][x]);
			if (grid->board[y][x] == '.' || grid->board[y][x] == grid->smine
				|| grid->board[y][x] == grid->mine)
		{
	//		fprintf(stderr, "SPSPS");///
			if (ft_isfree(grid, x, y, 0) == 1)
			{
				fprintf(stderr, "SOLUTION");
				ft_putnbr(y);
				ft_putchar(' ');
				ft_putnbr(x);
				return ;
			}
		}
			x--;
		}
		y--;
	}
	grid->gameover = 1;
}
void	ft_answer(t_map *grid)
{
	int halfw;
	int halfh;

	halfw = (grid->width / 2);
	halfh = (grid->height / 2);

	grid->quad_a = ft_splitquad(0, halfw, 0, halfh, grid);
	grid->quad_b = ft_splitquad(halfw, grid->width - 1, 0, halfh, grid);
	grid->quad_c = ft_splitquad(0, halfw, halfh, grid->height - 1, grid);
	grid->quad_d = ft_splitquad(halfw, grid->width - 1, halfh, grid->height - 1, grid);
	ft_findtarget(grid, 0 , 0 , 0, 0);
	ft_findbestplace(grid, 0, 0);
}

int		main(void)
{
	t_map grid;
	ft_setplayer(&grid);
	ft_setboardsize(&grid);
	while (grid.gameover != 1)
	{
		ft_readboard(&grid);
		ft_readpiece(&grid);
		ft_answer(&grid);
	}
	if (grid.gameover == 1)
		ft_putstr("0 0");
	
//	fprintf(stderr, "\nthis is width : %d", grid.width);
//	fprintf(stderr, "\nthis is psizex : %d", grid.psizex);
//	fprintf(stderr, "\nthis is psizey : %d", grid.psizey);
//	fprintf(stderr, "
	int i;
	i = 0;
	while (i < grid.psizex)
	{
		fprintf(stderr, "\n%s", grid.piece[i]);
		i++;
	}
}
