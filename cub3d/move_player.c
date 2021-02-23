#include "cub3d.h"

int key_press(int keycode, t_mlx *mlx)
{
  if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
  {
    if (player_move(mlx, keycode, MOVE_UNIT) == 0)
      render(mlx);
  }
  else if (keycode == KEY_LEFT)
  {
    player_rotate(mlx, ROT_UNIT * 1);
    render(mlx);
  }
  else if (keycode == KEY_RIGHT)
  {
    player_rotate(mlx, ROT_UNIT * -1);
    render(mlx);
  }
  else if (keycode == KEY_ESC)
    exit(0);
  return (0);
}

void player_rotate(t_mlx *mlx, double th)
{
  mlx->player->th += th;
  if (mlx->player->th < 0)
    mlx->player->th += _2PI;
  else if (mlx->player->th > _2PI)
    mlx->player->th -= _2PI;
}

int player_move(t_mlx *mlx, int key, double amt)
{
  t_moveoffset *offset;

  offset = (t_moveoffset *)malloc(sizeof(t_moveoffset));
  if (!offset)
    print_error("OFFSET ASSIGN ERROR");

  offset->dx = 0;
  offset->dy = 0;
  // cannot move
  if (get_move_offset(mlx->player->th, key, amt, offset) < 0)
    return (-1);
  offset->nx = mlx->player->x + offset->dx;
  offset->ny = mlx->player->y + offset->dy;

  if (map_get_cell(mlx->game_info, (int)offset->nx, (int)offset->ny) != '0')
  {
    printf("**BUMP!**\n");
    return (-1);
  }
  mlx->player->x = offset->nx;
  mlx->player->y = offset->ny;
  return (0);
}

int get_move_offset(double th, int key, double amt, t_moveoffset *offset)
{
  if (key == KEY_W)
  {
    offset->dx = 1 * amt * cos(th);
    offset->dy = 1 * amt * sin(th);
  }
  else if (key == KEY_S)
  {
    offset->dx = (-1) * amt * cos(th);
    offset->dy = (-1) * amt * sin(th);
  }
  else if (key == KEY_A)
  {
    offset->dx = amt * cos(th + 1 * M_PI_2);
    offset->dy = amt * sin(th + 1 * M_PI_2);
  }
  else if (key == KEY_D)
  {
    offset->dx = amt * cos(th + (-1) * M_PI_2);
    offset->dy = amt * sin(th + (-1) * M_PI_2);
  }
  else
    return (-1);
  return (0);
}
