/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:55:06 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:55:07 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_labs(long l)
{
	l = (l < 0 ? -l : l);
	return (l);
}