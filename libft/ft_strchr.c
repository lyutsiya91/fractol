#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	return (ft_memchr(s, c, i));
}
