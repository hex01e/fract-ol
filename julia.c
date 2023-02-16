/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:41:14 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/15 19:06:06 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_event(int code, t_mlx_data *data)
{
	if (code == 1)
	{
		data->zoom = 1;
		redraw(data, julia);
	}
	else if (code == 53)
		on_destroy(data);
	else if (code == 15)
	{
		data->zoom = 1;
		redraw(data, julia);
	}
	return (1);
}

static int	mouse_event(int code, int x, int y, t_mlx_data *data)
{
	if (code == 1)
	{
		data->x = get_coord(x, WIDTH, data);
		data->y = get_coord(y, HEIGHT, data);
		redraw(data, julia);
	}
	else if (code == 4)
	{
		data->zoom *= 1.2;
		redraw(data, julia);
	}
	else if (code == 5)
	{
		data->zoom /= 1.2;
		redraw(data, julia);
	}
	 return (1);
}

void	catch_events(t_mlx_data *mlx_data)
{
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img, 0, 0);
	mlx_hook(mlx_data->mlx_win, 17, 0, on_destroy,mlx_data);
	mlx_mouse_hook(mlx_data->mlx_win, mouse_event, mlx_data);
	mlx_key_hook(mlx_data->mlx_win, key_event, mlx_data);
}

void	julia(t_mlx_data *mlx_data)
{
	t_win_d		d;
	int			iter;
	double		temp;

	d.h = 0;
	mlx_data->c.im = mlx_data->y;
	mlx_data->c.re = mlx_data->x;
	while (d.h < HEIGHT)
	{
		d.w= 0;
		while (d.w < WIDTH)
		{
			mlx_data->z.re = get_coord(d.w , WIDTH, mlx_data);
			mlx_data->z.im = get_coord(d.h , HEIGHT, mlx_data);
			iter = 0;
			while (mlx_data->z.re * mlx_data->z.re + mlx_data->z.im * mlx_data->z.im <= 4 && iter <= ITER_MAX)
			{
				temp = mlx_data->z.re * mlx_data->z.re - mlx_data->z.im * mlx_data->z.im + mlx_data->c.re;
				mlx_data->z.im = 2 * mlx_data->z.re * mlx_data->z.im + mlx_data->c.im;
				mlx_data->z.re = temp;
				iter++;
			}
			draw(mlx_data->z, d, iter, mlx_data);
			d.w++;
		}
		d.h++;
	}
	catch_events(mlx_data);
}