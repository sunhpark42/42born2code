#include "cub3d.h"

void init_gameinfo(t_gameinfo *game_info)
{
  game_info->window_w = 0;
  game_info->window_h = 0;
  game_info->n_image = NULL;
  game_info->s_image = NULL;
  game_info->w_image = NULL;
  game_info->e_image = NULL;
  game_info->sprite_image = NULL;
  game_info->f_red = 0;
  game_info->f_green = 0;
  game_info->f_blue = 0;
  game_info->c_red = 0;
  game_info->c_green = 0;
  game_info->c_blue = 0;
  game_info->map = NULL;
}

void init_player(t_player *player)
{
  player->x = 0;
  player->y = 0;
  player->th = 0;
  player->move_speed = 0;
  player->rot_speed = 0;
}

void init_texture(t_texture *texture)
{
  texture->image = (t_image *)malloc(sizeof(t_image) * 1);
}

void init_mlx(t_mlx *mlx)
{
  mlx->mlx = mlx_init();
  mlx->window = NULL;
  mlx->canvas = (t_image *)malloc(sizeof(t_image) * 1);
  mlx->ray = (t_ray *)malloc(sizeof(t_ray) * 1);
  mlx->ray->wdir = (t_dir *)malloc(sizeof(t_dir) * 1);
  mlx->game_info = (t_gameinfo *)malloc(sizeof(t_gameinfo) * 1);
  if (!mlx->game_info)
    print_error("cannot assign gameinfo");
  mlx->player = (t_player *)malloc(sizeof(t_player) * 1);
  if (!mlx->player)
    print_error("cannot assign player");
  init_gameinfo(mlx->game_info);
  init_player(mlx->player);
  mlx->n_texture = (t_texture *)malloc(sizeof(t_texture) * 1);
  mlx->s_texture = (t_texture *)malloc(sizeof(t_texture) * 1);
  mlx->w_texture = (t_texture *)malloc(sizeof(t_texture) * 1);
  mlx->e_texture = (t_texture *)malloc(sizeof(t_texture) * 1);
  init_texture(mlx->n_texture);
  init_texture(mlx->s_texture);
  init_texture(mlx->w_texture);
  init_texture(mlx->e_texture);
}