#include "cub3d.h"

void draw_wall(t_mlx *mlx, t_texture *texture, int x)
{
	int wh;

	// double fov_h = get_fovh();
	// double fov_v = fov_h * (double)mlx->game_info->window_h / (double)mlx->game_info->window_w;
	wh = get_wall_height(mlx->ray->w_dist, SY, FOV_V);
	// wh = get_wall_height(mlx->ray->w_dist, mlx->game_info->window_h, get_fovv(get_fovh(), mlx->game_info->window_w, mlx->game_info->window_h));
	int y0 = (int)((mlx->game_info->window_h - wh) / 2.0);
	int y1 = y0 + wh - 1;

	int ystart = MAX(0, y0);
	int yend = MIN(mlx->game_info->window_h - 1, y1);
	int yoffset = ystart;

	double h;
	h = yend - ystart;

	while (ystart < yend)
	{
		// mlx->canvas->data[((int)floor(ystart) * mlx->game_info->window_w + (int)floor(x))] = 0xff00ff;
		mlx->canvas->data[(int)floor(ystart) * mlx->game_info->window_w + (int)floor(x)] =
				texture->image->data[((int)floor((ystart - yoffset) * texture->height / h) * texture->width) + (int)floor((texture->width * mlx->ray->w_ratio))];
		ystart++;
	}
}

// // int render(t_player *player, t_gameinfo *game_info, t_image *image)
void draw_floor(t_mlx *mlx, t_render *render)
{
	int y;

	y = 0;
	if (y < mlx->game_info->window_h - 1)
	{
		render->f_ec = get_fov_min_dist(mlx->game_info);
		while (y + 1 < mlx->game_info->window_h)
		{
			render->f_h = (double)(mlx->game_info->window_h - 1 - y) / mlx->game_info->window_h;
			render->f_d = render->f_ec / (1.0 - 2 * render->f_h);
			// double lum_f = get_luminosity(D);
			draw_horiz_line(mlx, y, 0, mlx->game_info->window_w, 0xffffff);
			draw_horiz_line(mlx, mlx->game_info->window_h - 1 - y, 0, mlx->game_info->window_w, 0xff0000);
			y++;
		}
	}
}

int render(t_mlx *mlx)
{
	t_render *render;
	t_intersection *inter;
	t_dir dir;
	double wdist;
	int x;

	render = (t_render *)malloc(sizeof(t_render) * 1);
	if (!render)
		print_error("CANNOT ASSIGN RENDER");
	inter = (t_intersection *)malloc(sizeof(t_intersection) * 1);
	if (!inter)
		print_error("CANNOT ASSIGN INTERSECTION");
	// init_intersection(mlx, inter);

	render->px = mlx->player->x;
	render->py = mlx->player->y;
	render->th = mlx->player->th;

	fill_window(mlx, 0x000000);
	draw_floor(mlx, render);

	x = 0;
	while (x < mlx->game_info->window_w)
	{
		mlx->ray->w_dist = cast_single_ray(mlx, inter, x);
		printf("** ray %3d : dist %.2f\n", x, mlx->ray->w_dist);
		draw_wall(mlx, mlx->w_texture, x);
		x++;
	}
	mlx_put_image_to_window(mlx, mlx->window, mlx->canvas->image, 0, 0);
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
	mlx_hook(mlx->window, X_EVENT_KEY_PRESS, 0, &key_press, mlx);

	print_gameinfo(mlx->game_info);
	load_textures(mlx);
	mlx->canvas = create_image(mlx, mlx->game_info->window_w, mlx->game_info->window_h);
	/* IMAGE */
	render(mlx);

	mlx_loop(mlx->mlx);

	// Game End
	// free_info(game_info);
	//while(1);
	return (0);
}
