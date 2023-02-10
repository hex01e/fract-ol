/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:03:48 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/06 11:14:50 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_vars(int *iter, t_complex *c, t_complex *z, t_win_d *d)
{
	*iter = 0;
	z->re = 0;
	z->im = 0;
	c->re = (d->w - HEIGHT / 2) * (4.0 / HEIGHT);
	c->im = (d->h - WIDTH / 2) * (4.0 / WIDTH);
}

void	mandelbrot(t_mlx_data *mlx_data)
{
	t_complex	c;
	t_complex	z;
	t_win_d		d;
	double		temp;
	int			iter;

	d.h = 0;
	while (d.h < HEIGHT)
	{
		d.w = 0;
		while (d.w < WIDTH)
		{
			set_vars(&iter, &c, &z, &d);
			while (z.re * z.re + z.im * z.im <= 4 && iter <= ITER_MAX)
			{
				temp = z.re * z.re - z.im * z.im + c.re;
				z.im = 2 * z.re * z.im + c.im;
				z.re = temp;
				iter++;
			}
			draw(z, d, iter, *mlx_data);
			d.w++;
		}
		d.h++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img, 0, 0);
}
