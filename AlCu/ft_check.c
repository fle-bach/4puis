/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:42:52 by gleger            #+#    #+#             */
/*   Updated: 2014/03/08 21:37:13 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

int				ft_isdigit(int number)
{
	if (number >= 48 && number <= 57)
		return (1);
	else
		return (0);
}

int				check_args(char *line, char *col)
{
	int		loop;
	int		check_int;

	loop = -1;
	check_int = 0;
	while (++loop < (int)ft_strlen(line) && check_int != -1)
	{
		if (ft_isdigit(line[loop]) == 0)
			check_int = -1;
	}
	loop = -1;
	while (++loop < (int)ft_strlen(col) && check_int != -1)
	{
		if (ft_isdigit(col[loop]) == 0)
			check_int = -1;
	}
	return (check_int);
}

int				check_size(char *line, char *col, t_gboard *board)
{
	int		check_int;

	if ((check_int = check_args(line, col)) == -1)
	{
		ft_puterr(P4_ERROR);
		ft_puterr(P4_COORDS);
		ft_puterr("\n");
		return (-1);
	}
	else
	{
		board->nb_columns = ft_atoi(col);
		board->nb_lines = ft_atoi(line);
		if (board->nb_lines < 6 || board->nb_columns < 7)
		{
			ft_puterr(P4_ERROR);
			ft_puterr(P4_SIZE);
			ft_puterr("\n");
			return (-1);
		}
	}
	return (0);
}
