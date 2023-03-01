/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:36:08 by houmanso          #+#    #+#             */
/*   Updated: 2023/03/01 21:48:21 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_iter_loop(t_win_d *d, t_mlx_data *mlx_data)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			iter;

	iter = 0;
	z.re = 0;
	z.im = 0;
	c.re = get_coord(d->w, WIDTH, mlx_data);
	c.im = get_coord(d->h, HEIGHT, mlx_data);
	while (z.re * z.re + z.im * z.im <= 4 && iter <= mlx_data->max)
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		iter++;
	}
	draw(*d, iter, mlx_data);
	d->w++;
}
