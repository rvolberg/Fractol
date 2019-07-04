/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:13:44 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/24 15:23:14 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** careful, here in the malloc it's - *dup - and not - dup -
** if it was dup, it would be the size of dup
** - *dup - gives the size of the value pointed by dup.
*/

char		*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	if (!(dup = (char*)malloc(sizeof(*dup) * (len + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
