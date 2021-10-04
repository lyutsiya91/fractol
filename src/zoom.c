#include "../fractol.h"

void	ft_zoom_in(double new_re, double new_im, t_fractal *fractal)
{
	fractal->max_re = new_re + ((fractal->max_re - new_re) * 1.2);
	fractal->min_re = new_re + ((fractal->min_re - new_re) * 1.2);
	fractal->max_im = new_im + ((fractal->max_im - new_im) * 1.2);
	fractal->min_im = new_im + ((fractal->min_im - new_im) * 1.2);
	fractal->scale_re = (fractal->max_re - fractal->min_re) / WIDTH;
	fractal->scale_im = (fractal->max_im - fractal->min_im) / HEIGHT;
	ft_display_fractal(fractal);
}

void	ft_zoom_out(double new_re, double new_im, t_fractal *fractal)
{
	fractal->max_re = new_re + ((fractal->max_re - new_re) * 0.8);
	fractal->min_re = new_re + ((fractal->min_re - new_re) * 0.8);
	fractal->max_im = new_im + ((fractal->max_im - new_im) * 0.8);
	fractal->min_im = new_im + ((fractal->min_im - new_im) * 0.8);
	fractal->scale_re = (fractal->max_re - fractal->min_re) / WIDTH;
	fractal->scale_im = (fractal->max_im - fractal->min_im) / HEIGHT;
	ft_display_fractal(fractal);
}

int	ft_mouse_zoom(int button, int x, int y, t_fractal *fractal)
{
	double	new_re;
	double	new_im;

	new_re = fractal->min_re + x * fractal->scale_re;
	new_im = fractal->max_im - y * fractal->scale_im;
	if (button == 4)
		ft_zoom_in(new_re, new_im, fractal);
	if (button == 5)
		ft_zoom_out(new_re, new_im, fractal);
	return (0);
}
