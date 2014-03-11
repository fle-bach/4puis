/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 04:48:00 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/10 22:25:20 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

int		ft_lines_columns(t_gboard *p4, int player, t_axe p, int cl)
{
	int		check;

	check = 0;
	if (cl == 0)
	{
		check = ft_check_three(p4->board[p.x][p.y], player, check);
		check = ft_check_three(p4->board[p.x][p.y + 1], player, check);
		check = ft_check_three(p4->board[p.x][p.y + 2], player, check);
		check = ft_check_three(p4->board[p.x][p.y + 3], player, check);
	}
	else
	{
		if (p.x > 2)
		{
			check = ft_check_three(p4->board[p.x][p.y], player, check);
			check = ft_check_three(p4->board[p.x - 1][p.y], player, check);
			check = ft_check_three(p4->board[p.x - 2][p.y], player, check);
			check = ft_check_three(p4->board[p.x - 3][p.y], player, check);
		}
	}
	return (check);
}

int		ft_three(t_gboard *p4, int player, t_axe p)
{
	int		check;

	if (p.y < (p4->nb_columns - 3))
	{
		check = ft_lines_columns(p4, player, p, 0);
		if (check == 2)
			return (ft_good_check_l_c(p.x, p.y, p4, 0));
	}
	check = ft_lines_columns(p4, player, p, 1);
	if (check == 2)
		return (ft_good_check_l_c(p.x, p.y, p4, 1));
	return (0);
}

int		ft_double(t_gboard *p4, t_axe p, int check)
{
	if (check == 0 && p4->board[p.x][p.y] == 0 && p4->board[p.x][p.y + 3] == 0)
	{
		if ((p.x + 1) == p4->nb_lines && (p.y - 1) == -1
			&& p4->board[p.x][p.y + 4] == 0)
			return (p.y + 4);
		else if ((p.x + 1) == p4->nb_lines && (p.y + 4) == p4->nb_columns
			&& p4->board[p.x][p.y - 1] == 0)
			return (p.y + 1);
		else if ((p.x + 1) == p4->nb_lines && (p.y + 4) != p4->nb_columns
			&& (p.y - 1) != -1 && p4->board[p.x][p.y - 1] == 0)
			return (p.y + 1);
		else if ((p.x + 1) == p4->nb_lines && (p.y + 4) != p4->nb_columns
			&& (p.y - 1) != -1 && p4->board[p.x][p.y + 4] == 0)
			return (p.y + 4);
		else if ((p.x + 1) != p4->nb_lines && (p.y - 1) == -1
			&& (p.y + 4) != p4->nb_columns && (p.y - 1) != -1
			&& p4->board[p.x + 1][p.y + 3] && p4->board[p.x + 1][p.y]
			&& p4->board[p.x + 1][p.y + 4] && p4->board[p.x][p.y + 4] == 0)
			return (p.y + 4);
		else if ((p.x + 1) != p4->nb_lines && (p.y + 4) == p4->nb_columns
			&& (p.y + 4) != p4->nb_columns && (p.y - 1) != -1
			&& p4->board[p.x + 1][p.y + 3] && p4->board[p.x + 1][p.y]
			&& p4->board[p.x + 1][p.y - 1] && p4->board[p.x][p.y - 1] == 0)
			return (p.y + 1);
		else if ((p.x + 1) != p4->nb_lines
			&& (p.y + 4) != p4->nb_columns && (p.y - 1) != -1
			&& p4->board[p.x + 1][p.y + 3] && p4->board[p.x + 1][p.y]
			&& p4->board[p.x + 1][p.y + 4] && p4->board[p.x][p.y + 4] == 0)
			return (p.y + 4);
		else if ((p.x + 1) != p4->nb_lines
			&& (p.y + 4) != p4->nb_columns && (p.y - 1) != -1
			&& p4->board[p.x + 1][p.y + 3] && p4->board[p.x + 1][p.y]
			&& p4->board[p.x + 1][p.y - 1] && p4->board[p.x][p.y - 1] == 0)
			return (p.y + 1);
	}
	return (0);
}


int		check_double_triple(t_gboard *p4, int player, int dt)
{
	int		check;
	t_axe	p;

	p.x = -1;
	while (++p.x != p4->nb_lines)
	{
		p.y = -1;
		while (++p.y != p4->nb_columns)
		{
			if (dt == 0)
			{
				if ((check = ft_three(p4, player, p)))
					return (check);
			}
			else if (p.y < (p4->nb_columns - 3))
			{
				check = ft_lines_columns(p4, player, p, 0);
				if ((check = ft_double(p4, p, check)))
					return (check);
			}
		}
	}
	return (0);
}

int		check_three(t_gboard *p4, int player, int ok)
{
	int		check;

	check = check_double_triple(p4, player, 0);
	if (check == 0 && ok == 1)
		check = check_double_triple(p4, player, 1);
	return (check);
}
