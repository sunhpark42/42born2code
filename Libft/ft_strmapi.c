#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ret;
	int			i;
	
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (0);
	i = 0;
	while (*(s + i))
	{
		*(ret + i) = f(i , *(s + i));
		i++;
	}
	return (ret);
}
