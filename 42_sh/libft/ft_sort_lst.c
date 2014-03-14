/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:01:05 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:01:09 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_lst(t_list *list, int (*ft_test_elem)(t_list *e1, t_list *e2))
{
	t_list	*ptr;
	int		ordered;

	ptr = list;
	ordered = FALSE;
	while (ordered == FALSE)
	{
		ordered = TRUE;
		ptr = list;
		while (ptr)
		{
			if (ft_test_elem(ptr, ptr->next) == 1)
			{
				ft_swap_lst(&ptr, &(ptr->next));
				ordered = FALSE;
			}
			ptr = ptr->next;
		}
	}
}
