/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:43:59 by rvolberg          #+#    #+#             */
/*   Updated: 2017/11/24 15:54:52 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (n != 0 && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
