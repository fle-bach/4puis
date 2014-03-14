/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:06:18 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:06:19 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*res;

	res = NULL;
	if (s1 && s2)
	{
		res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
		if (res)
		{
			ft_strcpy(res, s1);
			ft_strncat(res, s2, n);
		}
	}
	return (res);
}
