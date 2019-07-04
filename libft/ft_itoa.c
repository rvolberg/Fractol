/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:45:32 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/05 21:24:04 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_dest_size(int n)
{
	unsigned int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char				*ft_fill_dest(unsigned int i, int nb, char *dest)
{
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		dest[i] = ((nb % 10) + 48);
		nb = nb / 10;
		i--;
	}
	return (dest);
}

char					*ft_itoa(int n)
{
	char				*dest;
	unsigned int		i;
	int					nb;

	nb = n;
	i = 0;
	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	i = ft_dest_size(n);
	if (!(dest = ft_strnew(i)))
		return (NULL);
	i = i - 1;
	dest = ft_fill_dest(i, nb, dest);
	return (dest);
}
