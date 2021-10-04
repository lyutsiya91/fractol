#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str != ((void *)0))
	{
		ft_strlcpy(str, s1, len1 + 1);
		ft_strlcat(str, s2, len1 + len2 + 1);
		return (str);
	}
	else
		return ((void *)0);
}
