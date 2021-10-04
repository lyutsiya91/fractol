#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (ft_isdigit(str[i]))
	{
		while (str[i] && ft_isdigit(str[i]))
		{
			number = (number * 10) + ((int)str[i] - '0');
			i++;
		}
	}
	return (sign * number);
}
