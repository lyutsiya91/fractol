#include "../fractol.h"

void	ft_hooks(t_fractal *fractal)
{
	mlx_mouse_hook(fractal->win.win, ft_mouse_zoom, fractal);
	mlx_hook(fractal->win.win, 6, 1L << 6,
		ft_mouse_motion, fractal);
	mlx_hook(fractal->win.win, 2, 1L << 0, ft_keypress, fractal);
}

int	ft_create_window(t_fractal *fractal)
{
	fractal->win.mlx = mlx_init();
	if (fractal->win.mlx != NULL)
	{
		fractal->win.win = mlx_new_window(fractal->win.mlx, WIDTH,
				HEIGHT, "fractol");
		if (fractal->win.win != NULL)
		{
			fractal->win.img = mlx_new_image(fractal->win.mlx, WIDTH, HEIGHT);
			if (fractal->win.img != NULL)
			{
				fractal->win.addr = mlx_get_data_addr(fractal->win.img,
						&fractal->win.bits_per_pixel, &fractal->win.line_length,
						&fractal->win.endian);
				mlx_put_image_to_window(fractal->win.mlx, fractal->win.win,
					fractal->win.img, 0, 0);
				ft_hooks(fractal);
				ft_init_fractal(fractal);
				ft_display_fractal(fractal);
				mlx_loop(fractal->win.mlx);
				return (0);
			}
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	ft_bzero(&fractal, sizeof(t_fractal));
	ft_parsing_args(argc, argv, &fractal);
	if (ft_create_window(&fractal))
		return (1);
	return (0);
}
