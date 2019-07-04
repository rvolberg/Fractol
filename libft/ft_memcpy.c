/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:03:54 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/24 13:44:36 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *)src;
	s2 = (char *)dest;
	i = 0;
	if (n == 0)
		return (s2);
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
