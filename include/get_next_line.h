/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:56:45 by rvolberg          #+#    #+#             */
/*   Updated: 2018/02/18 11:18:48 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 29

typedef struct		s_struct
{
	char			*tmp;
	int				fd;
	struct s_struct	*next;
}					t_stock;

int					get_next_line(const int fd, char **line);
#endif
