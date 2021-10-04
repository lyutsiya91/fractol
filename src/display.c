#include "../fractol.h"

void	ft_pixel_put(t_data *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_length
			+ x *(win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_color(int iter, int max_iter, int color)
{
	int	t_color;
	int	table[4][5];
	int	i;
	int	j;
	int	x;

	x = 1;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			table[i][j] = 0x310062 * (x + 10);
			j++;
			x *= 2;
		}
		i++;
	}
	if (iter == max_iter)
		t_color = 0x000;
	else
		t_color = table[color][iter % 5];
	return (t_color);
}

void	ft_create_fractal(t_fractal *fractal)
{
	int	t_color;

	fractal->y = 0;
	while (fractal->y < HEIGHT)
	{
		fractal->c_im = fractal->max_im - fractal->y * fractal->scale_im;
		fractal->x = 0;
		while (fractal->x < WIDTH)
		{
			fractal->c_re = fractal->min_re + fractal->x * fractal->scale_re;
			fractal->iter = 0;
			fractal->z_re = fractal->c_re;
			fractal->z_im = fractal->c_im;
			ft_draw_fractal(fractal);
			t_color = ft_color(fractal->iter, fractal->max_iter, fractal->col);
			ft_pixel_put(&fractal->win, fractal->x, fractal->y, t_color);
			fractal->x++;
		}
		fractal->y++;
	}	
}

void	ft_display_fractal(t_fractal *fractal)
{
	mlx_clear_window(fractal->win.mlx, fractal->win.win);
	ft_create_fractal(fractal);
	mlx_put_image_to_window(fractal->win.mlx, fractal->win.win,
		fractal->win.img, 0, 0);
}

void	ft_init_fractal(t_fractal *fractal)
{
	fractal->min_re = -2.0;
	fractal->max_re = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;
	fractal->scale_re = (fractal->max_re - fractal->min_re) / WIDTH;
	fractal->scale_im = (fractal->max_im - fractal->min_im) / HEIGHT;
	fractal->max_iter = 50;
	fractal->col = 0;
}
