/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:56:13 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:56:16 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			new->content_size = content_size;
			new->content = (void *)malloc(content_size);
			if (new->content)
				ft_memcpy(new->content, content, content_size);
		}
		new->next = NULL;
	}
	return (new);
}
