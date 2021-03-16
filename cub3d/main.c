// // #include "cub3d.h"

// // t_image image;
// // t_image w_image;
// // t_gameinfo *game_info;
// // t_player *player;
// // void *mlx;
// // void *window;

// // t_texture w_texture;

// // double w_ratio;

// // int visible[1000][1000] = {
// // 		0,
// // };
// // double zbuf[SX];

// // void print_int_array(char *arr)
// // {
// // 	int i;

// // 	i = 0;
// // 	while (i < ft_strlen(arr))
// // 	{
// // 		printf("%c ", arr[i]);
// // 		i++;
// // 	}
// // 	printf("\n");
// // }

// // void print_gameinfo(t_gameinfo *game_info)
// // {
// // 	printf("window_w : %d\n", game_info->window_w);
// // 	printf("window_h : %d\n", game_info->window_h);
// // 	printf("n_image : %s\n", game_info->n_image);
// // 	printf("s_image : %s\n", game_info->s_image);
// // 	printf("w_image : %s\n", game_info->w_image);
// // 	printf("e_image : %s\n", game_info->e_image);
// // 	printf("sprite_image : %s\n", game_info->sprite_image);
// // 	printf("f_red : %d\n", game_info->f_red);
// // 	printf("f_green : %d\n", game_info->f_green);
// // 	printf("f_blue : %d\n", game_info->f_blue);
// // 	printf("c_red : %d\n", game_info->c_red);
// // 	printf("c_green : %d\n", game_info->c_green);
// // 	printf("c_blue : %d\n", game_info->c_blue);
// // 	printf("-----------------MAP-------------------\n");
// // 	print_map(game_info->map);
// // 	printf("-----------------MAP_END-----------------\n");
// // }

// // void init_gameinfo(t_gameinfo *game_info)
// // {
// // 	game_info->window_w = 0;
// // 	game_info->window_h = 0;
// // 	game_info->n_image = NULL;
// // 	game_info->s_image = NULL;
// // 	game_info->w_image = NULL;
// // 	game_info->e_image = NULL;
// // 	game_info->sprite_image = NULL;
// // 	game_info->f_red = 0;
// // 	game_info->f_green = 0;
// // 	game_info->f_blue = 0;
// // 	game_info->c_red = 0;
// // 	game_info->c_green = 0;
// // 	game_info->c_blue = 0;
// // 	game_info->map = 0;
// // }

// // void freemap(t_gameinfo *game_info)
// // {
// // 	int i;

// // 	i = 0;
// // 	while (game_info->map && game_info->map[i])
// // 	{
// // 		free(game_info->map[i]);
// // 		i++;
// // 	}
// // 	free(game_info->map);
// // }

// // void free_info(t_gameinfo *game_info)
// // {
// // 	if (game_info->map)
// // 		freemap(game_info);
// // 	if (game_info->n_image)
// // 		free(game_info->n_image);
// // 	if (game_info->s_image)
// // 		free(game_info->s_image);
// // 	if (game_info->w_image)
// // 		free(game_info->w_image);
// // 	if (game_info->e_image)
// // 		free(game_info->e_image);
// // 	if (game_info->sprite_image)
// // 		free(game_info->sprite_image);
// // 	free(game_info);
// // }

// int get_player_position(t_player *player, t_gameinfo *game_info)
// {
// 	int x;
// 	int y;
// 	char **map;

// 	x = 0;
// 	y = 0;
// 	map = game_info->map;
// 	while (map && map[y])
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == 'N')
// 			{
// 				player->c_x = x;
// 				player->c_y = y;
// 				player->dir_y = 1;
// 				player->dir_x = 0;
// 			}
// 			if (map[y][x] == 'S')
// 			{
// 				player->c_x = x;
// 				player->c_y = y;
// 				player->dir_y = -1;
// 				player->dir_x = 0;
// 			}
// 			if (map[y][x] == 'W')
// 			{
// 				player->c_x = x;
// 				player->c_y = y;
// 				player->dir_y = 0;
// 				player->dir_x = -1;
// 			}
// 			if (map[y][x] == 'E')
// 			{
// 				player->c_x = x;
// 				player->c_y = y;
// 				player->dir_y = 0;
// 				player->dir_x = 1;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

