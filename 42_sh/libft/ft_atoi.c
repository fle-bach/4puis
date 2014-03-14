/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:51:29 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:51:31 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		res;

	res = 0;
	while (ft_isblank(*str) == 1)
		str = str + 1;
	i = ((*str == '+' || *str == '-') ? 1 : 0);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (str[0] == '-')
		res = res * (-1);
	return (res);
}
