/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:54:07 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:54:09 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'|| c == '\r' || c == '\n'
		|| c == '\f')
		return (1);
	return (0);
}