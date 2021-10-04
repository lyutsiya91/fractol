#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ans;
	char	*str;

	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	str = (char *)s;
	ans = (void *)0;
	while (*str)
	{
		str = ft_memchr(str, c, ft_strlen(str) + 1);
		if (str == (void *)0)
			break ;
		ans = str;
		str++;
	}
	return (ans);
}
