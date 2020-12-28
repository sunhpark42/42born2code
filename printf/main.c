#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{
	char		a = 'b';
	char		*b = "42seoul";
	int			c = -42;
	int			d = 2147483647;
	int			e = 1234;
	int			f = 1234;
	int			*g = &f;

	printf("Return(mine) : %d", ft_printf("%c, %s, %d, %i, %x, %X, %p, %%\n", a, b, c, d, e, f, g));
	printf("\n");
	printf("Return(real) : %d", printf("%c, %s, %d, %i, %x, %X, %p, %%\n", a, b, c, d, e, f, g));
}
