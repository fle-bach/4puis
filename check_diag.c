/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:55:45 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/11 20:10:53 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

int		check_good_diag1(t_gboard *p4, int x, int y)
{
	while (p4->board[x][y] != 0)
	{
		x--;
		y++;
	}
	if ((x + 1) != p4->nb_lines && p4->board[x + 1][y])
		return (y + 1);
	else if ((x + 1) == p4->nb_lines)
		return (y + 1);
	return (0);
}

int		check_good_diag(t_gboard *p4, int x, int y)
{
	while (p4->board[x][y] != 0)
	{
		x--;
		y--;
	}
	if ((x + 1) != p4->nb_lines && p4->board[x + 1][y])
		return (y + 1);
	else if ((x + 1) == p4->nb_lines)
		return (y + 1);
	return (0);
}

int		ft_right_bis(t_gboard *p4, int play, int check)
{
	t_axe	p;
	int		x_bis;

	p.x = p4->nb_lines - 1;
	while (--p.x != 2)
	{
		x_bis = p.x + 1;
		p.y = p4->nb_columns;
		while (--p.y != 2 && --x_bis != 2)
		{
			check = 0;
			check = ft_check_three(p4->board[x_bis][p.y], play, check);
			check = ft_check_three(p4->board[x_bis - 1][p.y - 1], play, check);
			check = ft_check_three(p4->board[x_bis - 2][p.y - 2], play, check);
			check = ft_check_three(p4->board[x_bis - 3][p.y - 3], play, check);
			if (check == 2)
				return (check_good_diag(p4, x_bis, p.y));
		}
	}
	return (0);
}

int		ft_right(t_gboard *p4, int play, int check)
{
	t_axe	p;
	int		y_bis;

	p.y = p4->nb_columns;
	while (--p.y != 2)
	{
		y_bis = p.y + 1;
		p.x = p4->nb_lines;
		while (--p.x != 2 && --y_bis != 2)
		{
			check = 0;
			check = ft_check_three(p4->board[p.x][y_bis], play, check);
			check = ft_check_three(p4->board[p.x - 1][y_bis - 1], play, check);
			check = ft_check_three(p4->board[p.x - 2][y_bis - 2], play, check);
			check = ft_check_three(p4->board[p.x - 3][y_bis - 3], play, check);
			if (check == 2)
				return (check_good_diag(p4, p.x, y_bis));
		}
	}
	return (ft_right_bis(p4, play, check));
}

int		ft_left_bis(t_gboard *p4, int play, int check)
{
	t_axe	p;
	int		x_bis;

	p.x = p4->nb_lines - 1;
	while (--p.x != 2)
	{
		x_bis = p.x + 1;
		p.y = -1;
		while (++p.y != (p4->nb_columns - 3) && --x_bis != 2)
		{
			check = 0;
			check = ft_check_three(p4->board[x_bis][p.y], play, check);
			check = ft_check_three(p4->board[x_bis - 1][p.y + 1], play, check);
			check = ft_check_three(p4->board[x_bis - 2][p.y + 2], play, check);
			check = ft_check_three(p4->board[x_bis - 3][p.y + 3], play, check);
			if (check == 2)
				return (check_good_diag1(p4, x_bis, p.y));
		}
	}
	return (0);
}

int		ft_left(t_gboard *p4, int play, int check)
{
	t_axe	p;
	int		y_bis;

	p.y = -1;
	while (++p.y != (p4->nb_columns - 3))
	{
		y_bis = p.y - 1;
		p.x = p4->nb_lines;
		while (--p.x != 2 && ++y_bis != (p4->nb_columns - 3))
		{
			check = 0;
			check = ft_check_three(p4->board[p.x][y_bis], play, check);
			check = ft_check_three(p4->board[p.x - 1][y_bis + 1], play, check);
			check = ft_check_three(p4->board[p.x - 2][y_bis + 2], play, check);
			check = ft_check_three(p4->board[p.x - 3][y_bis + 3], play, check);
			if (check == 2)
				return (check_good_diag1(p4, p.x, y_bis));
		}
	}
	return (ft_left_bis(p4, play, check));
}

int		check_diag(t_gboard *p4, int player)
{
	int		check;

	check = 0;
	if ((check = ft_right(p4, player, check))
		|| (check = ft_left(p4, player, check)))
		return (check);
	return (0);
}
