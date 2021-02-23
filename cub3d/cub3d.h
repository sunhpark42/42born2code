#ifndef CUB3D_H
	#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./mlx/mlx.h"
#include <math.h>
#include <fcntl.h>

/* DELETE AFTER */
#include "get_next_line.h"
#include "./utils/libft.h"

/* KEY CONSTANTS */
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

/* MAC KEY CODE */
# define KEY_ESC				53
# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_R					15
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define KEY_LEFT				123
# define KEY_RIGHT				124

/* RAY CASTING CONSTANTS */
# define EPS					(1e-06)
# define IS_ZERO(d)				(fabs(d) < EPS)
# define DEG2RAD(d)				((d) * M_PI / 180.0)
# define RAD2DEG(d)				((d) * 180.0 / M_PI)
# define MIN(a, b)				((a) < (b) ? (a) : (b))
# define MAX(a, b)				((a) > (b) ? (a) : (b))

# define SX						720
# define SY						480
/* filed of view */
# define FOV					60
# define FOV_H					DEG2RAD(FOV)
# define FOV_V					(FOV_H * (double)SY / (double)SX)

# define WALL_H					1.0
# define WALL_V					1.0

# define _2PI       6.28318530717958647692 /* 2 * MPI */
# define ROT_UNIT				0.03
# define MOVE_UNIT				0.1

# define PL_RADIUS						1

static const double ANGLE_PER_PIXEL = FOV_H / (SX - 1. );
static const double FOVH_2 = FOV_H / 2.0;

enum { VERT, HORIZ };

typedef enum { false = 0, true = 1 } t_bool;
typedef enum { DIR_N = 0, DIR_E, DIR_W, DIR_S } t_dir;

typedef struct s_sprite
{
	int			tex;
	int			x, y;
	double		dist;
	double		th;
} t_sprite;

typedef	struct	s_gameinfo
{
	int			window_w;
	int			window_h;
	char		*n_image;
	char		*s_image;
	char		*w_image;
	char		*e_image;
	char		*sprite_image;
	int			f_red;
	int			f_green;
	int			f_blue;
	int			c_red;
	int			c_green;
	int			c_blue;
	char		**map;
}				t_gameinfo;

typedef	struct	s_player
{
	double		c_x;
	double		c_y;
	double		th;
	double		dir_x;
	double		dir_y;
	double		n_x;
	double		n_y;
	double		move_speed;
	double		rot_speed;
}			t_player;

/* mlx Image */
typedef struct	s_image
{
	void		*image_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_image;

typedef struct s_texture
{
	t_image		*image;
	int			width;
	int			height;
}				t_texture;

#endif
