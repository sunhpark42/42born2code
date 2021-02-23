#include "cub3d.h"

// void draw_line(t_image *image, t_gameinfo *game_info, double x1, double y1, double x2, double y2, int color)
void draw_line(t_mlx *mlx, double x, double y1, double y2, int color)
{
  double delta_y;
  double step;

  delta_y = y2 - y1;
  step = fabs(delta_y);
  delta_y /= step;
  while (fabs(y2 - y1) > 0.01)
  {
    mlx->canvas->data[((int)floor(y1) * mlx->game_info->window_w + (int)floor(x))] = color;
    y1 += delta_y;
  }
}

void draw_horiz_line(t_mlx *mlx, double y, double x1, double x2, int color)
{
  double delta_x;
  double step;

  delta_x = x2 - x1;
  step = fabs(delta_x);
  delta_x /= step;
  while (fabs(x2 - x1) > 0.01)
  {
    mlx->canvas->data[((int)floor(y) * mlx->game_info->window_w + (int)floor(x1))] = color;
    x1 += delta_x;
  }
}

void fill_window(t_mlx *mlx, int color)
{
  double x;
  double width;
  double height;

  width = (double)(mlx->game_info->window_w);
  height = (double)(mlx->game_info->window_h);
  x = 0;
  while (x < width)
  {
    draw_line(mlx, x, 0, height, color);
    x++;
  }
}