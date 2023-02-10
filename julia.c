/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:41:14 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/09 23:14:50 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_event(int code, t_mlx_data *data)
{
	if (code == 1)
	{
		data->x_ = 0;
		data->y_ = 0;
		data->zoom = 1;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
		julia(data);
	}
	else if (code == 123)
	{
		data->x_ -= 0.2/ data->zoom ;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
		julia(data);
	}
	else if (code == 124)
	{
		data->x_ += 0.2/ data->zoom;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
		julia(data);
	}
	else if (code == 125)
	{
		data->y_ += 0.2/ data->zoom;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
		julia(data);
	}
	else if (code == 126)
	{
		data->y_ -= 0.2/ data->zoom;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
		julia(data);
	}
	return (1);
}

int		mouse_event(int code, int x, int y, t_mlx_data *data)
{
	double	temp_x;
	double	temp_y;

	if (code == 1)
	{
		data->x = get_coord(x, WIDTH, data) + data->x_;
		data->y = get_coord(y, HEIGHT, data) + data->y_;
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
		julia(data);
	}
	else if (code == 4)
	{
		temp_x = get_coord(x, WIDTH, data);
		temp_y = get_coord(y, WIDTH, data);
		data->zoom *= 1.2;
		data->x_ += (temp_x - get_coord(x, WIDTH, data));
		data->y_ += (temp_y - get_coord(y, WIDTH, data));
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
		julia(data);
	}
	else if (code == 5)
	{
		temp_x = get_coord(x, WIDTH, data);
		temp_y = get_coord(y, WIDTH, data);
		data->zoom /= 1.2;
		data->x_ += (temp_x - get_coord(x, WIDTH, data));
		data->y_ += (temp_y - get_coord(y, WIDTH, data));
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->mlx_win);
		data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
		julia(data);
	}
	 return (1);
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
			mlx_data->z.re = get_coord(d.w , WIDTH, mlx_data) + mlx_data->x_;
			mlx_data->z.im = get_coord(d.h , HEIGHT, mlx_data) + mlx_data->y_;
			iter = 0;
			while (mlx_data->z.re * mlx_data->z.re + mlx_data->z.im * mlx_data->z.im <= 4 && iter <= ITER_MAX)
			{
				temp = mlx_data->z.re * mlx_data->z.re - mlx_data->z.im * mlx_data->z.im + mlx_data->c.re;
				mlx_data->z.im = 2 * mlx_data->z.re * mlx_data->z.im + mlx_data->c.im;
				mlx_data->z.re = temp;
				iter++;
			}
			draw(mlx_data->z, d, iter, *mlx_data);
			d.w++;
		}
		d.h++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img, 0, 0);
	mlx_mouse_hook(mlx_data->mlx_win, mouse_event, mlx_data);
	mlx_key_hook(mlx_data->mlx_win, key_event, mlx_data);
}