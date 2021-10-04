#include "../fractol.h"

void	ft_direction(int keycode, t_fractal *fractal)
{
	if (keycode == UP)
	{
		fractal->min_im += fabs(fractal->scale_im) * 50;
		fractal->max_im += fabs(fractal->scale_im) * 50;
	}
	if (keycode == DOWN)
	{
		fractal->min_im -= fabs(fractal->scale_im) * 50;
		fractal->max_im -= fabs(fractal->scale_im) * 50;
	}
	if (keycode == LEFT)
	{
		fractal->min_re -= fabs(fractal->scale_re) * 50;
		fractal->max_re -= fabs(fractal->scale_re) * 50;
	}
	if (keycode == RIGHT)
	{
		fractal->min_re += fabs(fractal->scale_re) * 50;
		fractal->max_re += fabs(fractal->scale_re) * 50;
	}
}

int	ft_keypress(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == 36)
	{
		if (fractal->col >= 0 && fractal->col <= 3)
			fractal->col += 1;
		if (fractal->col == 4)
			fractal->col = 0;
		ft_display_fractal(fractal);
		return (0);
	}
	ft_direction(keycode, fractal);
	fractal->scale_re = (fractal->max_re - fractal->min_re) / WIDTH;
	fractal->scale_im = (fractal->max_im - fractal->min_im) / HEIGHT;
	ft_display_fractal(fractal);
	return (0);
}

int	ft_mouse_motion(int x, int y, t_fractal *fractal)
{
	if (fractal->type == 'j')
	{
		fractal->j_re = 4 * ((double)x / WIDTH - 0.5);
		fractal->j_im = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
		ft_display_fractal(fractal);
	}
	return (0);
}
