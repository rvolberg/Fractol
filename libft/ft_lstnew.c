/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:56:57 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/05 20:49:39 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(list->content = (void*)malloc(sizeof(t_list))))
			return (NULL);
		list->content = ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
		list->next = list;
	}
	if (!(content))
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
