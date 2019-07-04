/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:49:57 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/24 14:58:10 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** memcpy is use to compare binary bytes by bytes (bytes = series of 8 bits)
** that are in a buffer (temporary zone) for Nth bytes
*/

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	i = 0;
	ptr1 = (const unsigned char*)s1;
	ptr2 = (const unsigned char*)s2;
	while (n != 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		n--;
	}
	return (0);
}
