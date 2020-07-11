#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	int				neg;
	char			c;
	
	neg = 1;
	if (n < 0)
		neg = -neg;
	i = 1000000000;
	while (n / i == 0)
		i /= 10;
	if(n % i == 0)
		write(fd, "0", 1);
	while (n % i != 0)
	{
		c = neg * (n / i) + '0';
		write(fd, &c, 1);
		n %= i;
		i /= 10;
	}
}
