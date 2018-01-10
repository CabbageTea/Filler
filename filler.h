#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include "get_next_line.h"

typedef struct			s_parse
{
	int		plnum; // player number
	int		width; // width of board
	int		height; // height of board 
	int		*firstp[1];
	int		*pcoords[100]; // piece coordinates
	char	smine;
	char	mine; // my piece
	char	enemy; // enemy piece
	int		psizex; // piece grid size
	int		psizey; // ^
	char	*board[101]; // where the entire board is saved - pls forgive me
	char	*piece[100]; // where the entire piece board is saved - so bad
	int		*coordsy; // int array of coords
   	int 	*coordsx; // int array of pcoords
	int		gameover; // flag that tell us to stop the game

	int		quad_a;
	int 	quad_b;
	int		quad_c;
	int		quad_d;

	

} t_map;

#endif
