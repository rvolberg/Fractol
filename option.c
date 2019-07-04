/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:58:40 by rvolberg          #+#    #+#             */
/*   Updated: 2018/09/29 09:45:57 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

/*
** option reset
*/

void		ft_reset(t_env *env)
{
	t_fract		*fract;
	t_op		*graph;

	graph = (t_op*)env->data;
	fract = (t_fract*)env->fract;
	fract->i_max = 50;
	fract->min_x = -2.0;
	fract->min_y = -2.0;
	fract->max_x = 2.0;
	fract->max_y = 2.0;
	fract->scale_x = graph->i_len / (fract->max_x - fract->min_x);
	fract->scale_y = graph->i_hei / (fract->max_y - fract->min_y);
	fract->zr = 0;
	fract->zi = 0;
	fract->cr = 0;
	fract->ci = 0;
	ft_send_fractal(env);
}

/*
** changement de fractal
*/

void		ft_fractal_change(t_env *env)
{
	t_op	*graph;

	graph = (t_op*)env->data;
	if (env->fractal_pick == 0)
		env->fractal_pick = 1;
	else if (env->fractal_pick == 1)
		env->fractal_pick = 2;
	else if (env->fractal_pick == 2)
		env->fractal_pick = 0;
	ft_send_fractal(env);
}

/*
** rotation de julia
*/

int			ft_julia_rotation(int x, int y, t_env *env)
{
	t_fract		*fractal;
	t_op		*graph;

	graph = (t_op*)env->data;
	fractal = (t_fract*)env->fract;
	if (x >= 0 && y >= 0 && x <= graph->i_len && y <= graph->i_hei && \
		env->fractal_pick == 1 && env->j_pause == 0)
	{
		fractal->cr = fractal->min_x + x / fractal->scale_x;
		fractal->ci = fractal->max_y - y / fractal->scale_y;
		ft_send_fractal(env);
	}
	return (0);
}

/*
** fontion zoom & dezoom
** x_cpy et y_cpy sont les coordonnees pixels traduites sur l'axe x;y
** x_zoom et y_zoom = longeur total axe (ex: -2, 2 -> longeur = 4) * zoom
** et diviser par 2 pour la precision
*/

void		ft_zoom(int x, int y, t_env *env)
{
	t_fract		*fract;
	t_op		*graph;
	double		x_cpy;
	double		y_cpy;

	graph = (t_op*)env->data;
	fract = (t_fract*)env->fract;
	x_cpy = (double)x / fract->scale_x + fract->min_x;
	y_cpy = (double)y / fract->scale_y + fract->min_y;
	env->x_zoom = ((fract->max_x - fract->min_x) * env->zoom) / 2;
	env->y_zoom = ((fract->max_y - fract->min_y) * env->zoom) / 2;
	fract->min_x = x_cpy - env->x_zoom;
	fract->max_x = x_cpy + env->x_zoom;
	fract->min_y = y_cpy - env->y_zoom;
	fract->max_y = y_cpy + env->y_zoom;
	fract->scale_x = graph->i_len / (fract->max_x - fract->min_x);
	fract->scale_y = graph->i_hei / (fract->max_y - fract->min_y);
	ft_send_fractal(env);
}
