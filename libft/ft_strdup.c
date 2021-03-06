#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(*s1) * (len + 1));
	if (str != ((void *)0))
	{
		i = 0;
		while (i < len)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return ((void *)0);
}
