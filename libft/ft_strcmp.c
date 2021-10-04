#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		len = len1;
	else
		len = len2;
	return (ft_strncmp(s1, s2, len));
}
