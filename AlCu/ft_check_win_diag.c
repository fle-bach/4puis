/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_win_diag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 20:07:00 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/09 12:30:04 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

int			check_left_bis(t_gboard *p4, int player, int nb)
{
	int		x;
	int		y;
	int		y_bis;
	int		check;

	y = p4->nb_columns - 2;
	while (y != 2)
	{
		y_bis = y;
		x = p4->nb_lines - 1;
		check = 0;
		while (y_bis != -1 && x != -1)
		{
			if (p4->board[x][y_bis] == player)
				check++;
			else
				check = 0;
			if (check == nb)
				return (1);
			x--;
			y_bis--;
		}
		y--;
	}
	return (0);
}

int			check_left(t_gboard *p4, int player, int nb)
{
	int		x;
	int		y;
	int		x_bis;
	int		check;

	x = p4->nb_lines - 1;
	while (x != 2)
	{
		x_bis = x;
		y = p4->nb_columns - 1;
		check = 0;
		while (x_bis != -1 && y != -1)
		{
			if (p4->board[x_bis][y] == player)
				check++;
			else
				check = 0;
			if (check == nb)
				return (1);
			x_bis--;
			y--;
		}
		x--;
	}
	return (check_left_bis(p4, player, nb));
}

int			check_right_bis(t_gboard *p4, int player, int nb)
{
	int		x;
	int		y;
	int		y_bis;
	int		check;

	y = p4->nb_columns - 2;
	while (y != 2)
	{
		y_bis = y;
		x = 0;
		check = 0;
		while (y_bis != -1 && x != p4->nb_lines)
		{
			if (p4->board[x][y_bis] == player)
				check++;
			else
				check = 0;
			if (check == nb)
				return (1);
			x++;
			y_bis--;
		}
		y--;
	}
	return (0);
}

int			check_right(t_gboard *p4, int player, int nb)
{
	int		x;
	int		y;
	int		x_bis;
	int		check;

	x = 0;
	while (x != (p4->nb_lines - 3))
	{
		x_bis = x;
		y = p4->nb_columns - 1;
		check = 0;
		while (x_bis != p4->nb_lines && y != -1)
		{
			if (p4->board[x_bis][y] == player)
				check++;
			else
				check = 0;
			if (check == nb)
				return (1);
			x_bis++;
			y--;
		}
		x++;
	}
	return (check_right_bis(p4, player, nb));
}
