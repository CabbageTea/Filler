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
	int		plnum;
	int		width;
	int		height;
	int		*pcoords;
	char	mine;
	char	enemy;
	int		psizex;
	int		psizey;
	char	**board;
	char	**piece;
	int		**coords;
	int		gameover;
	

} t_map;

#endif
