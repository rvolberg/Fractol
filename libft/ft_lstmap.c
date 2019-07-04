/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:04:17 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/05 16:48:28 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** in this function we need to keep track of the begin of the list, to use a tmp
** that can change without creating issues and the new t_list after the
**f function is applie.
*/

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst_f;
	t_list	*ptr_begin_lst;
	t_list	*tmp;

	if (!f || !lst)
		return (NULL);
	lst_f = f(lst);
	if (!(lst_f = ft_lstnew(lst_f->content, lst_f->content_size)))
		return (NULL);
	lst = lst->next;
	ptr_begin_lst = lst_f;
	while (lst)
	{
		tmp = f(lst);
		if (!(tmp = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst_f->next = tmp;
		lst_f = lst_f->next;
		lst = lst->next;
	}
	return (ptr_begin_lst);
}
