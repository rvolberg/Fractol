/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:13:16 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/02 15:14:53 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_char(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

static int		ft_check_nega_or_posi(const char *str, int i)
{
	if (str[i] == '-' && str[i + 1] != '-' && str[i + 1] != '+')
	{
		i++;
		return (-1);
	}
	else if (str[i] == '+' && str[i + 1] != '-' && str[i + 1] != '+')
	{
		i++;
		return (1);
	}
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	long		ret;
	int			i;
	int			nop;

	ret = 0;
	i = ft_check_char(str);
	nop = ft_check_nega_or_posi(str, i);
	if (nop != 0)
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		ret = ret * 10;
		ret = ret + (str[i] - 48);
		i++;
	}
	if (nop != 0)
		ret = ret * nop;
	return (ret);
}
