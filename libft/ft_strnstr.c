/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:48:14 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/05 18:02:06 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hs, const char *n, size_t len)
{
	size_t	len_n;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	len_n = ft_strlen(n);
	if ((n[j] == '\0') || ((hs[i] == '\0') && (n[j] == '\0')))
		return ((char *)hs);
	while (hs[i] != '\0' && i < len)
	{
		while (hs[i + j] == n[j] && (i + j) < len)
		{
			j++;
			if (j == len_n)
				return ((char *)&hs[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
