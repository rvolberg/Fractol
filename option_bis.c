/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 07:23:01 by rvolberg          #+#    #+#             */
/*   Updated: 2018/09/25 12:27:28 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

/*
** fonction qui augmente et diminue le nombre d'iteration manuellement
*/

void		ft_iter_option(t_env *env, int key)
{
	t_fract		*fract;
	t_op		*graph;

	graph = (t_op*)env->data;
	fract = (t_fract*)env->fract;
	if (key == 24)
		fract->i_max += 10;
	if ((key == 27) && (fract->i_max > 50))
		fract->i_max -= 10;
	ft_send_fractal(env);
}

/*
** ft option couleur
*/

void		ft_color(t_env *env)
{
	t_col		*col;
	t_op		*graph;

	graph = (t_op*)env->data;
	col = (t_col*)env->color;
	if (col->palette == 0)
	{
		col->blue = 50;
		col->green = 50;
		col->red = 50;
		col->palette++;
	}
	else if (col->palette == 1)
	{
		col->blue = 200;
		col->green = 150;
		col->red = 75;
		col->palette++;
	}
	else if (col->palette >= 2)
		col = ft_color_bis(col);
	ft_send_fractal(env);
}

/*
** color suite
*/

t_col		*ft_color_bis(t_col *col)
{
	if (col->palette == 2)
	{
		col->blue = 255;
		col->green = 200;
		col->red = 0;
		col->palette++;
	}
	else if (col->palette == 3)
	{
		col->blue = 65;
		col->green = 30;
		col->red = 48;
		col->palette++;
	}
	else if (col->palette == 4)
	{
		col->blue = 250;
		col->green = 250;
		col->red = 250;
		col->palette = 0;
	}
	return (col);
}
