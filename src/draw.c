#include "../fractol.h"

void	ft_draw_mandelbrot(t_fractal *fractal)
{
	while (pow(fractal->z_re, 2.0) + pow(fractal->z_im, 2.0)
		<= 4 && fractal->iter < fractal->max_iter)
	{
		fractal->z_tmp = fractal->z_re;
		fractal->z_re = pow(fractal->z_re, 2.0)
			- pow(fractal->z_im, 2.0) + fractal->c_re;
		fractal->z_im = 2.0 * fractal->z_tmp
			* fractal->z_im + fractal->c_im;
		fractal->iter++;
	}
}

void	ft_draw_julia(t_fractal *fractal)
{
	while (pow(fractal->z_re, 2.0) + pow(fractal->z_im, 2.0)
		<= 4 && fractal->iter < fractal->max_iter)
	{
		fractal->z_tmp = fractal->z_re;
		fractal->z_re = pow(fractal->z_re, 2.0)
			- pow(fractal->z_im, 2.0) + fractal->j_re;
		fractal->z_im = 2.0 * fractal->z_tmp
			* fractal->z_im + fractal->j_im;
		fractal->iter++;
	}
}

void	ft_draw_mandelbor(t_fractal *fractal)
{
	while (pow(fractal->z_re, 2.0) + pow(fractal->z_im, 2.0)
		<= 4 && fractal->iter < fractal->max_iter)
	{
		fractal->z_tmp = fractal->z_re;
		fractal->z_re = pow(fractal->z_re, 2.0)
			- pow(fractal->z_im, 2.0) + fractal->c_re;
		fractal->z_im = -2.0 * fractal->z_tmp
			* fractal->z_im + fractal->c_im;
		fractal->iter++;
	}
}

void	ft_draw_fractal(t_fractal *fractal)
{
	if (fractal->type == 'm')
		ft_draw_mandelbrot(fractal);
	else if (fractal->type == 'j')
		ft_draw_julia(fractal);
	else if (fractal->type == '1')
		ft_draw_mandelbor(fractal);
}
