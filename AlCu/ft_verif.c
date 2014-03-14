/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 20:38:34 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/12 23:20:49 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

int		ft_verif(t_gboard *p4, int play, int check, int ok)
{
	int			count;
	int			verif;
	static int	i = 0;

	if (i == 20)
	{
		i = 0;
		return (check + 1);
	}
	i++;
	count = p4->nb_lines - 1;
	if (p4->board[0][check])
		return (-1);
	while (p4->board[count][check])
		count--;
	ft_play(p4, check, play);
	if ((verif = check_three(p4, play, 0)) || (verif = check_diag(p4, play)))
	{
		p4->board[count][check] = 0;
		return (-1);
	}
	else if (ok == 1 && ((verif = check_three(p4, play, 1))
		|| (verif = check_double_empty(p4, play))
		|| (verif = check_double_diag(p4, play))))
	{
		p4->board[count][check] = 0;
		return (-1);
	}
	else
	{
		i = 0;
		p4->board[count][check] = 0;
		return (check + 1);
	}
}
