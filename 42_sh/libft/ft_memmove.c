/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:57:45 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:57:46 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cpysrc;

	i = 0;
	cpysrc = (char *)malloc(n * sizeof(char));
	ft_memcpy(cpysrc, src, n);
	ft_memcpy(dest, cpysrc, n);
	free (cpysrc);
	return (dest);
}
