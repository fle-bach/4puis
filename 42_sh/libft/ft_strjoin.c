/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:03:32 by fle-bach          #+#    #+#             */
/*   Updated: 2014/02/19 17:37:05 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = NULL;
	if (s1 && s2)
	{
		res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
		if (res)
		{
			ft_strcpy(res, s1);
			ft_strcat(res, s2);
		}
	}
	return (res);
}