// // void init_player(t_player *player)
// // {
// // 	player->c_x = 0;
// // 	player->c_y = 0;
// // 	player->th = 0;
// // 	player->dir_x = 0;
// // 	player->dir_y = 0;
// // 	player->n_x = 0;
// // 	player->n_y = 0;
// // 	player->move_speed = 0;
// // 	player->rot_speed = 0;
// // }

// // void print_player(t_player *player)
// // {
// // 	printf("c_x : %f\n", player->c_x);
// // 	printf("c_y : %f\n", player->c_y);
// // 	printf("dir_x : %f\n", player->dir_x);
// // 	printf("dir_y : %f\n", player->dir_y);
// // 	printf("n_x : %f\n", player->n_x);
// // 	printf("n_y : %f\n", player->n_y);
// // 	printf("move_speed : %f\n", player->move_speed);
// // 	printf("rot_speed : %f\n", player->rot_speed);
// // }

// // int map_get_cell(t_gameinfo *game_info, int x, int y)
// // {
// // 	char **map;

// // 	map = game_info->map;
// // 	if (x >= 0 && y >= 0 && y < get_maplen(map) && x < ft_strlen(map[y]))
// // 		return (map[y][x]);
// // 	return (-1);
// // }

// // int sign(double num)
// // {
// // 	return IS_ZERO(num) ? 0 : ((num > 0) ? 1 : -1);
// // }

// // double l2dist(double x0, double y0, double x1, double y1)
// // {
// // 	double dx;
// // 	double dy;

// // 	dx = x0 - x1;
// // 	dy = y0 - y1;
// // 	return sqrt(dx * dx + dy * dy);
// // }

// // t_bool get_wall_intersection(t_gameinfo *game_info, double ray, double px, double py, t_dir *wdir, double *wx, double *wy)
// // {
// // 	int xstep = sign(cos(ray)); /* +1 right , 0 no change */
// // 	int ystep = sign(sin(ray)); /* +1 up, 0 no change */

// // 	double xslope = (xstep == 0 ? INFINITY : tan(ray));
// // 	double yslope = (ystep == 0 ? INFINITY : 1. / tan(ray));

// // 	double nx = (xstep > 0 ? floor(px) + 1 : ((xstep < 0) ? ceil(px) - 1 : px));
// // 	double ny = (ystep > 0 ? floor(py) + 1 : ((ystep < 0) ? ceil(py) - 1 : py));

// // 	double f = INFINITY;
// // 	double g = INFINITY;
// // 	t_bool hit = false;
// // 	int hit_side; /* VERT or HORIZ */

// // 	while (!hit)
// // 	{
// // 		int mapx, mapy;

// // 		if (xstep != 0)
// // 			f = xslope * (nx - px) + py;
// // 		if (ystep != 0)
// // 			g = yslope * (ny - py) + px;

// // 		double dist_v = l2dist(px, py, nx, f);
// // 		double dist_h = l2dist(px, py, g, ny);

// // 		/* VERT IS NEARER */
// // 		if (dist_v < dist_h)
// // 		{
// // 			mapx = (xstep == 1) ? (int)(nx) : (int)(nx)-1;
// // 			mapy = (int)f;
// // 			hit_side = VERT;
// // 			printf("V(%d, %2.f) -> ", mapx, f);
// // 		}
// // 		else
// // 		{
// // 			mapx = (int)g;
// // 			mapy = (ystep == 1) ? (int)(ny) : (int)(ny)-1;
// // 			hit_side = HORIZ;
// // 			printf("V(%2.f, %d) -> ", g, mapy);
// // 		}

// // 		int cell = map_get_cell(game_info, mapx, mapy);
// // 		if (cell < 0)
// // 			break; /* out of range */

// // 		if (cell == '1')
// // 		{
// // 			if (hit_side == VERT)
// // 			{
// // 				*wdir = (xstep > 0) ? DIR_W : DIR_E;
// // 				*wx = nx;
// // 				*wy = f;
// // 			}
// // 			else
// // 			{
// // 				*wdir = (ystep > 0) ? DIR_S : DIR_N;
// // 				*wx = g;
// // 				*wy = ny;
// // 			}
// // 			hit = true;
// // 			printf("HIT!!!!!!!!!!WALL!!!!!!!!!!\n");
// // 			break;
// // 		}
// // 		visible[mapy][mapx] = 1;

// // 		if (hit_side == VERT)
// // 			nx += xstep;
// // 		else
// // 			ny += ystep;
// // 	}

// // 	return hit;
// // }

