/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:40:33 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/17 12:35:33 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_error(char *arg)
{
	write(2, arg, ft_strlen(arg));
	write(2, ": commande not found\n", 21);
}

int		ft_exit(char *line)
{
	if (ft_strcmp(line, "exit") == 0)
		exit(0);
	else if (ft_strncmp(line, "exit", 4) == 0)
	{
		write(1, "error exit\n", 11);
		return (0);
	}
	return (1);
}

int		ft_error_arg(char *arg)
{
	int		count;

	count = 0;
	while (arg[count])
	{
		if (arg[count] == '=')
		{
			write(2, "no '=' in first argument please\n", 32);
			return (-1);
		}
		count++;
	}
	return (0);
}
