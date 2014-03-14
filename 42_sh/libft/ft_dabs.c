/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:52:00 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:52:03 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_dabs(double d)
{
	d = (d < 0 ? -d : d);
	return (d);
}