// // double cast_single_ray(t_gameinfo *game_info, int x, double px, double py, double th, t_dir *wdir)
// // {
// // 	double ray = (th + FOVH_2) - (x * ANGLE_PER_PIXEL);

// // 	/* wall intersection point */
// // 	double wx, wy;

// // 	if (get_wall_intersection(game_info, ray, px, py, wdir, &wx, &wy) == false)
// // 		return INFINITY; /* no intersection */

// // 	printf("DIR : %d\n", *wdir);
// // 	double wdist = l2dist(px, py, wx, wy);
// // 	if (*wdir == 0 || *wdir == 3)
// // 		w_ratio = wx - floor(wx);
// // 	else
// // 		w_ratio = wy - floor(wy);

// // 	/* 보정 */
// // 	wdist *= cos(th - ray);

// // 	return wdist;
// // }

// /* DDA */
// // void draw_line(t_image *image, t_gameinfo *game_info, double x1, double y1, double x2, double y2, int color)
// // {
// // 	double delta_x;
// // 	double delta_y;
// // 	double step;

// // 	delta_x = x2 - x1;
// // 	delta_y = y2 - y1;
// // 	step = (fabs(delta_x) > fabs(delta_y) ? fabs(delta_x) : fabs(delta_y));
// // 	delta_x /= step;
// // 	delta_y /= step;
// // 	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
// // 	{
// // 		image->data[((int)floor(y1) * game_info->window_w + (int)floor(x1))] = color;
// // 		x1 += delta_x;
// // 		y1 += delta_y;
// // 	}
// // }

// // void fill_window(t_image *image, t_gameinfo *game_info, int color)
// // {
// // 	double x;
// // 	double width;
// // 	double height;

// // 	width = (double)(game_info->window_w);
// // 	height = (double)(game_info->window_h);
// // 	x = 0;
// // 	while (x < width)
// // 	{
// // 		draw_line(image, game_info, x, 0, x, height, color);
// // 		x++;
// // 	}
// // }

// // int get_wall_height(double dist)
// // {
// // 	double fov_h;
// // 	fov_h = 2.0 * dist * tan(FOV_V / 2.0);
// // 	return (int)(SY * (WALL_H / fov_h));
// // }

// // TODO : 벽의 너비를 구해야 함.

// // void draw_wall(t_gameinfo *game_info, t_image *image, double dist, int x, int color, int xstart)
// // {
// // 	int wh;
// // 	int ww;

// // 	wh = get_wall_height(dist);

// // 	/* start/end y position of the wall slice */
// // 	int y0 = (int)((game_info->window_h - wh) / 2.0);
// // 	int y1 = y0 + wh - 1;

// // 	/* need clipping */
// // 	int ystart = MAX(0, y0);
// // 	int yend = MIN(game_info->window_h - 1, y1);

// // 	//draw_line(image, game_info, x, ystart, x, yend, w_image_array[y * 128 / (y1 - y0)][]);

// // 	double delta_x;
// // 	double delta_y;
// // 	double step;

// // 	delta_y = (double)yend - (double)ystart;
// // 	step = fabs(delta_y);
// // 	delta_y /= step;

// // 	double ye;
// // 	double ys;

// // 	ye = yend;
// // 	ys = ystart;

// // 	double h;
// // 	double w;

// // 	h = ye - ys;
// // 	w = h * SX / SY;

// // 	double y_offset;
// // 	double x_offset;
// // 	y_offset = ys;

// // 	while (ystart < yend)
// // 	{
// // 		image->data[((int)floor(ystart) * game_info->window_w + (int)floor(x))] =
// // 				w_texture.image->data[((int)floor((ystart - ys) * w_texture.height / h) * w_texture.width) + (int)floor((w_texture.width * w_ratio))];
// // 		ystart++;
// // 	}
// // }

// // double get_fov_min_dist() /* distance to the floor-FOV intersection point */
// // {
// // 	static double T = -1;
// // 	if (T < 0)
// // 		T = WALL_H / (2.0 * tan(FOV_V / 2.0));
// // 	return T;
// // }

// static int cmp_sprites(const void *a, const void *b)
// {
// 	return (((const t_sprite *)a)->dist > ((const t_sprite *)b)->dist) ? -1 : 1;
// }

// static t_sprite *get_visible_sprites(double px, double py, double p_th, int *pcnt)
// {
// 	int n = 0;
// 	t_sprite *sp = NULL;

