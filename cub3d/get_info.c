#include "cub3d.h"

char *get_image_url(char *line)
{
  if (!is_xpm(line))
    print_error("Not .xpm format");
  if (!is_exist(line))
    print_error("Does not exist");
  return (ft_strdup(line));
}

void set_color(t_gameinfo *game_info, char position, char *line)
{
  char **rgb;
  rgb = ft_split(line, ',');
  if (!rgb)
    print_error("COLOR ASSIGN ERROR");
  if (position == 'F')
  {
    game_info->f_red = ft_atoi(rgb[0]);
    game_info->f_green = ft_atoi(rgb[1]);
    game_info->f_blue = ft_atoi(rgb[2]);
  }
  if (position == 'C')
  {
    game_info->c_red = ft_atoi(rgb[0]);
    game_info->c_green = ft_atoi(rgb[1]);
    game_info->c_blue = ft_atoi(rgb[2]);
  }
  if (rgb)
    free_string_array(rgb);
}

void set_window(t_gameinfo *game_info, char *width, char *height)
{
  game_info->window_w = ft_atoi(width);
  game_info->window_h = ft_atoi(height);
}

void set_player(t_player *player, int x, int y, double th)
{
  player->x = x;
  player->y = y;
  player->th = th;
}

void get_player_position(t_mlx *mlx)
{
  int x;
  int y;
  char **map;

  y = 0;
  map = mlx->game_info->map;
  while (map && map[y])
  {
    x = 0;
    while (map[y][x])
    {
      if (map[y][x] == 'N')
        set_player(mlx->player, x, y, 90);
      if (map[y][x] == 'S')
        set_player(mlx->player, x, y, 270);
      if (map[y][x] == 'W')
        set_player(mlx->player, x, y, 180);
      if (map[y][x] == 'E')
        set_player(mlx->player, x, y, 0);
      x++;
    }
    y++;
  };
}