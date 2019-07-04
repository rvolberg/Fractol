/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 10:59:20 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/02 15:51:05 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	len;

	len = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (len <= (size + 1))
	{
		str[len] = '\0';
		len++;
	}
	return (str);
}
