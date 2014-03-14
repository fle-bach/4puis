/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:02:53 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:02:54 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	i;
	size_t	n;

	i = ft_strlen(str);
	cpy = (char *)malloc((i + 1) * sizeof(char));
	if (cpy)
	{
		n = 0;
		while (str[n] != '\0')
		{
			cpy[n] = str[n];
			n++;
		}
		cpy[n] = '\0';
	}
	return (cpy);
}
