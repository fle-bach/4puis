/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:39:40 by fle-bach          #+#    #+#             */
/*   Updated: 2014/01/12 22:09:20 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_realloc(char **s, char *str, int i)
{
	int	count;
	char	**cmp;

	if (i == 0)
	{
		cmp = (char **)malloc(sizeof(char *) * 2);
		cmp[0] = ft_strdup(str);
		cmp[1] = NULL;
		return (cmp);
	}
	count = 0;
	cmp = (char **)malloc(sizeof(char *) * (i + 2));
	while (s[count])
	{
		cmp[count] = ft_strdup(s[count]);
		count++;
	}
	cmp[count] = ft_strdup(str);
	cmp[count + 1] = NULL;
	ft_free_double_tab(&s);
	return (cmp);
}
