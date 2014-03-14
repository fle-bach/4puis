/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:04:46 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:04:48 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*res;
	unsigned int	i;

	res = NULL;
	if (s && f)
	{
		i = 0;
		res = (char *)malloc((ft_strlen(s)) * sizeof(char) + 1);
		if (res)
		{
			while (s[i] != '\0')
			{
				res[i] = f(s[i]);
				i++;
			}
			res[i] = '\0';
		}
	}
	return (res);
}
