/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:17:18 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:17:20 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			n = 1;
			while ((s1[i + n] == s2[n]) && (s1[i + n] != '\0'))
				n++;
			if (s2[n] == '\0')
				return ((char *)&(s1[i]));
		}
		i++;
	}
	return (NULL);
}
