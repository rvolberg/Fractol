/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:02:58 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/02 17:26:11 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	start_cpy;
	char			*dest;
	int				j;

	j = 0;
	start_cpy = start;
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
		return (dest);
	}
	return (dest);
}
