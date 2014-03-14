/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:19:29 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/01 16:50:49 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define UCHAR unsigned char
# define UINT unsigned int
# define TRUE 1
# define FALSE 0

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int		ft_iabs(int i);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isspace(char c);
int		ft_isblank(char c);
int		ft_strlen2(char **s);
int		ft_powi(int i, int p);
int		ft_atoi(const char *str);
int		ft_indexof(char *str, char c);
int		get_next_line(int const fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strequ(char const *s1, char const *s2);
int		ft_startswith(const char *str, const char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);

char	*ft_itoa(int n);
char	*ft_strnew(size_t size);
char	*ft_strtrim(char const *s);
char	*ft_strdup(const char *str);
char	**ft_sort_strs(char **tab, int n);
char	**ft_strsplit_trim(char const *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	**ft_strsplit(char const *s, char c);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_strclr(char *s);
void	ft_putlong(long l);
void	ft_strdel(char **as);
void	ft_memdel(void **ap);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	*ft_memalloc(size_t size);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_free_double_tab(char ***s);
void	ft_swap_ptr(void **s1, void **s2);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putfloat(float f, unsigned int p);
void	ft_swap_lst(t_list **s1, t_list **s2);
void	ft_lstpush(t_list **alst, t_list *new);
void	ft_striter(char *s, void (*f)(char *));
void	*ft_memset(void *b, int c, size_t len);
void	ft_putdouble(double d, unsigned int p);
void	*ft_memchr(const void *str, int c, size_t n);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	ft_sort_lst(t_list *list, int (*ft_test_elem)(t_list *e1, t_list *e2));

long	ft_labs(long l);
long	ft_powl(long i, long p);

float	ft_fabs(float f);

double	ft_dabs(double d);

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);

#endif /* !LIBFT_H */
