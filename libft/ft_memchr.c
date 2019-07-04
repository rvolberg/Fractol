/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:00:32 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/24 14:30:35 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** we don't need a dest string, we simply create a pointer unsigned char*
** to src and we return that pointer.
** we check nth number of time (as asked)
** we check the pointer with a unsigned char  - the c -(as asked)
** if different we move forward the pointer
*/

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	i;

	i = (unsigned char)c;
	ptr_s = (unsigned char*)s;
	while (n != '\0')
	{
		if (*ptr_s != i)
			ptr_s++;
		else
			return (ptr_s);
		n--;
	}
	return (NULL);
}
