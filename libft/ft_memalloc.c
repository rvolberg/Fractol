/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:19:00 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/02 15:43:46 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
