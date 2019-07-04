/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:19:55 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/24 13:49:36 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** memove is useful when src and dest are the same
** if memcpy was used there would be a lost of information
** here we also move byte by byte
** if dest is shorter or equal to src, simply memcpy
** else, we move pointer to pointer
** going backwards.
*/

void					*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*tmp_src;
	unsigned char		*tmp_dest;

	tmp_src = src;
	tmp_dest = dest;
	i = 0;
	if (tmp_dest <= tmp_src)
		return (ft_memcpy(dest, src, n));
	tmp_src = tmp_src + n;
	tmp_dest = tmp_dest + n;
	while (n != 0)
	{
		*--tmp_dest = *--tmp_src;
		n--;
	}
	return (dest);
}
