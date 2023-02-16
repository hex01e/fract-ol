/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:34:18 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/15 19:12:35 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	mandel3(t_mlx_data *mlx_data)
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
			iter = 0;
			z.re = 0;
			z.im = 0;
			c.re = get_coord(d.w, WIDTH, mlx_data) + mlx_data->x_;
			c.im = get_coord(d.h, HEIGHT, mlx_data) + mlx_data->y_;
			while (z.re * z.re + z.im * z.im <= 4 && iter <= ITER_MAX)
			{
				temp = (z.re * z.re * z.re * z.re ) - 6 * z.re * z.re * z.im * z.im  + (z.im * z.im * z.im * z.im ) + c.re;
				z.im = 4 * z.re * z.re * z.re * z.im - 4 * z.im * z.im * z.im * z.re + c.im;
				z.re = temp;
				iter++;
			}
			draw(z, d, iter, mlx_data);
			d.w++;
		}
		d.h++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img, 0, 0);
}
