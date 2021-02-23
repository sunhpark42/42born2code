#include "cub3d.h"

int get_maplen(char **map)
{
  int i;

  i = 0;
  while (map && map[i])
    i++;
  return i;
}