
#include "so_long.h"

int	ft_extension_check(const char *s1, const char *s2, int n)
{
	int	i;

	i = ft_strlen(s1) - n;
	while (s1[i] && s2[i] && n != 0 && (s1[i] == s2[i]))
	{
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}