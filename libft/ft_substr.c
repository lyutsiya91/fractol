#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return ((void *)0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str != ((void *)0))
	{
		i = 0;
		while (i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return ((void *)0);
}
