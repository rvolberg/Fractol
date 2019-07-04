/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:38:33 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/02 12:09:20 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;
	char	*ptrh;
	int		i;

	i = 0;
	ptrh = (char *)haystack;
	len = ft_strlen(needle);
	if ((haystack[i] == '\0') && (needle[i] == '\0'))
		return ((char *)haystack);
	while (*ptrh)
	{
		if (ft_memcmp(ptrh, needle, len) == 0)
			return (ptrh);
		ptrh++;
	}
	return (NULL);
}
