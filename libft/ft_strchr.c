/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:40:37 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/24 18:54:20 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*ptrs;
	char	f;

	f = (char)c;
	ptrs = (char *)s;
	while (*ptrs && *ptrs != f)
		ptrs++;
	if (*ptrs == f)
		return (ptrs);
	return (NULL);
}
