/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 12:15:33 by gleger            #+#    #+#             */
/*   Updated: 2014/03/12 23:14:09 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __P4_H__
# define __P4_H__

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <termcap.h>
# include <termios.h>
# include <time.h>
# include <stdio.h>

# define	BUFF_SIZE 1

# define	P4_ERROR "\033[0;31m#Error\033[0;37m"
# define	P4_WARNING "\033[0;33;m#Warning\033[0;37m"
# define	P4_USAGE "\033[0;31mUsage\033[0;37m"
# define	P4_RULE " ./puissance4 nb_lines, nb_columns"
# define	P4_SIZE " The board must be at least 6 lines and 7 columns big."
# define	P4_COORDS " Lines and columns must be numbers."
# define	COL_FULL "Can't you see column is full\n...dumbass !"
# define	OVER_COL \
			"Check numbers over board and\nyou'll see how stupid you are."
# define	COL_STR "POSITIVE NUMBERS meatbag !!"

/*
** Type - Board value -> Print value
** Empty case - 0 -> Underscore
** Player 1 - 1 -> Red
** Player 2 - 2 -> Yellow
*/

typedef struct s_gboard		t_gboard;
typedef struct s_axe		t_axe;

struct						s_gboard
{
	int		nb_lines;
	int		nb_columns;
	int		**board;
	int		ia_id;
	char	*error;
};

struct						s_axe
{
	int		x;
	int		y;
};

size_t			ft_strlen(const char *str);

t_gboard		*init_game(void);

void			ft_putendl_fd(const char *str, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putchar_fd(const char c, int fd);
void			ft_putendl(const char *str);
void			print_board(t_gboard *grid);
void			print_index(t_gboard *grid, int *bloop, int *bindex);
void			bzero_board(t_gboard *grid);
void			ft_putstr(const char *str);
void			ft_puterr(const char *str);
void			ft_putchar(const char c);
void			ft_putnbr(int number);
void			board_error(t_gboard *grid);

char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strcpy(char *str, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strdup(const char *s1);

int				ft_good_check_l_c(int x, int y, t_gboard *p4, int cl);
int				ft_verif(t_gboard *p4, int player, int check, int ok);
int				check_size(char *line, char *col, t_gboard *board);
int				ft_check_three(int broad, int player, int check);
int				check_three(t_gboard *p4, int player, int ok);
int				check_right(t_gboard *p4, int player, int nb);
int				check_left(t_gboard *p4, int player, int nb);
int				check_double_empty(t_gboard *p4, int player);
int				check_double_diag(t_gboard *p4, int player);
int				player(t_gboard *p4, char *cl, int player);
int				ft_ia(t_gboard *p4, char *cl, int player);
int				ft_play(t_gboard *p4, int y, int player);
int				check_diag(t_gboard *p4, int player);
int				check_win(t_gboard *p4, int player);
int				check_args(char *line, char *col);
int				memset_board(t_gboard *grid);
int				ft_atoi(const char *src);
int				ft_isdigit(int number);
int				ft_player(void);

#endif		/* !__P4_H__ */