// 	for (int x = 0; x < 8; x++)
// 	{
// 		for (int y = 0; y < 7; y++)
// 		{
// 			if (visible[y][x] == 0 || map_get_cell(game_info, x, y) != '2')
// 				continue;
// 			if (n == 0)
// 				sp = (t_sprite *)malloc(sizeof(t_sprite));
// 			else
// 				sp = (t_sprite *)realloc(sp, sizeof(t_sprite) * (n + 1));

// 			//sp[n].tex = w_image;
// 			sp[n].x = x;
// 			sp[n].y = y;
// 			sp[n].th = atan2(y + 0.5 - py, x + 0.5 - px);
// 			if (sp[n].th < 0)
// 				sp[n].th += _2PI;
// 			sp[n].dist = l2dist(px, py, x + 0.5, y + 0.5) * cos(p_th - sp[n].th);
// 			n++;
// 		}
// 	}
// 	*pcnt = n;
// 	printf("%d\n", n);
// 	return sp;
// }

// static const double pixel_per_angle = (SX - 1.0) / FOV_H;

// static void draw_sprites(px, py, p_th)
// {
// 	int nsp = 0;
// 	t_sprite *sp = get_visible_sprites(px, py, p_th, &nsp);

// 	// order
// 	qsort(sp, nsp, sizeof(t_sprite), cmp_sprites);

// 	for (int i = 0; i < nsp; i++)
// 	{
// 		int sh = get_wall_height(sp[i].dist);
// 		// double lum = get_luminosity(sp[i].dist);
// 		//t_image *ptex = texture_get(sp[i].tex);
// 		// 현재는 w_image 로 통일

// 		double angle = sp[i].th - p_th;
// 		if (angle > M_PI)
// 			angle -= _2PI;
// 		else if (angle < -M_PI)
// 			angle += _2PI;

// 		int cx = (int)((FOVH_2 - angle) * pixel_per_angle);
// 		int xmin = MAX(0, cx - sh / 2);
// 		int xmax = MIN(SX, cx + sh / 2);

// 		for (int x = xmin; x < xmax; x++)
// 		{
// 			if (sp[i].dist > zbuf[x])
// 				continue; // behind wall
// 			if (sp[i].dist < PL_RADIUS)
// 				continue;

// 			double txratio = (double)(x - cx) / sh + 0.5;
// 			int tx = (int)(txratio * w_texture.width);
// 			int y0 = (int)((SY - sh) / 2.0);

// 			for (int y = MAX(0, y0); y < MIN(SY, y0 + sh); y++)
// 			{
// 				int ty = (int)((double)(y - y0) * w_texture.height / sh);
// 				if (w_texture.image->data[((int)floor(ty) * SX) + (int)floor(tx)] == 0x000000)
// 					continue;
// 				image.data[((int)floor(y) * SX + (int)floor(x))] = 0xff0000 + i * 100;
// 			}
// 		}
// 	}
// 	if (nsp > 0)
// 		free(sp);
// }

// int render(t_player *player, t_gameinfo *game_info, t_image *image)
// {
// 	double px;
// 	double py;
// 	double th;

// 	px = player->c_x;
// 	py = player->c_y;
// 	// TODO : 정확한 시야각으로 바꾸기
// 	th = player->th;

// 	int wall_colors[4] = {0xff0000, 0xffff00, 0x0000ff, 0x00ff00};

// 	fill_window(image, game_info, 0x000000);

// 	int x, y;

// 	y = 0;
// 	if (y < SY - 1)
// 	{
// 		double EC = get_fov_min_dist();

// 		for (int y1 = y + 1; y1 < SY; y1++)
// 		{
// 			double h = (double)(SY - 1 - y1) / SY;
// 			double D = EC / (1. - 2 * h);
// 			//            double lum_f = get_luminosity(D);

// 			draw_line(image, game_info, 0, y1, SX, y1, 0xffffff);
// 			draw_line(image, game_info, 0, SY - 1 - y1, SX, SY - 1 - y1, 0xff00ff);
// 		}
// 	}

// 	x = 0;
// 	int tx = -1;
// 	int ty = -1;
// 	int bx = -1;
// 	int by = -1;
// 	int xstart = 0;
// 	while (x < SX)
// 	{
// 		t_dir dir;
// 		double wdist = cast_single_ray(game_info, x, px, py, th, &dir);
// 		zbuf[x] = wdist;
// 		printf("** ray %3d : disx %.2f\n", x, wdist);
// 		draw_wall(game_info, image, wdist, x, wall_colors[dir], xstart);
// 		x++;
// 	}

