/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:56:03 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:56:05 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmp;

	newlst = NULL;
	if (lst)
	{
		tmp = f(lst);
		newlst = ft_lstnew(tmp->content, tmp->content_size);
		newlst->next = ft_lstmap(lst->next, f);
	}
	return (newlst);
}
