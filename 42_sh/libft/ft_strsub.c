/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:17:31 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:17:32 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	res = NULL;
	if (s)
	{
		i = 0;
		res = (char *)malloc((len + 1) * sizeof(char));
		if (res)
		{
			while (i < len)
			{
				res[i] = s[start + i];
				i++;
			}
			res[i] = '\0';
		}
	}
	return (res);
}
