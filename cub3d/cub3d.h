#ifndef CUB3D_H
#define CUB3D_H

/*
** needed header
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./mlx/mlx.h"
#include <math.h>
#include <fcntl.h>

/*
** gnl, libft header
*/
#include "get_next_line.h"
#include "./utils/libft.h"

/*
** KEY CONSTANTS
*/
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17

/*
** MAC KEY CODE
*/
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_LEFT 123
#define KEY_RIGHT 124

#define KEY_Q 12
#define KEY_E 14
#define KEY_R 15

/* RAY CASTING CONSTANTS */
#define EPS (1e-06)
// #define IS_ZERO(d) (fabs(d) < EPS) // util 로 분리.
// #define DEG2RAD(d) ((d)*M_PI / 180.0) // util 로 분리.
// #define RAD2DEG(d) ((d)*180.0 / M_PI) // util 로 분리.
// #define MIN(a, b) ((a) < (b) ? (a) : (b)) // util로 분리
// #define MAX(a, b) ((a) > (b) ? (a) : (b)) // util로 분리

/*
** window x, windoy y 와 같음
*/
// #define SX 720
// #define SY 480

/*
** Filed of view
** TODO : 나중에 utils 로 변경하기
*/
#define FOV 60
// #define FOV_H DEG2RAD(FOV) // util로 분리
// #define FOV_V (FOV_H * (double)SY / (double)SX) // util로 분리

#define WALL_H 1.0

#define _2PI 6.28318530717958647692 /* 2 * MPI */

// static const double ANGLE_PER_PIXEL = FOV_H / (SX - 1.); // util로 분리
// static const double FOVH_2 = FOV_H / 2.0; // util로 분리

enum
{
	VERT,
	HORIZ
};

/*
** boolean
*/
typedef enum
{
	false = 0,
	true = 1
} t_bool;

typedef enum
{
	DIR_N = 0,
	DIR_E,
	DIR_W,
	DIR_S
} t_dir;

/*
** Information for Game setting like window size, images, color, map
** wsad_image : String (URL)
*/
typedef struct s_gameinfo
{
	int window_w;
	int window_h;
	char *n_image;
	char *s_image;
	char *w_image;
	char *e_image;
	char *sprite_image;
	int f_red;
	int f_green;
	int f_blue;
	int c_red;
	int c_green;
	int c_blue;
	char **map;
} t_gameinfo;

/*
** Information for Player like location, tanh, move_speed, rot_speed;
*/
#define ROT_UNIT 0.1
#define MOVE_UNIT 0.1

typedef struct s_player
{
	double x; // c_x -> x
	double y; // c_y -> y
	double th;
	double move_speed;
	double rot_speed;
} t_player;

/*
** Mlx Basic Image Unit
*/
typedef struct s_image
{
	void *image; // image_ptr -> image
	int *data;
	int size_l;
	int bpp;
	int endian;
} t_image;

/*
** Texture
*/
typedef struct s_texture
{
	t_image *image;
	int width;
	int height;
} t_texture;

/*
** ray
*/
typedef struct s_ray
{
	double th;
	double wall_x;
	double wall_y;
	t_dir *wdir;
	double w_ratio;
	double w_dist;
} t_ray;

/*
** MLX information
** mlx pointer
** window pointer
** game_info
** player
** wsad_texture
*/
typedef struct s_mlx
{
	void *mlx;
	void *window;
	t_image *canvas;
	t_ray *ray;
	t_gameinfo *game_info;
	t_player *player;
	t_texture *n_texture;
	t_texture *s_texture;
	t_texture *e_texture;
	t_texture *w_texture;
} t_mlx;

/*
** struct for Equation
*/
typedef struct s_intersection
{
	int xstep;
	int ystep;
	double nx;
	double ny;
	double f;
	double g;
	t_bool hit;
	int hit_side;
	char cell;
} t_intersection;

typedef struct s_moveoffset
{
	double dx;
	double dy;
	double nx;
	double ny;
} t_moveoffset;

/*
** Error Handling
*/
void print_error(char *error_msg);

/*
** initation
*/
void init_gameinfo(t_gameinfo *game_info);
void init_player(t_player *player);
void init_mlx(t_mlx *mlx);

/*
** print Utils
*/
void print_char_array(char *arr);
void print_map(char **map);
void print_gameinfo(t_gameinfo *game_info);
void print_player(t_player *player);

/*
** Parsing Function
*/
int parse_game(t_gameinfo *game_info, int fd);
char **parse_line(t_gameinfo *game_info, char *line);
int parse_map(t_gameinfo *game_info, char *line);
char *parse_map_line(char *line);

/*
** get/set information from .cub
*/
char *get_image_url(char *line);
void set_color(t_gameinfo *game_info, char position, char *line);
void set_window(t_gameinfo *game_info, char *width, char *height);
void set_player(t_player *player, int x, int y, double th);
void get_player_position(t_mlx *mlx);

/*
** validator_utils
*/
t_bool is_xpm(char *line);
t_bool is_exist(char *line);

/*
** validate_map
*/
t_bool is_validate_map(t_gameinfo *game_info);
t_bool is_map_surrounded(t_gameinfo *game_info);
t_bool is_all_elements_valid(t_gameinfo *game_info);
t_bool is_only_one_player(t_gameinfo *game_info);

/*
** free
*/
void free_string_array(char **array);
void free_info(t_gameinfo *game_info);
void freemap(t_gameinfo *game_info);

/*
** image utils
*/
void load_textures(t_mlx *mlx);
int load_texture(t_mlx *mlx, t_texture *texture, char *src);
t_image *create_image(t_mlx *mlx, int width, int height);

/*
** math utils
*/
int sign(double num);
double l2dist(double x0, double y0, double x1, double y1);
double max(double a, double b);
double min(double a, double b);

t_bool is_zero(double num);
double deg_to_rad(double num);
double rad_to_deg(double num);
double get_fovh(void);
double get_fovv(double fovh, double width, double height);

/*
** raycasting math utils
*/

int get_wall_height(double dist, double height, double fovv);
double get_angle_per_pixel(double fov_h, double screen_witdh);
double get_fovh_2(double fov_h);
double get_fov_min_dist(t_gameinfo *game_info);

/*
** raycasting utils
*/
char map_get_cell(t_gameinfo *game_info, int x, int y);

double cast_single_ray(t_mlx *mlx, t_intersection *inter, int x);
t_bool get_wall_intersection(t_mlx *mlx, t_intersection *inter);

/*
** set ray value
*/
void set_ray(t_ray *ray, t_intersection *inter);
void set_hit_side(t_mlx *mlx, t_intersection *inter, int *mapx, int *mapy);
void init_intersection(t_mlx *mlx, t_intersection *inter);

/*
** move player
*/
int key_press(int keycode, t_mlx *mlx);
void player_rotate(t_mlx *mlx, double th);
int player_move(t_mlx *mlx, int key, double amt);
int get_move_offset(double th, int key, double amt, t_moveoffset *offset);

/*
** map util
*/
int get_maplen(char **map);

/*
** draw Canvas
*/
int render(t_mlx *mlx);

#endif