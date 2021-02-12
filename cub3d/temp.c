#include "mlx.h"

int 	main(void)
{
	void	*window;

	window = mlx_init();
	if (!window)
		return (0);
	mlx_new_window(window, 100, 100, "hello");
}
