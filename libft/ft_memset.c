/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:14:17 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/13 15:00:45 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;
	char			*str;

	str = s;
	i = 0;
	while (i != n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
