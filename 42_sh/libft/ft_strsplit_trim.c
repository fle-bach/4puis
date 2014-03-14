/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_trim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 15:32:06 by fle-bach          #+#    #+#             */
/*   Updated: 2014/01/21 18:22:10 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_numwords_trim(const char *s)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != ' ' && s[i] != '\t')
			|| (s[i] != ' ' && s[i] != '\t'
				&& (s[i - 1] == ' ' || s[i - 1] == '\t')))
			res++;
		i++;
	}
	return (res);
}

size_t	ft_splits_trim(char **str, const char *s, size_t i)
{
	size_t	n;
	size_t	len;

	n = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] != ' ' && s[i] != '\0' && s[i] != '\t')
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			str[n] = ft_strsub(s, i - len, len);
			n++;
			len = 0;
		}
		else
			i++;
	}
	return (n);
}

char	**ft_strsplit_trim(char const *s)
{
	char	**str;
	size_t	n;

	str = NULL;
	if (s)
	{
		n = (ft_numwords_trim(s));
		str = (char **)malloc((n + 1) * sizeof(char *));
		if (str)
		{
			ft_splits_trim(str, s, 0);
			str[n] = NULL;
		}
	}
	return (str);
}
