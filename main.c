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
			if (piece[i][x] == '*')
				ret++;
			x++;
		}
		i++;
	}
	return (ret);
}

void	ft_readpcoords(t_map *grid)
{
	int stars;
	stars = ft_countpsize(&grid);
	grid->coords = (int **)malloc(sizeof(int *) * stars + 1);
	
	


void	ft_savep(t_map *grid)
{
	int i;
	char *board;

	i = 0;
	board = NULL;
	grid->piece = (char **)malloc(sizeof(char *) * (grid->psizey * grid->psizex));
	while (i < grid->psizey)
	{
		ft_strdel(board);
		get_next_line(1, &board);
		grid->piece[i] = board;
		i++;
	}
	ft_readpcoords(&grid);
}


void	ft_pieceinfo(t_map *grid)
{
	char *r;
	int i;
	int t;
	char *x; 
	char *y;

	y = NULL;
	x = NULL;
	i = 6;
	t = 0;
	get_next_line(1, r);
	while (ft_isdigit(r[i]))
		y[++t] = r[++i];
	i++;
	t = 0;
	while (ft_isdigit(r[i]))
		x[++t] = r[++i];
	grid->psizey = ft_atoi(y);
	grid->psizex = ft_atoi(x);
	ft_savep(&grid);
}

void	ft_mallocboard(t_map *grid)
{
	int i;

	i = 0;
	char *line;

	line = NULL;
	grid->board = (char **)malloc(sizeof(char *) * (grid->height * grid->width));
}
void	ft_readboard(t_map *grid)
{
	get_next_line(1, &line);
	while(i < grid->height)
	{
		ft_strdel(line);
		get_next_line(1, &line);
		grid->board[i] = line + 4;
		i++;
	}
}


void	ft_setplayer(char *parse, t_map *grid)
{
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

int		main(void)
{
	char *parse;
	t_map grid;
	get_next_line(1, &parse);
	ft_putstr_fd("help", 2);
	ft_setplayer(&grid);
	ft_mallocboard(&grid);
	while (grid->gameover != 1);
	{
		ft_readboard(grid);
		ft_pieceinfo(&grid);
		ft_answer(&grid);
	}
}





