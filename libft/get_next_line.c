/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:56:38 by rvolberg          #+#    #+#             */
/*   Updated: 2018/02/18 10:41:22 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** ft qui verifie le fd, cree struct et stock tmp et fd si non trouve
*/

static t_stock		*ft_struct(const int fd, t_list **list)
{
	t_stock			*data;
	t_list			*link;

	link = *list;
	while (link != NULL)
	{
		data = (t_stock*)link->content;
		if (data->fd == fd)
			return (data);
		link = link->next;
	}
	if (!(link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	link->next = NULL;
	if (!(data = (t_stock*)malloc(sizeof(t_stock))))
		return (NULL);
	data->tmp = ft_memalloc(1);
	data->fd = fd;
	data->next = data;
	link->content = (t_stock*)data;
	ft_lstadd(list, link);
	return (data);
}

/*
** ft qui check pour \n
*/

static int			ft_check(char **line, t_stock **data)
{
	size_t			c;
	size_t			len;
	char			*str;

	len = ft_strlen((*data)->tmp);
	str = ft_strdup((*data)->tmp);
	c = 0;
	if (str != NULL)
	{
		while (str[c] != '\0')
		{
			if (str[c] == '\n')
			{
				*line = ft_strsub(str, 0, c);
				c++;
				ft_strdel(&((*data)->tmp));
				(*data)->tmp = ft_strsub_free(str, c, len);
				return (1);
			}
			c++;
		}
	}
	ft_strdel(&str);
	return (0);
}

/*
** fonction qui lit et stock ds tmp et check
*/

static int			ft_read(t_stock **data, char **line, int i)
{
	char			*buffer;

	buffer = ft_strnew(BUFF_SIZE);
	while ((i = read((*data)->fd, buffer, BUFF_SIZE)) > 0)
	{
		(*data)->tmp = ft_strjoin_free((*data)->tmp, buffer);
		if ((ft_check(line, data)))
		{
			ft_strdel(&buffer);
			return (1);
		}
	}
	if (i < 0)
	{
		ft_strdel(&buffer);
		return (-1);
	}
	if (ft_strlen((*data)->tmp) > 0)
	{
		i = 1;
		*line = ft_strdup((*data)->tmp);
		ft_strclr((*data)->tmp);
	}
	ft_strdel(&buffer);
	return (i);
}

/*
** GNL
*/

int					get_next_line(const int fd, char **line)
{
	int				i;
	static t_list	*list = NULL;
	t_stock			*data;

	i = 0;
	if (!(data = ft_struct(fd, &list)))
		return (-1);
	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if ((ft_check(line, &data)))
	{
		return (1);
	}
	i = ft_read(&data, line, i);
	return (i);
}
