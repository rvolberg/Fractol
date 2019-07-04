/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:23:19 by rvolberg          #+#    #+#             */
/*   Updated: 2018/09/29 09:41:36 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

/*
** ft qui affiche pixel
*/

void				ft_print(double x, double y, t_op *graph, t_env *env)
{
	unsigned int	i;
	unsigned int	pixels_max;
	unsigned int	color;
	t_fract			*fm;
	t_col			*col;

	col = (t_col*)env->color;
	fm = (t_fract*)env->fract;
	i = ((y * graph->i_len) + x);
	pixels_max = graph->i_hei * graph->i_len;
	if ((ft_iteration_fractal(fm, env->fractal_pick)) != fm->i_max)
	{
		color = fm->i_esc * col->blue + (fm->i_esc * col->green << 8);
		color += (fm->i_esc * col->red << 16);
	}
	else
		color = 0X000000;
	if ((i < pixels_max) && (x < graph->i_len) && (x > 0) && (y < graph->i_hei))
		graph->data[i] = color;
	else
		return ;
}

/*
** ft traite event clavier pour options
*/

int					ft_key(int key, t_env *env)
{
	t_op *graph;

	graph = (t_op*)env->data;
	if (key == 38 && env->j_pause == 0)
		env->j_pause = 1;
	else if (key == 38 && env->j_pause == 1)
		env->j_pause = 0;
	if (key == 15)
		ft_reset(env);
	if (key == 3)
		ft_fractal_change(env);
	if (key == 53)
	{
		mlx_destroy_image(graph->mlx, graph->img);
		free(env->color);
		free(env->data);
		free(env->fract);
		free(env);
		exit(0);
	}
	if (key == 24 || key == 27)
		ft_iter_option(env, key);
	if (key == 8)
		ft_color(env);
	return (0);
}

/*
** ft traite event souris pour le zoom
*/

int					ft_mouse(int mouse, int x, int y, t_env *env)
{
	t_fract *fract;

	fract = (t_fract*)env->fract;
	if (mouse == 1 || mouse == 5)
	{
		env->zoom = 0.4;
		ft_zoom(x, y, env);
	}
	if (mouse == 2 || mouse == 4)
	{
		env->zoom = 1.4;
		ft_zoom(x, y, env);
	}
	return (0);
}

/*
** ft affiche window
*/

int					ft_window_output(t_env *env)
{
	t_op *graph;

	graph = (t_op*)env->data;
	mlx_key_hook(graph->win, ft_key, (void *)env);
	mlx_mouse_hook(graph->win, ft_mouse, (void *)env);
	mlx_hook(graph->win, M_NOT, PTR_M_MASK, ft_julia_rotation, env);
	mlx_loop(graph->mlx);
	return (0);
}
