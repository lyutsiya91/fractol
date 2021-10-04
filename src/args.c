#include "../fractol.h"

int	ft_check_for_julia(const char *str)
{
	if (!ft_isdigit(*str) && *str != '-')
		return (1);
	if (str[0] == '-' && !ft_isdigit(str[1]))
		return (1);
	if (ft_strchr(str, '.') != ft_strrchr(str, '.'))
		return (1);
	return (0);
}

int	ft_define_type(int argc, char **args, t_fractal *fractal)
{
	if (!ft_strcmp(args[1], "MANDELBROT"))
	{
		fractal->type = 'm';
		return (0);
	}
	else if (!ft_strcmp(args[1], "MANDELBAR"))
	{
		fractal->type = '1';
		return (0);
	}
	else if (argc >= 4 && !ft_strcmp(args[1], "JULIA"))
	{
		fractal->type = 'j';
		if (ft_check_for_julia(args[2]) || ft_check_for_julia(args[3]))
		{
			printf("Invalid numbers for JULIA\n");
			exit(0);
		}
		fractal->j_re = ft_atof(args[2]);
		fractal->j_im = ft_atof(args[3]);
		return (0);
	}
	return (1);
}

void	ft_parsing_args(int argc, char **args, t_fractal *fractal)
{
	if (argc > 1)
	{
		if (!ft_define_type(argc, args, fractal))
			return ;
	}
	printf("USAGE: [ MANDELBROT | MANDELBAR ");
	printf("| JULIA PART_REAL PART_IMAGINARY ]\n");
	exit(0);
}
