/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:24:59 by gleger            #+#    #+#             */
/*   Updated: 2014/03/09 16:08:33 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

t_gboard		*init_game(void)
{
	t_gboard	*board;

	board = malloc(sizeof(t_gboard));
	if (board == NULL)
		return (NULL);
	board->error = NULL;
	return (board);
}

int				memset_board(t_gboard *grid)
{
	int			loop;

	loop = -1;
	grid->board = malloc(grid->nb_lines * sizeof(int *));
	if (grid->board == NULL)
		return (-1);
	while (++loop < grid->nb_lines)
	{
		grid->board[loop] = malloc(grid->nb_columns * sizeof(int));
		if (grid->board[loop] == NULL)
			return (-1);
	}
	return (0);
}

void			bzero_board(t_gboard *grid)
{
	int			loop;
	int			index;

	loop = -1;
	index = -1;
	memset_board(grid);
	while (++loop < grid->nb_lines)
	{
		while (++index < grid->nb_columns)
			grid->board[loop][index] = 0;
		index = -1;
	}
}

void			print_index(t_gboard *grid, int *bloop, int *bindex)
{
	int			index;

	index = -1;
	while (++index < grid->nb_columns)
	{
		ft_putchar(' ');
		ft_putnbr(index + 1);
		if (index < 9)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	*bloop += 1;
	*bindex -= 1;
}

void			print_board(t_gboard *grid)
{
	t_axe		loops;

	loops.x = -2;
	while (++loops.x < grid->nb_lines)
	{
		loops.y = -1;
		while (++loops.y < grid->nb_columns)
		{
			if (loops.x == -1)
				print_index(grid, &loops.x, &loops.y);
			else
			{
				ft_putstr("\033[1;34m|\033[0;37m");
				if (grid->board[loops.x][loops.y] == 0)
					ft_putstr("\033[1;34m_\033[0;37m");
				else if (grid->board[loops.x][loops.y] == 1)
					ft_putstr("\033[0;31mO\033[0;37m");
				else if (grid->board[loops.x][loops.y] == 2)
					ft_putstr("\033[0;33mO\033[0;37m");
				ft_putstr("\033[1;34m|\033[0;37m");
			}
		}
		ft_putchar('\n');
	}
	board_error(grid);
}
