/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:04:18 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/24 17:45:43 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return the appropriate size for the 2 strings, or if the given
** buffer ('size') is too small, give size of src + buffer back
** (buffer is the size of char to write in dest)
** only gives back the disponible space
** only concat if enougth space
*/

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size <= dest_len || !dest || !src || !size)
	{
		return (src_len + size);
	}
	while (size - 1 > (dest_len + i) && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
