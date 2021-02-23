#include "cub3d.h"

void print_char_array(char *arr)
{
  int i;

  i = 0;
  while (i < ft_strlen(arr))
  {
    printf("%c ", arr[i]);
    i++;
  }
  printf("\n");
}

void print_map(char **map)
{
  int i;

  i = 0;
  while (map && map[i])
  {
    printf("MAP[%d] : %s\n", i, map[i]);
    i++;
  }
}

void print_gameinfo(t_gameinfo *game_info)
{
  printf("window_w : %d\n", game_info->window_w);
  printf("window_h : %d\n", game_info->window_h);
  printf("n_image : %s\n", game_info->n_image);
  printf("s_image : %s\n", game_info->s_image);
  printf("w_image : %s\n", game_info->w_image);
  printf("e_image : %s\n", game_info->e_image);
  printf("sprite_image : %s\n", game_info->sprite_image);
  printf("f_red : %d\n", game_info->f_red);
  printf("f_green : %d\n", game_info->f_green);
  printf("f_blue : %d\n", game_info->f_blue);
  printf("c_red : %d\n", game_info->c_red);
  printf("c_green : %d\n", game_info->c_green);
  printf("c_blue : %d\n", game_info->c_blue);
  printf("-----------------MAP-------------------\n");
  print_map(game_info->map);
  printf("-----------------MAP_END-----------------\n");
}

void print_player(t_player *player)
{
  printf("x : %f\n", player->x);
  printf("y : %f\n", player->y);
  printf("move_speed : %f\n", player->move_speed);
  printf("rot_speed : %f\n", player->rot_speed);
}