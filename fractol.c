/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:42:32 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/28 15:11:04 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_args_err(void)
{
	ft_putstr_fd("usage: ./fractol NAME\nyou can use :\n", 2);
	ft_putstr_fd("\t*) Mandelbrot", 2);
	ft_putstr_fd("\t[usage: ./fractol Mandelbrot]\n", 2);
	ft_putstr_fd("\t*) Julia", 2);
	ft_putstr_fd("\t[usage: ./fractol Julia x y]\n", 2);
	exit(1);
}

void	setup(t_mlx_data *data)
{
	data->zoom = 1;
	data->x = -0.85;
	data->y = -0.20;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		free(data->mlx);
		exit(1);
	}
	data->buffer = (int *) mlx_get_data_addr(data->img, &data->pixel_bits, &data->line_bytes
		, &data->endian);
}

void	get_started(t_mlx_data *mlx_data, int flag)
{
	setup(mlx_data);
	if (flag == MANDELBROT)
		mandelbrot(mlx_data);
	else if (flag == JULIA)
		julia(mlx_data);
}

int	main(int argc, char const *argv[])
{
	t_mlx_data	mlx_data;
	int			len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if (!ft_strncmp("mandelbrot", argv[1], len) && len == 10)
			get_started(&mlx_data, MANDELBROT);
		else if (!ft_strncmp("julia", argv[1], len) && len == 5)
			get_started(&mlx_data, JULIA);
		else
			ft_args_err();
		mlx_loop(mlx_data.mlx);
	}
	else
		ft_args_err();
	return (0);
}
