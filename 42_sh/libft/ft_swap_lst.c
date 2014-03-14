/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:18:00 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:18:01 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_lst(t_list **s1, t_list **s2)
{
	t_list	tmp;
	size_t	size;

	size = sizeof(t_list) - sizeof(t_list *);
	ft_memcpy(&tmp, *s1, size);
	ft_memcpy(*s1, *s2, size);
	ft_memcpy(*s2, &tmp, size);
}