// 	draw_sprites(px, py, th);
// 	mlx_put_image_to_window(mlx, window, image->image_ptr, 0, 0);
// 	return (0);
// }

// // static int get_move_offset(double th, int key, double amt, double *pdx, double *pdy)
// // {
// // 	if (key == KEY_W)
// // 	{
// // 		*pdx = 1 * amt * cos(th);
// // 		*pdy = 1 * amt * sin(th);
// // 	}
// // 	else if (key == KEY_S)
// // 	{
// // 		*pdx = (-1) * amt * cos(th);
// // 		*pdy = (-1) * amt * sin(th);
// // 	}
// // 	else if (key == KEY_A)
// // 	{
// // 		*pdx = amt * cos(th + 1 * M_PI_2);
// // 		*pdy = amt * sin(th + 1 * M_PI_2);
// // 	}
// // 	else if (key == KEY_D)
// // 	{
// // 		*pdx = amt * cos(th + (-1) * M_PI_2);
// // 		*pdy = amt * sin(th + (-1) * M_PI_2);
// // 	}
// // 	else
// // 		return (-1);
// // 	return (0);
// // }

// // int player_move(t_player *player, int key, double amt)
// // {
// // 	double dx = 0, dy = 0;
// // 	double nx, ny;

// // 	if (get_move_offset(player->th, key, amt, &dx, &dy) < 0)
// // 	{
// // 		printf("ERROR\n");
// // 		return (-1);
// // 	}
// // 	nx = player->c_x + dx;
// // 	ny = player->c_y + dy;

// // 	printf("NX : %d, NY : %d\n", (int)nx, (int)ny);
// // 	if (map_get_cell(game_info, (int)nx, (int)ny) != '0')
// // 	{
// // 		printf("**BUMP!**\n");
// // 		return (-1);
// // 	}
// // 	player->c_x = nx;
// // 	player->c_y = ny;
// // 	return (0);
// // }

// // void player_rotate(t_player *player, double th)
// // {
// // 	player->th += th;
// // 	if (player->th < 0)
// // 		player->th += _2PI;
// // 	else if (player->th > _2PI)
// // 		player->th -= _2PI;
// // }

// // int key_press(int keycode, t_player *player)
// // {
// // 	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
// // 	{
// // 		if (player_move(player, keycode, MOVE_UNIT) == 0)
// // 			render(player, game_info, &image);
// // 	}
// // 	else if (keycode == KEY_LEFT)
// // 	{
// // 		player_rotate(player, ROT_UNIT * 1);
// // 		render(player, game_info, &image);
// // 	}
// // 	else if (keycode == KEY_RIGHT)
// // 	{
// // 		player_rotate(player, ROT_UNIT * -1);
// // 		render(player, game_info, &image);
// // 	}
// // 	else if (keycode == KEY_ESC)
// // 		exit(0);
// // 	printf("PLAYER X : %f, Y : %f\n", player->c_x, player->c_y);
// // 	return (0);
// // }

// // int load_image()
// // {
// // 	int fd;
// // 	int image_width;
// // 	int image_height;

// // 	fd = open(game_info->w_image, O_RDONLY);
// // 	if (fd < 0)
// // 		return (-1);
// // 	close(fd);
// // 	w_image.image_ptr = mlx_xpm_file_to_image(mlx, game_info->w_image, &image_width, &image_height);
// // 	w_image.data = (int *)mlx_get_data_addr(w_image.image_ptr, &w_image.bpp, &w_image.size_l, &w_image.endian);

// // 	w_texture.image = &w_image;
// // 	w_texture.width = image_width;
// // 	w_texture.height = image_height;

// // 	return (0);
// // }

// // char *parse_map_line(char *line)
// // {
// // 	char *map_line;
// // 	int i;

// // 	map_line = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
// // 	if (!map_line)
// // 		return (0);
// // 	i = 0;
// // 	while (i < ft_strlen(line))
// // 	{
// // 		if (line[i] == ' ')
// // 			map_line[i] = '9';
// // 		else
// // 			map_line[i] = line[i];
// // 		i++;
// // 	}
// // 	map_line[i] = '\0';
// // 	return (map_line);
// // }

