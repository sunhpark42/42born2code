#include "cub3d.h"

int parse_game(t_gameinfo *game_info, int fd)
{
  char *line;

  while (get_next_line(fd, &line))
  {
    parse_line(game_info, line);
    if (line)
      free(line);
  }
  if (line)
    free(line);
  return (1);
}

char **parse_line(t_gameinfo *game_info, char *line)
{
  char **command;

  if (!ft_strlen(line))
    return (0);
  command = ft_split(line, ' ');
  // TODO : 필요한 요소 개수가 맞는지 확인, null 일 수 있음. 근데 25줄 딱임.
  if (ft_strncmp(command[0], "R", ft_strlen(command[0])) == 0)
    set_window(game_info, command[1], command[2]);
  else if (ft_strncmp(command[0], "NO", ft_strlen(command[0])) == 0)
    game_info->n_image = get_image_url(command[1]);
  else if (ft_strlen(command[0]) == 2 && ft_strncmp(command[0], "SO", ft_strlen(command[0])) == 0)
    game_info->s_image = get_image_url(command[1]);
  else if (ft_strncmp(command[0], "WE", ft_strlen(command[0])) == 0)
    game_info->w_image = get_image_url(command[1]);
  else if (ft_strncmp(command[0], "EA", ft_strlen(command[0])) == 0)
    game_info->e_image = get_image_url(command[1]);
  else if (ft_strncmp(command[0], "S", ft_strlen(command[0])) == 0)
    game_info->sprite_image = get_image_url(command[1]);
  else if (ft_strncmp(command[0], "F", ft_strlen(command[0])) == 0)
    set_color(game_info, 'F', command[1]);
  else if (ft_strncmp(command[0], "C", ft_strlen(command[0])) == 0)
    set_color(game_info, 'C', command[1]);
  else
    parse_map(game_info, line);
  if (command)
    free_string_array(command);
  return (0);
}

int parse_map(t_gameinfo *game_info, char *line)
{
  char **temp_map;
  int map_len;
  int i;

  map_len = get_maplen(game_info->map);
  temp_map = (char **)malloc(sizeof(char *) * (map_len + 1 + 1));
  if (!temp_map)
    return (0);
  i = 0;
  while (i < map_len)
  {
    temp_map[i] = game_info->map[i];
    i++;
  }
  temp_map[i] = parse_map_line(line);
  temp_map[i + 1] = NULL;
  if (game_info->map)
    free(game_info->map);
  game_info->map = temp_map;
  return (0);
}

char *parse_map_line(char *line)
{
  char *map_line;
  int i;

  map_line = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
  if (!map_line)
    return (0);
  i = 0;
  while (i < ft_strlen(line))
  {
    if (line[i] == ' ')
      map_line[i] = '9';
    else
      map_line[i] = line[i];
    i++;
  }
  map_line[i] = '\0';
  return (map_line);
}
