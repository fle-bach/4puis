/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:57:01 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:57:02 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (UCHAR *)str;
	while (n > i)
	{
		if (ptr[i] == (UCHAR)c)
			return (&(ptr[i]));
		i++;
	}
	return (NULL);
}
