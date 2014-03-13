/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 00:15:56 by gleger            #+#    #+#             */
/*   Updated: 2014/03/13 23:19:04 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

int			ia_play(t_gboard *grid, int play_id)
{
	(void)grid;
	(void)play_id;
	return (0);
}

int			ft_check_ia_win(t_gboard *p4, int player, int ok)
{
	int		check;

	if (player == 1)
	{
		if ((check = check_three(p4, player + 1, ok)) != 0
			|| (check = check_diag(p4, player + 1))
			|| (ok == 1 && (check = check_double_empty(p4, player + 1)))
			|| (ok == 1 && (check = check_double_diag(p4, player + 1))))
			return (check);
	}
	else
	{
		if ((check = check_three(p4, player - 1, ok)) != 0
			|| (check = check_diag(p4, player - 1))
			|| (ok == 1 && (check = check_double_empty(p4, player - 1)))
			|| (ok == 1 && (check = check_double_diag(p4, player - 1))))
			return (check);
	}
	return (0);
}

int			ft_check_ia(t_gboard *p4, int player)
{
	int		check;

	if ((check = ft_check_ia_win(p4, player, 0)))
		return (check);
	if ((check = check_three(p4, player, 0)))
		return (check);
	if ((check = check_diag(p4, player)))
		return (check);
	if ((check = ft_check_ia_win(p4, player, 1)))
	{
		if (ft_verif(p4, player, check, 0) != -1)
			return (check);
	}
	if ((check = check_three(p4, player, 1)))
		return (check);
	if ((check = check_double_empty(p4, player)))
		return (check);
	if ((check = check_double_diag(p4, player)))
		return (check);
	check = -1;
	while (check == -1)
	{
		check = (rand() % p4->nb_columns) + 1;
		check = ft_verif(p4, player, (check - 1), 1);
	}
	return (check);
}

int			ft_ia(t_gboard *p4, char *cl, int player)
{
	int		win;
	int		move;
	int		check;

	move = -1;
	while (move == -1)
	{
		ft_putstr(cl);
		move = ft_check_ia(p4, player);
		check = move;
		move = ft_play(p4, (move - 1), player);
		if (move != -1)
		{
			ft_putstr("move : ");
			ft_putnbr(check);
			ft_putchar('\n');
		}
	}
	print_board(p4);
	win = check_win(p4, player);
	if (win == 1)
	{
		ft_putendl("Mouwhahahaha you're nothing to me..");
		ft_putendl("    .... puny human !!!");
	}
	return (win);
}
