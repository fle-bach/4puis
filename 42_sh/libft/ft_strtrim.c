/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:17:46 by fle-bach          #+#    #+#             */
/*   Updated: 2014/02/19 17:18:20 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_cpy(char *s, int i, int j)
{
	char	*cpy;
	int		count;

	count = 0;
	cpy = (char *)malloc(sizeof(char) * (j - i + 1));
	while (i != j)
	{
		cpy[count] = s[i];
		count++;
		i++;
	}
	cpy[count] = '\0';
	return (cpy);
}

char			*ft_strtrim(char const *s)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[j] != '\0')
		j++;
	j--;
	while ((s[j] == ' ' || s[j] == '\t') && j != -1)
		j--;
	if (j != -1)
		cpy = ft_cpy((char *)s, i, (j + 1));
	else
		cpy = ft_strdup("");
	free((char *)s);
	return (cpy);
}
