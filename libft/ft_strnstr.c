#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	i;

	n = ft_strlen(needle);
	if (!n)
		return ((char *)haystack);
	i = 0;
	while (len > 0 && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (len < n)
				return ((void *)0);
			if (ft_strncmp((char *)&haystack[i], needle, n) == 0)
				return ((char *)&haystack[i]);
		}
		i++;
		len--;
	}
	return ((void *)0);
}
