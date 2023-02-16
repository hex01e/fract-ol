/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:45:47 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/15 19:06:02 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	julia_iter_loop(t_mlx_data *mlx_data, t_win_d *d, t_complex *c)
{
	int	iter;
	double	temp;
	t_complex	z;

	z.re = get_coord(d->w , WIDTH, mlx_data) + mlx_data->x_;
	z.im = get_coord(d->h , HEIGHT, mlx_data) + mlx_data->y_;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter <= ITER_MAX)
	{
		temp = z.re * z.re - z.im * z.im + c->re;
		z.im = 2 * z.re * z.im + c->im;
		z.re = temp;
		iter++;
	}
	draw(z, *d, iter, mlx_data);
	d->w++;
}