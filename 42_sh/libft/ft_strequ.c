/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:03:04 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:03:05 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		res;
	size_t	i;

	res = 0;
	if (s1 && s2)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (res);
			i++;
		}
		res = (s2[i] != '\0') ? 0 : 1;
	}
	return (res);
}
