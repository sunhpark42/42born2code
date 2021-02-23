#include "cub3d.h"

t_bool is_validate_map(t_gameinfo *game_info)
{
  if (!is_all_elements_valid(game_info))
    return (false);
  if (!is_only_one_player(game_info))
    return (false);
  if (!is_map_surrounded(game_info))
    return (false);

  return (true);
}

t_bool is_map_surrounded(t_gameinfo *game_info)
{
  int x;
  int y;

  y = 0;
  while (game_info->map && game_info->map[y])
  {
    x = 0;
    while (game_info->map[y][x])
    {
      if (ft_strchr("02NSWE", game_info->map[y][x]) != 0)
      {
        if ((y >= 0 && game_info->map[y - 1][x] == '9') || (y < get_maplen(game_info->map) - 1 && game_info->map[y + 1][x] == '9'))
          return (false);
        if ((x >= 0 && game_info->map[y][x - 1] == '9') || (x < ft_strlen(game_info->map[y]) - 1 && game_info->map[y][x + 1] == '9'))
          return (false);
        if (y == 0 || x == 0 || y == get_maplen(game_info->map) - 1 || x == ft_strlen(game_info->map[y]) - 1)
          return (false);
      }
      x++;
    }
    y++;
  }
  return (true);
}

t_bool is_all_elements_valid(t_gameinfo *game_info)
{
  int x;
  int y;
  char **map;

  map = game_info->map;
  y = 0;
  while (map && map[y])
  {
    x = 0;
    while (map[y][x])
    {
      if (ft_strchr("012NSEW9", map[y][x]) == 0)
        return (false);
      x++;
    }
    y++;
  }
  return (true);
}

t_bool is_only_one_player(t_gameinfo *game_info)
{
  int x;
  int y;
  int player;
  char **map;

  map = game_info->map;
  player = 0;
  y = 0;
  while (map && map[y])
  {
    x = 0;
    while (map[y][x])
    {
      if (ft_strchr("NSEW", map[y][x]) != 0)
        player++;
      x++;
    }
    y++;
  }
  if (player != 1)
    return (false);
  return (true);
}