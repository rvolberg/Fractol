/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:06:24 by rvolberg          #+#    #+#             */
/*   Updated: 2018/09/29 09:36:20 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# define M_NOT 6
# define PTR_M_MASK (1L<<6)
# define SQUARE(x) (x * x)

typedef struct			s_output
{
	void				*mlx;
	void				*win;
	void				*img;
	unsigned int		*data;
	int					w_len;
	int					w_hei;
	int					i_len;
	int					i_hei;
	struct s_output		*next;
}						t_op;
typedef struct			s_fractal
{
	int					i_max;
	int					i_esc;
	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;
	double				scale_x;
	double				scale_y;
	double				zr;
	double				zi;
	double				cr;
	double				ci;
	struct s_fractal	*next;
}						t_fract;
typedef struct			s_palette
{
	unsigned int		red;
	unsigned int		blue;
	unsigned int		green;
	int					palette;
	struct s_palette	*next;
}						t_col;
typedef struct			s_env
{
	double				zoom;
	t_col				*color;
	void				*fract;
	void				*data;
	int					j_pause;
	int					fractal_pick;
	double				x_zoom;
	double				y_zoom;
	struct s_env		*next;
}						t_env;
int						ft_pick_fractal(char *name);
void					ft_send_fractal(t_env *env);
void					ft_print(double x, double y, t_op *data, t_env *env);
int						ft_window_output(t_env *env);
int						ft_key(int key, t_env *graph);
int						ft_mouse(int x, int y, int mouse, t_env *env);
t_env					*ft_init_env(int fpick, int *bbp, int *sl, int *end);
t_op					*ft_init_struct_data(int *bbp, int *sl, int *end);
t_fract					*ft_init_fractal(t_op *data);
t_col					*ft_init_color(void);
void					ft_mandel_fractal(t_env *env);
void					ft_julia_fractal(t_env *env);
int						ft_iteration_fractal(t_fract *fm, int fractal_pick);
void					ft_zoom(int x, int y, t_env *graph);
void					ft_color(t_env *env);
t_col					*ft_color_bis(t_col *col);
void					ft_iter_option(t_env *env, int key);
void					ft_reset(t_env *env);
void					ft_fractal_change(t_env *env);
int						ft_julia_rotation(int x, int y, t_env *env);

#endif
