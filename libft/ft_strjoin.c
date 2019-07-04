/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:27:51 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/03 11:46:49 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (s1 && s2)
	{
		i = (ft_strlen(s1) + ft_strlen(s2));
		dest = ft_memalloc(i + 1);
		if (dest)
		{
			dest = ft_strcat(dest, s1);
			dest = ft_strcat(dest, s2);
			return (dest);
		}
	}
	return (dest);
}
