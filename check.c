/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 07:30:44 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/09 14:21:13 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

int		ft_check_three(int broad, int player, int check)
{
	if (broad == 0)
		return (--check);
	else if (broad != player)
		return (++check);
	return ((check - 50));
}

int		ft_good_check_l_c(int x, int y, t_gboard *p4, int cl)
{
	if (cl == 1)
		return (y + 1);
	if ((x + 1) == p4->nb_lines)
	{
		if (p4->board[x][y] == 0)
			return (y + 1);
		else if (p4->board[x][y + 1] == 0)
			return (y + 2);
		else if (p4->board[x][y + 2] == 0)
			return (y + 3);
		else if (p4->board[x][y + 3] == 0)
			return (y + 4);
	}
	else
	{
		if (p4->board[x][y] == 0 && p4->board[x + 1][y])
			return (y + 1);
		else if (p4->board[x][y + 1] == 0 && p4->board[x + 1][y + 1])
			return (y + 2);
		else if (p4->board[x][y + 2] == 0 && p4->board[x + 1][y + 2])
			return (y + 3);
		else if (p4->board[x][y + 3] == 0 && p4->board[x + 1][y + 3])
			return (y + 4);
	}
	return (0);
}

int		ft_empty(int check, t_gboard *p4, t_axe p)
{
	if (check == -1 && p4->board[p.x][p.y + 1] && p4->board[p.x][p.y + 3])
	{
		if ((p.x + 1) == p4->nb_lines)
			return (p.y + 3);
		else if (p4->board[p.x + 1][p.y] && p4->board[p.x + 1][p.y + 2]
			&& p4->board[p.x + 1][p.y + 4])
			return (p.y + 3);
	}
	return (0);
}

int		check_double_empty(t_gboard *p4, int player)
{
	int		check;
	t_axe	p;

	p.x = -1;
	while (++p.x != p4->nb_lines)
	{
		p.y = -1;
		while (++p.y != (p4->nb_columns - 4))
		{
			check = 0;
			check = ft_check_three(p4->board[p.x][p.y], player, check);
			check = ft_check_three(p4->board[p.x][p.y + 1], player, check);
			check = ft_check_three(p4->board[p.x][p.y + 2], player, check);
			check = ft_check_three(p4->board[p.x][p.y + 3], player, check);
			check = ft_check_three(p4->board[p.x][p.y + 4], player, check);
			if ((check = ft_empty(check, p4, p)))
				return (check);
		}
	}
	return (0);
}
