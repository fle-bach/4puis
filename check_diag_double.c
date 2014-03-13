/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diag_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:28:28 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/13 20:40:05 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

int		check_good_diag1_double(t_gboard *p4, int x, int y)
{
	if (p4->board[x][y] == 0 && p4->board[x - 3][y + 3] == 0)
	{
		if ((y == (p4->nb_columns - 4) && (x + 1) == p4->nb_lines)
			|| (y == 0 && x == 3))
			return (0);
		else if (((x + 1) == p4->nb_lines || y == 0)
			&& p4->board[x - 2][y + 3] && p4->board[x - 4][y + 4] == 0
			&& p4->board[x - 3][y + 4])
			return (y + 4);
		else if ((x + 1) != p4->nb_lines && y != 0
			&& p4->board[x + 1][y] && p4->board[x - 2][y - 3])
		{
			if ((x == (p4->nb_lines - 4) || y == (p4->nb_columns - 4))
				&& p4->board[x + 1][y - 1] == 0)
			{
				if ((x + 2) == p4->nb_lines)
					return (y + 1);
				else if (p4->board[x + 2][y - 1])
					return (y + 1);
			}
			else if ((x != (p4->nb_lines - 4) && y != (p4->nb_columns - 4))
				&& ((p4->board[x + 2][y - 1] && p4->board[x + 1][y - 1] == 0)
					|| (p4->board[x - 3][y + 4]
						&& p4->board[x - 4][y + 4] == 0)))
			{
				if (p4->board[x + 2][y - 1] && p4->board[x + 1][y - 1] == 0)
					return (y + 1);
				else
					return (y - 2);
			}
		}
	}
	else if (p4->board[x][y] == 0 && p4->board[x - 2][y + 2] == 0)
	{
		if (p4->board[x - 1][y + 2])
			return (y + 3);
		return (0);
	}
	return (0);
}

int		check_good_diag_double(t_gboard *p4, int x, int y)
{
	if (p4->board[x][y] == 0 && p4->board[x - 3][y - 3] == 0)
	{
		if ((y == 3 && (x + 1) == p4->nb_lines)
			|| (y == (p4->nb_columns - 1) && x == 3))
			return (0);
		else if (((x + 1) == p4->nb_lines || y == (p4->nb_columns - 1))
			&& p4->board[x - 2][y - 3] && p4->board[x - 4][y - 4] == 0
			&& p4->board[x - 3][y - 4])
			return (y - 2);
		else if ((x + 1) != p4->nb_lines && y != (p4->nb_columns - 1)
			&& p4->board[x + 1][y] && p4->board[x - 2][y - 3])
		{
			if ((x == 3 || y == 3) && p4->board[x + 1][y + 1] == 0)
			{
				if ((x + 1) == p4->nb_lines)
					return (y + 1);
				else if (p4->board[x + 2][y + 1])
					return (y + 1);
			}
			else if (x != 3 && y != 3 && ((p4->board[x + 1][y + 1] == 0)
				|| (p4->board[x - 3][y - 4] && p4->board[x - 4][y - 4] == 0)))
			{
				if (p4->board[x + 1][y + 1] == 0)
				{
					if ((x + 2) == p4->nb_lines)
						return (y + 1);
					else if (p4->board[x + 2][y + 1])
						return (y + 1);
				}
				else
					return (y - 2);
			}
		}
	}
	else if (p4->board[x][y] == 0 && p4->board[x - 2][y - 2] == 0)
	{
		if (p4->board[x - 1][y - 2])
			return (y - 1);
		return (0);
	}
	return (0);
}

int		ft_double_left_bis(t_gboard *p4, int play, int check)
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
			if (check == 0)
			{
				if ((check = check_good_diag_double(p4, x_bis, p.y)))
					return (check);
			}
		}
	}
	return (0);
}

int		ft_double_left(t_gboard *p4, int play, int check)
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
			if (check == 0)
			{
				if ((check = check_good_diag_double(p4, p.x, y_bis)))
					return (check);
			}
		}
	}
	return (ft_double_left_bis(p4, play, check));
}

int		ft_double_right_bis(t_gboard *p4, int play, int check)
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
			if (check == 0)
			{
				if ((check = check_good_diag1_double(p4, x_bis, p.y)))
					return (check);
			}
		}
	}
	return (0);
}

int		ft_double_right(t_gboard *p4, int play, int check)
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
			if (check == 0)
			{
				if ((check = check_good_diag1_double(p4, p.x, y_bis)))
					return (check);
			}
		}
	}
	return (ft_double_right_bis(p4, play, check));
}

int		check_double_diag(t_gboard *p4, int player)
{
	int		check;

	check = 0;
	if ((check = ft_double_left(p4, player, check))
		|| (check = ft_double_right(p4, player, check)))
		return (check);
	return (0);
}
