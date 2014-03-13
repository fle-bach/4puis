/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:23:38 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/13 23:11:15 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:03:18 by gleger            #+#    #+#             */
/*   Updated: 2014/03/13 22:23:27 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

void			show_usage(void)
{
	ft_puterr(P4_USAGE);
	ft_puterr(P4_RULE);
	ft_puterr("\n");
}

int				check_poss(t_gboard *p4)
{
	int			y;
	int			check;

	check = 0;
	y = 0;
	while (y != p4->nb_columns)
	{
		if (p4->board[0][y] == 0)
			check++;
		y++;
	}
	if (check == 0)
		ft_putendl("It's a draw.");
	return (check);
}

void			ft_p4(t_gboard *p4, char *cl)
{
	int			win;
	int			nb_player;

	srand(time(NULL));
	p4->ia_id = rand() % 2 + 1;
	p4->ia_id = 2;
	nb_player = 1;
	win = 0;
	bzero_board(p4);
//	seg fault - boucle
	print_board(p4);
	while (win == 0 && check_poss(p4))
	{
		if (p4->ia_id != nb_player)
			win = ft_ia(p4, cl, nb_player);
		else
			win = ft_ia(p4, cl, nb_player);
		if (nb_player == 1)
			nb_player++;
		else
			nb_player--;
	}
}

int				main(int argc, char **argv)
{
	t_gboard	*p4;
	char		*cl;

	tgetent(NULL, NULL);
	if ((cl = tgetstr("cl", NULL)) == NULL)
		return (-1);
	ft_putstr(cl);
	if ((p4 = init_game()) == NULL)
		return (-1);
	if (argc != 3)
	{
		show_usage();
		return (-1);
	}
	else
	{
		if (check_size(argv[1], argv[2], p4) == -1)
			return (-1);
		ft_p4(p4, cl);
	}
	return (0);
}
