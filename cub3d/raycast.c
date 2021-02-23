#include "cub3d.h"

char map_get_cell(t_gameinfo *game_info, int x, int y)
{
  char **map;

  map = game_info->map;
  if (x >= 0 && y >= 0 && y < get_maplen(map) && x < ft_strlen(map[y]))
    return (map[y][x]);
  return ('e');
}

// x : 현재 빛을 쏜 x 좌표
double cast_single_ray(t_mlx *mlx, t_intersection *inter, int x)
{
  mlx->ray->th = (mlx->player->th + FOV_H) - (x * ANGLE_PER_PIXEL);

  if (get_wall_intersection(mlx, inter) == false)
    return INFINITY; /* no intersection */

  // double xslope = (inter->xstep == 0 ? INFINITY : tan(mlx->ray->th));
  // double yslope = (inter->ystep == 0 ? INFINITY : 1.0 / tan(mlx->ray->th));
  // if (inter->xstep != 0)
  //   inter->f = xslope * (inter->nx - mlx->player->x) + mlx->player->y;
  // if (inter->ystep != 0)
  //   inter->g = yslope * (inter->ny - mlx->player->y) + mlx->player->x;

  // double dist_v = l2dist(mlx->player->x, mlx->player->y, inter->nx, inter->f);
  // double dist_h = l2dist(mlx->player->x, mlx->player->y, inter->g, inter->ny);

  // /* VERT IS NEARER */
  // if (dist_v < dist_h)
  // {
  //   mapx = (inter->xstep == 1) ? (int)(inter->nx) : (int)(inter->nx) - 1;
  //   mapy = (int)inter->f;
  //   inter->hit_side = VERT;
  //   printf("V(%d, %2.f) -> ", mapx, inter->f);
  // }
  // else
  // {
  //   mapx = (int)inter->g;
  //   mapy = (inter->ystep == 1) ? (int)(inter->ny) : (int)(inter->ny) - 1;
  //   inter->hit_side = HORIZ;
  //   printf("V(%2.f, %d) -> ", inter->g, mapy);
  // }

  printf("DIR : %d\n", *(mlx->ray->wdir));
  // if (*(mlx->ray->wdir) == 0 || *(mlx->ray->wdir) == 3)
  //   mlx->ray->w_ratio = mlx->ray->wall_x - floor(mlx->ray->wall_x);
  // else
  //   mlx->ray->w_ratio = mlx->ray->wall_y - floor(mlx->ray->wall_y);

  /* 보정 */
  mlx->ray->w_dist = l2dist(mlx->player->x, mlx->player->y, mlx->ray->wall_x, mlx->ray->wall_y);
  mlx->ray->w_dist *= cos(mlx->player->th - mlx->ray->th);

  return mlx->ray->w_dist;
}

t_bool get_wall_intersection(t_mlx *mlx, t_intersection *inter)
{
  double xstep = sign(cos(mlx->ray->th));
  double ystep = sign(sin(mlx->ray->th));

  double xslope = (xstep == 0) ? INFINITY : tan(mlx->ray->th);
  double yslope = (ystep == 0) ? INFINITY : 1. / tan(mlx->ray->th);

  inter->nx = (xstep > 0) ? floor(mlx->player->x) + 1 : ((xstep < 0) ? ceil(mlx->player->x) - 1 : mlx->player->x);
  inter->ny = (ystep > 0) ? floor(mlx->player->y) + 1 : ((ystep < 0) ? ceil(mlx->player->y) - 1 : mlx->player->y);

  inter->f = INFINITY;
  inter->g = INFINITY;
  inter->hit = false;

  while (!inter->hit)
  {
    int mapx;
    int mapy;
    if (inter->xstep != 0)
      inter->f = xslope * (inter->nx - mlx->player->x) + mlx->player->y;
    if (inter->ystep != 0)
      inter->g = yslope * (inter->ny - mlx->player->y) + mlx->player->x;

    double dist_v = l2dist(mlx->player->x, mlx->player->y, inter->nx, inter->f);
    double dist_h = l2dist(mlx->player->x, mlx->player->y, inter->g, inter->ny);
    // set_hit_side(mlx, inter, &mapx, &mapy);
    /* VERT IS NEARER */
    if (dist_v < dist_h)
    {
      mapx = (inter->xstep == 1) ? (int)(inter->nx) : (int)(inter->nx) - 1;
      mapy = (int)inter->f;
      inter->hit_side = VERT;
      printf("V(%d, %2.f) -> ", mapx, inter->f);
    }
    else
    {
      mapx = (int)inter->g;
      mapy = (inter->ystep == 1) ? (int)(inter->ny) : (int)(inter->ny) - 1;
      inter->hit_side = HORIZ;
      printf("V(%2.f, %d) -> ", inter->g, mapy);
    }

    inter->cell = map_get_cell(mlx->game_info, mapx, mapy);

    if (inter->cell == 'e')
      break; /* out of range */
    if (inter->cell == '1')
    {
      if (inter->hit_side == VERT)
      {
        *mlx->ray->wdir = (xstep > 0) ? DIR_W : DIR_E;
        mlx->ray->wall_x = inter->nx;
        mlx->ray->wall_y = inter->f;
      }
      else
      {
        *mlx->ray->wdir = (ystep > 0) ? DIR_S : DIR_N;
        mlx->ray->wall_x = inter->g;
        mlx->ray->wall_y = inter->ny;
      }
      // set_ray(mlx->ray, inter);
      inter->hit = true;
      printf("HIT!!!!!!!!!!WALL!!!!!!!!!!\n");
      break;
    }
    if (inter->hit_side == VERT)
      inter->nx += xstep;
    else
      inter->ny += ystep;
  }
  return inter->hit;
}