// // void print_map(char **map)
// // {
// // 	int i;

// // 	i = 0;
// // 	while (map && map[i])
// // 	{
// // 		printf("MAP[%d] : %s\n", i, map[i]);
// // 		i++;
// // 	}
// // }

// // int get_maplen(char **map)
// // {
// // 	int i;

// // 	i = 0;
// // 	while (map && map[i])
// // 		i++;
// // 	return i;
// // }

// // int parse_map(t_gameinfo *game_info, char *line)
// // {
// // 	char **temp_map;
// // 	int map_len;
// // 	int i;

// // 	map_len = get_maplen(game_info->map);
// // 	temp_map = (char **)malloc(sizeof(char *) * (map_len + 1 + 1));
// // 	if (!temp_map)
// // 		return (0);
// // 	i = 0;
// // 	while (i < map_len)
// // 	{
// // 		temp_map[i] = game_info->map[i];
// // 		i++;
// // 	}
// // 	temp_map[i] = parse_map_line(line);
// // 	temp_map[i + 1] = NULL;
// // 	if (game_info->map)
// // 		free(game_info->map);
// // 	game_info->map = temp_map;
// // 	return (0);
// // }

// // void free_command(char **command)
// // {
// // 	int i;

// // 	i = 0;
// // 	while (command && command[i])
// // 	{
// // 		free(command[i]);
// // 		i++;
// // 	}
// // 	free(command);
// // }

// // char **parse_line(t_gameinfo *game_info, char *line)
// // {
// // 	int len;
// // 	int i;
// // 	char **command;
// // 	char **rgb;

// // 	len = ft_strlen(line);
// // 	if (!len)
// // 		return (0);
// // 	command = ft_split(line, ' ');
// // 	if (ft_strncmp(command[0], "R", ft_strlen(command[0])) == 0)
// // 	{
// // 		game_info->window_w = ft_atoi(command[1]);
// // 		game_info->window_h = ft_atoi(command[2]);
// // 	}
// // 	// TODO : xpm 확장자 확인
// // 	// TODO : 파일 경로 및 위치가 유효한지 확인
// // 	else if (ft_strncmp(command[0], "NO", ft_strlen(command[0])) == 0)
// // 		game_info->n_image = ft_strdup(command[1]);
// // 	else if (ft_strlen(command[0]) == 2 && ft_strncmp(command[0], "SO", ft_strlen(command[0])) == 0)
// // 		game_info->s_image = ft_strdup(command[1]);
// // 	else if (ft_strncmp(command[0], "WE", ft_strlen(command[0])) == 0)
// // 		game_info->w_image = ft_strdup(command[1]);
// // 	else if (ft_strncmp(command[0], "EA", ft_strlen(command[0])) == 0)
// // 		game_info->e_image = ft_strdup(command[1]);
// // 	else if (ft_strncmp(command[0], "S", ft_strlen(command[0])) == 0)
// // 		game_info->sprite_image = ft_strdup(command[1]);
// // 	else if (ft_strncmp(command[0], "F", ft_strlen(command[0])) == 0)
// // 	{
// // 		rgb = ft_split(command[1], ',');
// // 		game_info->f_red = ft_atoi(rgb[0]);
// // 		game_info->f_green = ft_atoi(rgb[1]);
// // 		game_info->f_blue = ft_atoi(rgb[2]);
// // 		if (rgb)
// // 			free_command(rgb);
// // 	}
// // 	else if (ft_strncmp(command[0], "C", ft_strlen(command[0])) == 0)
// // 	{
// // 		rgb = ft_split(command[1], ',');
// // 		game_info->c_red = ft_atoi(rgb[0]);
// // 		game_info->c_green = ft_atoi(rgb[1]);
// // 		game_info->c_blue = ft_atoi(rgb[2]);
// // 		if (rgb)
// // 			free_command(rgb);
// // 	}
// // 	else
// // 		parse_map(game_info, line);
// // 	if (command)
// // 		free_command(command);
// // 	return (0);
// // }

// // int parse_game(t_gameinfo *game_info, int fd)
// // {
// // 	char *line;

// // 	printf("fd: %d\n", fd);
// // 	while (get_next_line(fd, &line))
// // 	{
// // 		parse_line(game_info, line);
// // 		if (line)
// // 			free(line);
// // 	}
// // 	if (line)
// // 		free(line);
// // 	return (1);
// // }

// /***************LINE******************/
