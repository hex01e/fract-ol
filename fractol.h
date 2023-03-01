/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:43:23 by houmanso          #+#    #+#             */
/*   Updated: 2023/03/01 21:55:10 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include "./libft/libft.h"

# define HEIGHT 800.0
# define WIDTH 800.0
# define MANDELBROT 1
# define JULIA 2

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_win_d
{
	int	w;
	int	h;
}	t_win_d;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*img;
	int			*buffer;
	void		*mlx_win;
	double		zoom;
	double		x;
	double		y;
	int			max;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	t_complex	c;
	t_complex	z;
}	t_mlx_data;

int		on_destroy(t_mlx_data *data);
double	get_coord(int p, double of, t_mlx_data *data);
void	draw(t_win_d d, int iter, t_mlx_data *mlx_data);
void	redraw(t_mlx_data *data, void fractol(t_mlx_data *));

void	julia(t_mlx_data *mlx_data);
void	julia_iter_loop(t_win_d *d, t_complex c, t_mlx_data *mlx_data);

void	mandelbrot(t_mlx_data *mlx_data);
void	mandelbrot_iter_loop(t_win_d *d, t_mlx_data *mlx_data);

#endif