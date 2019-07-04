/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:42:20 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/02 16:55:23 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = NULL;
	if (s)
	{
		if (!(dest = (char*)malloc(sizeof(char) * ((ft_strlen(s) + 1)))))
			return (NULL);
		while (s[i] != '\0')
		{
			dest[i] = f(i, s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (dest);
}
