/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:01:21 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:01:22 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_strs(char **tab, int n)
{
	int		i;
	int		ordered;

	ordered = FALSE;
	while (ordered == FALSE)
	{
		ordered = TRUE;
		i = 0;
		while (i < (n - 1))
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap_ptr((void **)&(tab[i]), (void **)&(tab[i + 1]));
				ordered = FALSE;
			}
			i++;
		}
	}
	return (tab);
}
