/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:02:02 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/23 16:24:27 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** in this function we use unsigned char because we move bytes by
** bytes, if int was used, we would move int by int
** we cast 'c' in unsigned char becaue its in the man.
** one bytes = 1 octet = 8 bits. one int = 2 octets.
** NB : pre incrementation is used (++i)
** ex :
** int j = i++; // i will contain i_old + 1, j will contain the i_old.
** Vs:
**int j = ++i; // i and j will both contain i_old + 1.
*/

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	unsigned char		*s2;
	unsigned char		j;

	i = 0;
	s1 = src;
	s2 = dest;
	j = (unsigned char)c;
	while (i < n)
	{
		s2[i] = s1[i];
		if (s2[i] == j)
		{
			s2 = &s2[++i];
			return (s2);
		}
		i++;
	}
	return (NULL);
}
