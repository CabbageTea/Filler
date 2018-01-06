/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:01:42 by dglaser           #+#    #+#             */
/*   Updated: 2018/01/01 22:53:45 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(const char *str);
int					ft_atoi(const char *str);
int					ft_isprint(int c);
char				*ft_strdup(const char *src);
void				*ft_memccpy(void *dest, const void *src, int c,
					size_t n);
void				ft_bzero(void *str, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int a);
int					ft_isdigit(int a);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *str, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t len);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t num);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *big, const char *lit);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putendl(char const *s1);
void				ft_putstr_fd(char const *s1, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int num);
int					ft_intlen(intmax_t a);
int					ft_unintlen(uintmax_t a);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int a);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *big, const char *lit, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newzies);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *ele));
int					ft_isspace(char c);
void				ft_swap(int *a, int *b);
void				ft_un_putnbr(uintmax_t a);
void				ft_putintstr(int *num);
void				ft_putnbrmax(intmax_t a);
void				ft_putnbrunmax(uintmax_t a);
int					ft_wstrlen(wchar_t *str);

#endif
