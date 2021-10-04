#include "libft.h"

double	ft_atof(const char *str)
{
	int		sign;
	double	right;
	double	left;
	int		e;

	left = 0;
	right = 0.0;
	sign = 1;
	e = 1;
	if (ft_strchr(str, '.') == 0)
		return (ft_atoi(str));
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		left = left * 10 + *str++ - '0';
	str++;
	while (ft_isdigit(*str))
	{
		right = right * 10 + *str++ - '0';
		e *= 10;
	}
	return (sign * ((double)left + (double)right / e));
}
