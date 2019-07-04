/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 10:39:06 by rvolberg          #+#    #+#             */
/*   Updated: 2018/02/18 10:44:04 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** to check if correct
*/

char			*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*dest;
	int			j;

	j = 0;
	i = len;
	dest = NULL;
	if (s)
	{
		if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i > 0)
		{
			dest[j] = s[start];
			i--;
			j++;
			start++;
		}
		dest[j] = '\0';
		ft_strdel(&s);
		return (dest);
	}
	return (NULL);
}
