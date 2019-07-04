/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:05:14 by rvolberg          #+#    #+#             */
/*   Updated: 2018/09/29 09:42:23 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

/*
** ft qui s'occupe du calcule les iterations des fractales
** selon le nombre d'iterations, si la valeur obtenue reste ds range,
** on le dessine, sinon il ne fait pas partie du set.
** iteration mandelbar si pick == 2
*/

int					ft_iteration_fractal(t_fract *fm, int fractal_pick)
{
	double			tmp;

	tmp = 0;
	if (fractal_pick == 2)
	{
		while ((SQUARE(fm->zr) + SQUARE(fm->zi) < 4) && (fm->i_esc < fm->i_max))
		{
			tmp = SQUARE(fm->zr) - SQUARE(fm->zi) + fm->cr;
			fm->zi = -2 * fm->zr * fm->zi + fm->ci;
			fm->zr = tmp;
			fm->i_esc++;
		}
	}
	else
	{
		while ((SQUARE(fm->zr) + SQUARE(fm->zi) < 4) && (fm->i_esc < fm->i_max))
		{
			tmp = fm->zr;
			fm->zr = SQUARE(fm->zr) - SQUARE(fm->zi) + fm->cr;
			fm->zi = 2 * fm->zi * tmp + fm->ci;
			fm->i_esc++;
		}
	}
	return (fm->i_esc);
}

/*
** ft qui parcours l image data pour y appliquer mandelbrot et mandelbar
*/

void				ft_mandel_fractal(t_env *env)
{
	double			x;
	double			y;
	t_fract			*fm;
	t_op			*graph;

	graph = (t_op*)env->data;
	fm = (t_fract*)env->fract;
	x = 0;
	y = 0;
	while (y < graph->i_hei)
	{
		while (x < graph->i_len)
		{
			fm->cr = x / fm->scale_x + fm->min_x;
			fm->ci = y / fm->scale_y + fm->min_y;
			fm->zr = 0;
			fm->zi = 0;
			fm->i_esc = 0;
			ft_print(x, y, graph, env);
			x++;
		}
		x = 0;
		y++;
	}
}

/*
** fonction qui calcule julia
*/

void				ft_julia_fractal(t_env *env)
{
	double			x;
	double			y;
	t_fract			*fm;
	t_op			*graph;

	graph = (t_op*)env->data;
	fm = (t_fract*)env->fract;
	x = 0;
	y = 0;
	while (y < graph->i_hei)
	{
		while (x < graph->i_len)
		{
			fm->zr = x / fm->scale_x + fm->min_x;
			fm->zi = y / fm->scale_y + fm->min_y;
			fm->i_esc = 0;
			ft_print(x, y, graph, env);
			x++;
		}
		x = 0;
		y++;
	}
}
