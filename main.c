/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:53:35 by rvolberg          #+#    #+#             */
/*   Updated: 2018/09/29 09:35:07 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

/*
** ft qui determine fractal input
*/

int			ft_pick_fractal(char *name)
{
	if ((ft_strcmp(name, "mandelbrot")) == 0)
		return (0);
	else if ((ft_strcmp(name, "julia") == 0))
		return (1);
	else if ((ft_strcmp(name, "mandelbar") == 0))
		return (2);
	return (-1);
}

/*
** fonction retour d'autre fonction avant de remplir
** l'image et input instruction options
*/

void		ft_send_fractal(t_env *env)
{
	t_op	*graph;

	graph = (t_op*)env->data;
	if (env->fractal_pick == 1)
		ft_julia_fractal(env);
	else
		ft_mandel_fractal(env);
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img, 0, 0);
	mlx_string_put(graph->mlx, graph->win, 10, 10, 0XF63106, "iter '-'/'+'");
	mlx_string_put(graph->mlx, graph->win, 10, 30, 0XF63106, "reset 'R'");
	mlx_string_put(graph->mlx, graph->win, 10, 50, 0XF63106, "color 'C'");
	mlx_string_put(graph->mlx, graph->win, 10, 70, 0XF63106, "fractal 'F'");
	mlx_string_put(graph->mlx, graph->win, 10, 90, 0XF63106, "pause J 'J'");
	ft_window_output(env);
}

/*
** ft main
*/

int			main(int argc, char **argv)
{
	t_env	*env;
	int		fract_pick;
	int		bbp;
	int		sl;
	int		end;

	env = NULL;
	if ((argc != 2) || (ft_pick_fractal(argv[1]) == -1))
	{
		ft_putendl_fd("usage:\t./fractol [fractal]", 2);
		ft_putendl_fd("mandelbrot\njulia\nmandelbar", 2);
		return (0);
	}
	fract_pick = ft_pick_fractal(argv[1]);
	env = ft_init_env(fract_pick, &bbp, &sl, &end);
	ft_send_fractal(env);
	return (0);
}
