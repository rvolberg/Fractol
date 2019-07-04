/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:20:04 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/24 19:42:40 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** we start at the end here.
*/

char		*ft_strrchr(const char *s, int c)
{
	char	*ptrs;
	char	f;
	int		i;

	i = ft_strlen(s);
	f = (char)c;
	ptrs = NULL;
	while (i != 0 && s[i] != f)
		i--;
	if (s[i] == f)
		ptrs = (char *)&s[i];
	return (ptrs);
}
