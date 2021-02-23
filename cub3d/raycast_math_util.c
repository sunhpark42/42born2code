#include "cub3d.h"

int get_wall_height(double dist, double height, double fovv)
{
  double fov_h;
  fov_h = 2.0 * dist * tan(FOV_V / 2.0);
  return (int)(height * (WALL_H / fov_h));
}

double get_angle_per_pixel(double fov_h, double screen_witdh)
{
  return (FOV_H / (screen_witdh - 1.0));
}

double get_fovh_2(double fov_h)
{
  return (FOV_H / 2.0);
}

double get_fov_min_dist(t_gameinfo *game_info) /* distance to the floor-FOV intersection point */
{
  static double t = -1;
  if (t < 0)
    t = WALL_H / (2.0 * tan(get_fovv(get_fovh(), game_info->window_w, game_info->window_h) / 2.0));
  return t;
}