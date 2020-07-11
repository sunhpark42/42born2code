#include "libft.h"

char	*ft_itoa(int n)
{
	int				neg;
	int				len;
	int				nb;
	char			*ret;
	int				i;
	
	len = 0;
	nb = n;
	while(nb != 0)
	{
		nb /= 10;
		len++;
	}
	neg = 1;
	if(n <= 0)
	{
		neg = -neg;
		len ++;
	}
	ret = (char*)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	nb = n;
	i = len - 1;
	while(i >= 0)
	{
		*(ret + i) = neg * (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	*(ret + len) = 0;
	if (n < 0)
		*(ret) = '-';
	return (ret);
}
