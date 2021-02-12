#include "cub3d.h"

int			parse_game(t_gameinfo* game_info, int fd)
{
	printf("fd: %d\n", fd);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_gameinfo		*game_info;
	int				fd;

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("CANNOT OPEN .cub FILE\n");
		exit(1);
	}
	game_info = (t_gameinfo*)malloc(sizeof(t_gameinfo) * 1);
	if (!game_info)
	{
		printf("Error\n");
		return (0);
	}
	parse_game(game_info, fd);
	return (0);
}
