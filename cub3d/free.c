#include "cub3d.h"

void free_string_array(char **array)
{
  int i;

  i = 0;
  while (array && array[i])
  {
    free(array[i]);
    i++;
  }
  free(array);
}

void free_info(t_gameinfo *game_info)
{
  if (game_info->map)
    freemap(game_info);
  if (game_info->n_image)
    free(game_info->n_image);
  if (game_info->s_image)
    free(game_info->s_image);
  if (game_info->w_image)
    free(game_info->w_image);
  if (game_info->e_image)
    free(game_info->e_image);
  if (game_info->sprite_image)
    free(game_info->sprite_image);
  free(game_info);
}

void freemap(t_gameinfo *game_info)
{
  int i;

  i = 0;
  while (game_info->map && game_info->map[i])
  {
    free(game_info->map[i]);
    i++;
  }
  free(game_info->map);
}
