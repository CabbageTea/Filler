#include "filler.h"

int		ft_countpsize(t_map *grid)
{
	int i; 
	int x;
	int ret;

	i = 0;
	ret = 0;
	while (i < grid->psizey)
	{
		x = 0;
		while(x < grid->psizex)
		{
			if (grid->piece[i][x] == '*')
				ret++;
			x++;
		}
		i++;
	}
//	fprintf(stderr, "%d", ret); ///
	return (ret);
}

void	ft_readpcoords(t_map *grid)
{
	int stars;
	int i;
	int x;
	int y;

	y = 0;
	x = 0;
	i = 0;
	fprintf(stderr, "\nin readpcoords"); ///
	stars = ft_countpsize(grid);
	grid->coordsy = (int *)malloc(sizeof(int) * stars) + 1;
	grid->coordsx = (int *)malloc(sizeof(int) * stars) + 1;
	while (y < grid->psizey)
	{
		while (x < grid->psizex)
		{ 
			if (grid->piece[y][x] == '*' && i == 0)
			{
				grid->coordsy[i] = y;
				grid->coordsx[i] = x;
				i++;
			}
			if (grid->piece[y][x] == '*' && i != 0)
			{
				grid->coordsy[i] = y - grid->coordsy[0];
				grid->coordsx[i] = x - grid->coordsx[0];
				i++;
			}
		x++;
		}
		y++;
	}
	fprintf(stderr, " y = %d, x = %d", grid->coordsy[0], grid->coordsx[0]); ///
}

void	ft_savep(t_map *grid)
{
	int i;
	char *board;
	char *full;
//fprintf(stderr, "\nwtf is going on");
	i = 0;
	full = NULL;
	board = NULL;
	grid->piece = (char **)ft_memalloc(sizeof(char *) * (grid->psizey)) + 1;
	fprintf(stderr, "This is psizey :%d", grid->psizey); ///
	while (i < grid->psizey)
	{
//		ft_strdel(&board);
		get_next_line(0, &board);
		fprintf(stderr, "the loop ->%s", board);
	//	grid->piece[i] = ft_strdup(board); //
	///	fprintf(stderr, "\nthis is the piece line %s\n", grid->piece[i]);///
		i++;
	}
	fprintf(stderr, "this is what's here%s", grid->piece[0]);
	ft_readpcoords(grid);
}

void	ft_psizex(char *r, t_map *grid)
{
	int i;
	int x;
   	char ret[2];
	
	i = 6;
	x = 0;
//	fprintf(stderr, "%c", r[i]);
	while (ft_isdigit(r[i]))
	{
		ret[x] = r[i];
		i++;
		x++;
	}
	ret[x] = '\0';
	grid->psizex = ft_atoi(ret);
}

void	ft_psizey(char *r, t_map *grid)
{
	int i;
	int x;
	char ret[2];

	i = 7;
	x = 0;
	if (ft_isdigit(r[i]))
		i++;
	i++;
		while (ft_isdigit(r[i]))
		{
			ret[x] = r[i];
			x++;
			i++;
		}
	ret[x] = '\0';
	grid->psizey = ft_atoi(ret);
}

void	ft_pieceinfo(t_map *grid)
{
	fprintf(stderr, "\nin piece info"); ////
	char *r;

	r = NULL;
	get_next_line(0, &r);
	ft_psizey(r, grid);
	ft_psizex(r, grid);
	ft_savep(grid);
}

void	ft_mallocboard(t_map *grid)
{
	int i;
	fprintf(stderr, "\nin malloc board"); /////

	i = 0;
	grid->board = (char **)ft_memalloc(sizeof(char *) * (grid->height * grid->width));
}

void	ft_readboard(t_map *grid)
{
	char *line;
	int i;
	fprintf(stderr, "\n in read board"); /////
	i = 0;
	line = NULL;
	get_next_line(0, &line);
	while(i < grid->height)
	{
		ft_strdel(&line);
		get_next_line(0, &line);
		grid->board[i] = ft_strdup(line + 4);
		i++;
	}
}

void	ft_setplayer(char *parse, t_map *grid)
{
	fprintf(stderr, "\nin set player"); ////
	fprintf(stderr, "\n This is parse : %s", parse); /////
	ft_bzero(grid, sizeof(t_map));
	if (ft_strstr(parse, "p1"))
		grid->plnum = 1;
	else if (ft_strstr(parse, "p2"))
		grid->plnum = 2;
	get_next_line(1, &parse);
	if (grid->plnum == 1)
		grid->mine = 'O';
	else
		grid->mine = 'X';
	if (ft_strstr(parse, "Plateau 15 17"))
	{
		grid->height = 15;
		grid->width = 17;
	}
	if (ft_strstr(parse, "Plateau 24 40"))
	{
		grid->height = 24;
		grid->width = 40;
	}
	if (ft_strstr(parse, "Plateau 100 99"))
	{
		grid->height = 100;
		grid->width = 99;
	}
}
void	ft_answer(t_map *grid)
{
	fprintf(stderr, "hello?"); /////
	ft_putnbr(12);
	ft_putchar(' ');
	ft_putnbr(14);
	grid->gameover = 1;

}

int		main(void)
{
	char *parse;
	t_map grid;
	get_next_line(0, &parse);
//	fprintf(stderr, "\nthis is what is in parse : %s\n", parse);
	ft_setplayer(parse, &grid);
	ft_mallocboard(&grid);
	while (grid.gameover != 1)
	{
		ft_readboard(&grid);
		ft_pieceinfo(&grid);
		ft_answer(&grid);
	}
return (0);
}





