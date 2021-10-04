#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 600
# define WIDTH 900
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractal
{
	char	type;
	double	z_re;
	double	z_im;
	double	z_tmp;
	double	c_re;
	double	c_im;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	scale_re;
	double	scale_im;
	double	j_re;
	double	j_im;
	int		col;
	int		x;
	int		y;
	int		max_iter;
	int		iter;
	t_data	win;
}				t_fractal;

void	ft_parsing_args(int argc, char **args, t_fractal *fractal);
int		ft_define_type(int argc, char **args, t_fractal *fractal);
int		ft_check_for_julia(const char *str);

int		ft_create_window(t_fractal *fractal);
void	ft_hooks(t_fractal *fractal);

void	ft_init_fractal(t_fractal *fractal);
void	ft_display_fractal(t_fractal *fractal);
void	ft_create_fractal(t_fractal *fractal);
int		ft_color(int iter, int max_iter, int color);
void	ft_pixel_put(t_data *win, int x, int y, int color);

void	ft_draw_fractal(t_fractal *fractal);
void	ft_draw_mandelbrot(t_fractal *fractal);
void	ft_draw_julia(t_fractal *fractal);
void	ft_draw_mandelbor(t_fractal *fractal);

int		ft_mouse_zoom(int button, int x, int y, t_fractal *fractal);
void	ft_zoom_in(double new_re, double new_im, t_fractal *fractal);
void	ft_zoom_out(double new_re, double new_im, t_fractal *fractal);

int		ft_mouse_motion(int x, int y, t_fractal *fractal);
int		ft_keypress(int keycode, t_fractal *fractal);
void	ft_direction(int keycode, t_fractal *fractal);

#endif
