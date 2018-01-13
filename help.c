#include "filler.h"


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
		grid->mine = 'x';
	}
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
	return (stars);
}

void	ft_therest(int stars, t_map *grid, int x, int y)
{
	int i;

	i = 0;
	while (x < grid->psizex && i < stars)
	{
		y = 0;
		while (y < grid->psizey)
		{
			if (grid->piece[x][y] == '*')
			{
				if (x == grid->firstpx && y == grid->firstpy)
					y++;
				else
				{
					grid->pcoordx[i] = y;
					grid->pcoordy[i] = x; //actually got this backwards but whatev
					i++;
				}
			}
			y++;
		}
		x++;
		fprintf(stderr, "the pcoordy 2 %d", grid->pcoordy[1]); //
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
					x = grid->firstpx;
					y = grid->firstpy;
					ft_therest(stars, grid, x, y);
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

void	ft_answer(t_map *grid)
{
	if (grid->plnum == 1)
	{
		grid->targetx = grid->width;
		grid->targety = grid->height;
	}	
	else
	{
		grid->targetx = 0;
		grid->targety = 0;
	}
/*	if (grid->targetx = grid->width)
		ft_attack1;
	
	else

	ft_attack2;
	*/
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
//	if (grid.gameover == 1)
//		ft_putstr("0 0");
	
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
