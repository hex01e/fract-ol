/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:42:32 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/09 23:53:56 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(t_mlx_data  *mlx_data)
{
	ft_putstr_fd("usage: ./fractol NAME\nyou can use :\n", 2);
	ft_putstr_fd("\t*) Mandelbrot", 2);
	ft_putstr_fd("\t[usage: ./fractol Mandelbrot]\n", 2);
	ft_putstr_fd("\t*) Julia", 2);
	ft_putstr_fd("\t[usage: ./fractol Julia x y]\n", 2);
	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
	free(mlx_data->mlx);
	exit(1);
}

void ff() {
	system("leaks fractol");
}

int	main(int argc, char const *argv[])
{
	atexit(ff);
	t_mlx_data	mlx_data;
	int			len;
	
	mlx_data.zoom = 1;
	mlx_data.x = -0.85;
	mlx_data.y = -0.20;
	mlx_data.x_ = 0;
	mlx_data.y_ = 0;
	mlx_data.s = 4.0;
	mlx_data.mlx = mlx_init();
	mlx_data.mlx_win = mlx_new_window(mlx_data.mlx, WIDTH, HEIGHT, "Fract-ol");
	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		mlx_data.img = mlx_new_image(mlx_data.mlx, HEIGHT, WIDTH);
		mlx_data.buffer = (int *) mlx_get_data_addr(mlx_data.img,
				&mlx_data.img_data.pixel_bits, &mlx_data.img_data.line_bytes, &mlx_data.img_data.endian);
		if (!ft_strncmp("Mandelbrot", argv[1], len) && len == 10)
			mandelbrot(&mlx_data);
		else if (!ft_strncmp("Julia", argv[1], len) && len == 5)
			julia(&mlx_data);
		else
			ft_error(&mlx_data);
		mlx_loop(mlx_data.mlx);
	}
	else
		ft_error(&mlx_data);
	return (0);
}
