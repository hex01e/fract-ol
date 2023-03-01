/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:17:19 by houmanso          #+#    #+#             */
/*   Updated: 2023/03/01 21:49:20 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_iter_loop(t_win_d *d, t_complex c, t_mlx_data *mlx_data)
{
	t_complex	z;
	int			iter;
	double		temp;

	iter = 0;
	z.re = get_coord(d->w, WIDTH, mlx_data);
	z.im = get_coord(d->h, HEIGHT, mlx_data);
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
