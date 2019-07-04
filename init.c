/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:22:48 by rvolberg          #+#    #+#             */
/*   Updated: 2018/09/29 09:59:24 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

/*
** initialisation stucture graph
*/

t_op			*ft_init_struct_data(int *bbp, int *sl, int *end)
{
	t_op		*graph;

	graph = NULL;
	if (!(graph = (t_op*)malloc(sizeof(t_op))))
		return (NULL);
	graph->w_len = 1200;
	graph->w_hei = 1200;
	graph->i_len = 1200;
	graph->i_hei = 1200;
	graph->mlx = mlx_init();
	graph->win = mlx_new_window(graph->mlx, graph->w_len, graph->w_hei, "win");
	graph->img = mlx_new_image(graph->mlx, graph->i_len, graph->i_hei);
	graph->data = (unsigned int*)mlx_get_data_addr(graph->img, bbp, sl, end);
	return (graph);
}

/*
** initialisation environnement
*/

t_env			*ft_init_env(int fpick, int *bbp, int *sl, int *end)
{
	t_env		*env;
	t_col		*col;
	t_fract		*fm;
	t_op		*graph;

	env = NULL;
	col = ft_init_color();
	graph = ft_init_struct_data(bbp, sl, end);
	fm = ft_init_fractal(graph);
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->zoom = 0;
	env->color = (t_col*)col;
	env->fract = (t_fract*)fm;
	env->data = (t_op*)graph;
	env->fractal_pick = fpick;
	env->j_pause = 0;
	env->x_zoom = 0;
	env->y_zoom = 0;
	return (env);
}

/*
** ft qui initialise struc color_palette
*/

t_col			*ft_init_color(void)
{
	t_col		*col;

	col = NULL;
	if (!(col = (t_col*)malloc(sizeof(t_col))))
		return (NULL);
	col->blue = 250;
	col->green = 250;
	col->red = 250;
	col->palette = 0;
	col->next = col;
	return (col);
}

/*
** ft_init struct fractales
** scale = le nombre de pixels pour la distance entre deux points
** sur l'axe x:y
** cr = point ds l'axe X et ci = point ds l'axe Y
*/

t_fract			*ft_init_fractal(t_op *graph)
{
	t_fract		*fract;

	fract = NULL;
	if (!(fract = (t_fract*)malloc(sizeof(t_fract))))
		return (NULL);
	fract->i_max = 50;
	fract->i_esc = 0;
	fract->min_x = -2.0;
	fract->max_x = 2.0;
	fract->min_y = -2.0;
	fract->max_y = 2.0;
	fract->scale_x = graph->i_len / (fract->max_x - fract->min_x);
	fract->scale_y = graph->i_hei / (fract->max_y - fract->min_y);
	fract->zr = 0;
	fract->zi = 0;
	fract->cr = 0;
	fract->ci = 0;
	return (fract);
}
