#include "cub3d.h"

void set_ray(t_ray *ray, t_intersection *inter)
{
  if (inter->hit_side == VERT)
  {
    *ray->wdir = (inter->xstep > 0) ? DIR_W : DIR_E;
    ray->wall_x = inter->nx;
    ray->wall_y = inter->f;
  }
  else
  {
    *ray->wdir = (inter->ystep > 0) ? DIR_S : DIR_N;
    ray->wall_x = inter->g;
    ray->wall_y = inter->ny;
  }
}

void set_hit_side(t_mlx *mlx, t_intersection *inter, int *mapx, int *mapy)
{
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
  //   *mapx = (inter->xstep == 1) ? (int)(inter->nx) : (int)(inter->nx) - 1;
  //   *mapy = (int)inter->f;
  //   inter->hit_side = VERT;
  //   printf("V(%d, %2.f) -> ", *mapx, inter->f);
  // }
  // else
  // {
  //   *mapx = (int)inter->g;
  //   *mapy = (inter->ystep == 1) ? (int)(inter->ny) : (int)(inter->ny) - 1;
  //   inter->hit_side = HORIZ;
  //   printf("V(%2.f, %d) -> ", inter->g, *mapy);
  // }
}

void init_intersection(t_mlx *mlx, t_intersection *inter)
{
  inter->xstep = sign(cos(mlx->ray->th)); /* +1 right , 0 no change */
  inter->ystep = sign(sin(mlx->ray->th)); /* +1 up, 0 no change */

  inter->nx = (inter->xstep > 0 ? floor(mlx->player->x) + 1 : ((inter->xstep < 0) ? ceil(mlx->player->x) - 1 : mlx->player->x));
  inter->ny = (inter->ystep > 0 ? floor(mlx->player->y) + 1 : ((inter->ystep < 0) ? ceil(mlx->player->y) - 1 : mlx->player->y));

  inter->f = INFINITY;
  inter->g = INFINITY;

  inter->hit = false;
}