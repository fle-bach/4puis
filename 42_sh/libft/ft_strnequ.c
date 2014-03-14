/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:05:57 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:05:59 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		res;
	size_t	i;

	res = 0;
	if (s1 && s2)
	{
		i = 0;
		while (s1[i] != '\0' && i < n)
		{
			if (s1[i] != s2[i])
				return (res);
			i++;
		}
		res = (i == n || s2[i] == '\0') ? 1 : 0;
	}
	return (res);
}
