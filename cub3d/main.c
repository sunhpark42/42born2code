#include "cub3d.h"

// t_image image;
// t_image w_image;
// t_gameinfo *game_info;
// t_player *player;
// void *mlx;
// void *window;

// t_texture w_texture;

// double w_ratio;

// void draw_wall(t_gameinfo *game_info, t_image *image, double dist, int x, int color, int xstart)
// {
// }
// {
// 	int wh;
// 	int ww;

// 	wh = get_wall_height(dist);

// 	/* start/end y position of the wall slice */
// 	int y0 = (int)((game_info->window_h - wh) / 2.0);
// 	int y1 = y0 + wh - 1;

// 	/* need clipping */
// 	int ystart = MAX(0, y0);
// 	int yend = MIN(game_info->window_h - 1, y1);

// 	//draw_line(image, game_info, x, ystart, x, yend, w_image_array[y * 128 / (y1 - y0)][]);

// 	double delta_x;
// 	double delta_y;
// 	double step;

// 	delta_y = (double)yend - (double)ystart;
// 	step = fabs(delta_y);
// 	delta_y /= step;

// 	double ye;
// 	double ys;

// 	ye = yend;
// 	ys = ystart;

// 	double h;
// 	double w;

// 	h = ye - ys;
// 	w = h * SX / SY;

// 	double y_offset;
// 	double x_offset;
// 	y_offset = ys;

// 	while (ystart < yend)
// 	{
// 		image->data[((int)floor(ystart) * game_info->window_w + (int)floor(x))] =
// 				w_texture.image->data[((int)floor((ystart - ys) * w_texture.height / h) * w_texture.width) + (int)floor((w_texture.width * w_ratio))];
// 		ystart++;
// 	}
// }

// // int render(t_player *player, t_gameinfo *game_info, t_image *image)
// int render(t_mlx *mlx)
// {
// 	return (0);
// }
// {
// 	double px;
// 	double py;
// 	double th;

// 	px = mlx->player->x;
// 	py = mlx->player->y;
// 	th = mlx->player->th;

// 	fill_window(mlx, 0x000000);

// 	int x, y;

// 	y = 0;
// 	if (y < SY - 1)
// 	{
// 		double EC = get_fov_min_dist();

// 		for (int y1 = y + 1; y1 < SY; y1++)
// 		{
// 			double h = (double)(SY - 1 - y1) / SY;
// 			double D = EC / (1. - 2 * h);
// 			// .. double lum_f = get_luminosity(D);

// 			draw_line(image, game_info, 0, y1, SX, y1, 0xffffff);
// 			draw_line(image, game_info, 0, SY - 1 - y1, SX, SY - 1 - y1, 0xff00ff);
// 		}
// 	}

// 	x = 0;
// 	int tx = -1;
// 	int ty = -1;
// 	t_intersection *inter;
// 	while (x < SX)
// 	{
// 		t_dir dir;

// 		inter = (t_intersection *)malloc(sizeof(t_intersection));
// 		if (!inter)
// 			print_error("ERROR");
// 		init_intersection(mlx, inter);
// 		double wdist = cast_single_ray(game_info, inter, x);
// 		printf("** ray %3d : disx %.2f\n", x, inter->wdist);
// 		draw_wall(game_info, image, wdist, x, wall_colors[dir], xstart);
// 		if (inter)
// 			free(inter);
// 		x++;
// 	}

// 	mlx_put_image_to_window(mlx, window, image->image_ptr, 0, 0);
// 	return (0);
// }

int render(t_mlx *mlx)
{
	return (0);
}

int main(int argc, char *argv[])
{
	int fd;
	t_mlx *mlx;

	if (argc != 2)
		print_error("the number of args is not 2");
	// TODO : .cub 파일인지 확인
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		print_error("cannot open the .cub file");

	// MLX에 필요한 모든 정보
	mlx = (t_mlx *)malloc(sizeof(t_mlx) * 1);
	if (!mlx)
		print_error("cannnot assign mlx");
	init_mlx(mlx);

	parse_game(mlx->game_info, fd);
	get_player_position(mlx);
	if (!is_validate_map(mlx->game_info))
		print_error("MAP ERROR");

	/* mlx */

	mlx->window = mlx_new_window(mlx->mlx, mlx->game_info->window_w, mlx->game_info->window_h, "SUNNY's CUB3D");
	// window = mlx_new_window(mlx, game_info->window_w, game_info->window_h, "SUNNY's CUB3D");
	mlx_hook(mlx->window, X_EVENT_KEY_PRESS, 0, &key_press, mlx);

	print_gameinfo(mlx->game_info);
	load_textures(mlx);

	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->w_texture->image->image, 0, 0);
	// load_image();
	/* IMAGE */

	//fill_window(&image, game_info, 0x0000ff);
	//draw_line(&image, game_info, 10, 0, 10, 400, 0xff0000);
	// render(mlx);

	mlx_loop(mlx->mlx);

	// Game End
	// free_info(game_info);
	//while(1);
	return (0);
}
