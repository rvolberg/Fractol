/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:41:29 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/05 17:26:52 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char			*dest;
	size_t			j;
	size_t			len;
	size_t			end;

	dest = NULL;
	len = 0;
	end = 0;
	j = 0;
	if (s)
	{
		len = ft_strlen(s);
		end = (len - 1);
		while (s[j] == ',' || s[j] == '\t' || s[j] == ' '
				|| s[j] == '\n')
			j++;
		while (s[end] == ',' || s[end] == '\t' || s[end] == ' '
				|| s[end] == '\n')
			end--;
		if ((end + 1) < j)
			end = j;
		len = (end + 1) - j;
		dest = ft_strsub(s, j, len);
	}
	return (dest);
}
