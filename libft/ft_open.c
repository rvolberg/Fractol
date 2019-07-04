/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:12:48 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/25 10:22:17 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_open(int argc, char **argv)
{
	int		fd;

	fd = 0;
	fd = open(argv[argc], O_RDONLY);
	if (fd < 0)
		ft_putendl_fd("open() failed", 2);
	return (fd);
}
