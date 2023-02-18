/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:22:15 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/18 19:19:31 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include "./libft/libft.h"

# define ITER_MAX 255
# define HEIGHT 800.0
# define WIDTH 800.0
# define MANDELBROT 1
# define JULIA 2
# define MENDEL3 3

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
	void		*mlx_win;
	int			*buffer;
	int			color;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	double		zoom;
	double		x;
	double		y;
	double		x_;
	double		y_;
}	t_mlx_data;

int		on_destroy(t_mlx_data *data);
double	get_coord(int p, double of, t_mlx_data *data);
void	redraw(t_mlx_data *data, void fractol(t_mlx_data *));
void	draw(t_complex z, t_win_d d, int iter, t_mlx_data *mlx_data);

void	julia_iter_loop(t_mlx_data *mlx_data, t_win_d *d, t_complex *c);
void	julia(t_mlx_data *mlx_data);

void	mandelbrot(t_mlx_data *mlx_data);

void	mandel3(t_mlx_data *mlx_data);

#endif