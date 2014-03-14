/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:59:31 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:59:32 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putfloat(float f, unsigned int p)
{
	long	l;
	float	r;

	l = (long)f;
	r = 0.5;
	if ((ft_fabs(f - l) >= r) && (p == 0))
		l = ((l > 0) ? l + 1 : l - 1);
	ft_putlong(l);
	f = ft_fabs(f - l);
	if (f > 0 && p != 0)
	{
		write(1, ".", 1);
		while (p--)
		{
			f = f * 10;
			l = (long)f;
			l = l % 10;
			f = f - l;
			ft_putchar(l + 48);
		}
	}
}
