/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:58:57 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/31 12:32:36 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putdouble(double d, unsigned int p)
{
	long	l;
	float	r;

	l = (long)d;
	r = 0.5;
	if ((ft_dabs(d - l) >= r) && (p == 0))
		l = ((l > 0) ? l + 1 : l - 1);
	ft_putlong(l);
	d = ft_dabs(d - l);
	if (d > 0 && p > 0)
	{
		write(1, ".", 1);
		while (p--)
		{
			d = d * 10;
			l = (long)d;
			l = l % 10;
			d = d - l;
			if (p == 0)
				l = (d >= r ? (long)l + 1 : (long)l);
			ft_putchar(l + 48);
		}
	}
}
