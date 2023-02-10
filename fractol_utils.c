/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:59:17 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/07 11:04:34 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_complex z, t_win_d d, int iter, t_mlx_data mlx_data)
{
	int	color;

	mlx_data.img_data.line_bytes /= 4;
	color = 0xff - iter * 1024 / ITER_MAX;
	if (z.re * z.re + z.im * z.im > 4)
		mlx_data.buffer[d.h * mlx_data.img_data.line_bytes + d.w] = color;
}

double	get_coord(int p, double of, t_mlx_data *data)
{
	return ((p - of / 2) * ((data->s / data->zoom) / of));
}
