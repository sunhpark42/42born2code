#include "cub3d.h"

char map_get_cell(t_gameinfo *game_info, int x, int y)
{
  char **map;

  map = game_info->map;
  if (x >= 0 && y >= 0 && y < get_maplen(map) && x < ft_strlen(map[y]))
    return (map[y][x]);
  return (-1);
}

// x : 현재 빛을 쏜 x 좌표
double cast_single_ray(t_mlx *mlx, t_intersection *inter, int x)
{
  mlx->ray->th = (mlx->player->th + get_fovh_2(get_fovh())) - (x * get_angle_per_pixel(get_fovh(), mlx->game_info->window_w));

  if (get_wall_intersection(mlx, inter) == false)
    return INFINITY; /* no intersection */

  printf("DIR : %d\n", *(mlx->ray->wdir));
  mlx->ray->w_dist = l2dist(mlx->player->x, mlx->player->y, mlx->ray->wall_x, mlx->ray->wall_y);
  if (*(mlx->ray->wdir) == 0 || *(mlx->ray->wdir) == 3)
    mlx->ray->w_ratio = mlx->ray->wall_x - floor(mlx->ray->wall_x);
  else
    mlx->ray->w_ratio = mlx->ray->wall_y - floor(mlx->ray->wall_y);

  /* 보정 */
  mlx->ray->w_dist *= cos(mlx->player->th - mlx->ray->th);

  return mlx->ray->w_dist;
}

t_bool get_wall_intersection(t_mlx *mlx, t_intersection *inter)
{
  int mapx;
  int mapy;
  while (!inter->hit)
  {
    set_hit_side(mlx, inter, &mapx, &mapy);
    inter->cell = map_get_cell(mlx->game_info, mapx, mapy);
    if (inter->cell < 0)
      break; /* out of range */
    if (inter->cell == '1')
    {
      set_ray(mlx->ray, inter);
      inter->hit = true;
      printf("HIT!!!!!!!!!!WALL!!!!!!!!!!\n");
      break;
    }
    if (inter->hit_side == VERT)
      inter->nx += inter->xstep;
    else
      inter->ny += inter->ystep;
  }
  return inter->hit;
}