/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:06:48 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/02 16:44:22 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = NULL;
	if (s)
	{
		if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i] != '\0')
		{
			dest[i] = f(s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (dest);
}
