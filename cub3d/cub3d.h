#ifndef CUB3D_H
	#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./mlx/mlx.h"
#include <math.h>
#include <fcntl.h>

typedef	struct	s_gameinfo
{
	int			window_w;
	int			window_h;
	char		*n_image;
	char		*s_image;
	char		*w_image;
	char		*e_image;
	char		*sprite_image;
	int			*f_red;
	int			*f_green;
	int			*f_blue;
	int			*c_red;
	int			*c_green;
	int			*c_blue;
}				t_gameinfo;

typedef	struct	s_player
{
	double		c_x;
	double		c_y;
	double		dir_x;
	double		dir_y;
	double		n_x;
	double		n_y;
	double		move_speed;
	double		rot_speed;
}			t_player;


#endif
