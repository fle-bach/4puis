/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:05:18 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:05:19 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (UCHAR *)s1;
	str2 = (UCHAR *)s2;
	while (i < n && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	if (i == n)
		res = 0;
	else
		res = (str1[i] - str2[i]);
	return (res);
}
