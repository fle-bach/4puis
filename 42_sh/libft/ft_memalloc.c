/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:56:36 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:56:37 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size)
	{
		ptr = (void *)malloc(size);
		if (ptr)
			return (ft_memset(ptr, 0, size));
	}
	return (NULL);
}
