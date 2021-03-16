#include "cub3d.h"

void error(char *msg)
{
  printf("%s\n", msg);
  exit(0);
}

int count_command(char **command)
{
  int x;

  x = 0;
  while (command && command[x])
    x++;
  return (x);
}

int get_maplen(char **map)
{
  int x;

  x = 0;
  while (map && map[x])
    x++;
  return (x);
}

void free_command(char **command)
{
  int i;

  i = 0;
  while (command && command[i])
  {
    free(command[i]);
    i++;
  }
  free(command);
}

void set_window_size(t_cub *cub, char *width, char *height)
{
  if (width <= 0 || height <= 0)
    error("WINDOW SIZE PARSING ERROR");
  cub->game_info->window_w = ft_atoi(width);
  cub->game_info->window_h = ft_atoi(height);
}

t_bool is_xpm(char *url)
{
  int len;

  len = ft_strlen(url);
  if (len > 4 && url[len - 4] == '.' && url[len - 3] == 'x' && url[len - 2] == 'p' && url[len - 1] == 'm')
    return (true);
  return (false);
}

void set_image_url(t_cub *cub, char *url, int item)
{
  int fd;

  if (!is_xpm(url))
    error("NOT .XPM Format");
  fd = open(url, O_RDONLY);
  if (fd < 0)
    error("CANNOT OPEN URL");
  close(fd);

  cub->textures[item] = new_texture();
  cub->textures[item]->image->image_ptr = mlx_xpm_file_to_image(cub->mlx, url, &cub->textures[item]->width, &cub->textures[item]->height);
  cub->textures[item]->image->data = (int *)mlx_get_data_addr(cub->textures[item]->image->image_ptr, &cub->textures[item]->image->bpp, &cub->textures[item]->image->size_l, &cub->textures[item]->image->endian);
}

void set_color(t_cub *cub, char *rgb, int position)
{
  char **rgb_array;

  rgb_array = ft_split(rgb, ',');
  if (count_command(rgb_array) != 3)
    error("RGB NUMBER ERROR");
  if (position == FLOOR)
  {
    cub->game_info->floor[0] = ft_atoi(rgb_array[0]);
    cub->game_info->floor[1] = ft_atoi(rgb_array[1]);
    cub->game_info->floor[2] = ft_atoi(rgb_array[2]);
  }
  else if (position == CEIL)
  {
    cub->game_info->ceil[0] = ft_atoi(rgb_array[0]);
    cub->game_info->ceil[1] = ft_atoi(rgb_array[1]);
    cub->game_info->ceil[2] = ft_atoi(rgb_array[2]);
  }

  if (rgb_array)
    free_command(rgb_array);
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

void parse_map(t_cub *cub, char *line)
{
  char **temp_map;
  int map_len;
  int i;

  if (!line)
    return;
  map_len = count_command(cub->game_info->map);
  temp_map = (char **)malloc(sizeof(char *) * (map_len + 1 + 1));
  if (!temp_map)
    error("Cannot Assign Map");
  i = 0;
  while (i < map_len)
  {
    temp_map[i] = cub->game_info->map[i];
    i++;
  }
  temp_map[i] = parse_map_line(line);
  temp_map[i + 1] = NULL;

  if (cub->game_info->map)
    free(cub->game_info->map);
  cub->game_info->map = temp_map;
}

void parse_line(t_cub *cub, char *line)
{
  char **command;
  int command_cnt;

  printf("line: %s\n", line);
  if (!ft_strlen(line))
    return;
  command = ft_split(line, ' ');
  if (!command)
    error("ERROR");
  command_cnt = count_command(command);
  // 각 조건에 맞게 command의 개수를 확인 해야함.
  if (command_cnt == 3 && ft_strlen(command[0]) == 1 && ft_strncmp(command[0], "R", ft_strlen(command[0])) == 0)
    set_window_size(cub, command[1], command[2]);
  else if (command_cnt == 2 && ft_strlen(command[0]) == 2)
  {
    if (ft_strncmp(command[0], "NO", 2) == 0)
      set_image_url(cub, command[1], NORTH);
    else if (ft_strncmp(command[0], "SO", 2) == 0)
      set_image_url(cub, command[1], SOUTH);
    else if (ft_strncmp(command[0], "WE", 2) == 0)
      set_image_url(cub, command[1], WEST);
    else if (ft_strncmp(command[0], "EA", 2) == 0)
      set_image_url(cub, command[1], EAST);
  }
  else if (command_cnt == 2 && ft_strlen(command[0]) == 1)
  {
    if (ft_strncmp(command[0], "S", 1) == 0)
      set_image_url(cub, command[1], SPRITE);
    else if (ft_strncmp(command[0], "F", 1) == 0)
      set_color(cub, command[1], FLOOR);
    else if (ft_strncmp(command[0], "C", 1) == 0)
      set_color(cub, command[1], CEIL);
  }
  else if (command_cnt == 1)
    parse_map(cub, line);

  if (command)
    free_command(command);
}

void parse_cub(t_cub *cub, int fd)
{
  char *line;
  //get_next_line Error 처리 해줘야 함.
  while (get_next_line(fd, &line))
  {
    parse_line(cub, line);
    if (line)
      free(line);
  }
  if (line)
    free(line);
}

t_gameinfo *new_info()
{
  t_gameinfo *game_info;

  game_info = (t_gameinfo *)malloc(sizeof(t_gameinfo));
  if (!game_info)
    error("Cannot Assign GameInfo");
  game_info->window_h = 0;
  game_info->window_w = 0;
  game_info->map = NULL;

  return (game_info);
}

t_image *new_image()
{
  t_image *image;

  image = (t_image *)malloc(sizeof(t_image));
  if (!image)
    error("Cannot Assign Image");
  image->image_ptr = NULL;
  image->data = NULL;
  image->size_l = 0;
  image->bpp = 0;
  image->endian = 0;

  return (image);
}

t_texture *new_texture()
{
  t_texture *texture;

  texture = (t_texture *)malloc(sizeof(t_texture));
  if (!texture)
    error("Cannot Assign Texture");
  texture->image = new_image();
  texture->width = 0;
  texture->height = 0;

  return (texture);
}

t_player *new_player()
{
  t_player *player;

  player = (t_player *)malloc(sizeof(player));
  if (!player)
    error("Cannot Assign Player");
  player->x = 0;
  player->y = 0;
  player->th = 0;
  player->move_speed = 0;
  player->rot_speed = 0;

  return (player);
}

t_cub *new_cub()
{
  t_cub *cub;

  cub = (t_cub *)malloc(sizeof(cub));
  if (!cub)
    error("Cannot Assign Cub");
  cub->mlx = mlx_init();
  cub->window = NULL;
  cub->w_ratio = 0;
  cub->zbuf = NULL;
  cub->canvas = new_image();
  cub->player = new_player();
  cub->game_info = new_info();

  return (cub);
}

/* print */
void print_map(t_cub *cub)
{
  int i = 0;
  int j = 0;
  while (cub->game_info->map && cub->game_info->map[i])
  {
    j = 0;
    while (cub->game_info->map[i][j])
    {
      printf("%c", cub->game_info->map[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
}

t_bool is_all_elements_valid(t_cub *cub)
{
  int x;
  int y;

  y = 0;
  while (cub->game_info->map && cub->game_info->map[y])
  {
    x = 0;
    while (cub->game_info->map[y][x])
    {
      if (ft_strchr("012NESW9", cub->game_info->map[y][x]) == 0)
        return (false);
      x++;
    }
    y++;
  }
  return (true);
}

t_bool is_only_one_player(t_cub *cub)
{
  int x;
  int y;
  int player;

  y = 0;
  player = 0;
  while (cub->game_info->map && cub->game_info->map[y])
  {
    x = 0;
    while (cub->game_info->map[y][x])
    {
      if (ft_strchr("NESW", cub->game_info->map[y][x]))
        player++;
      x++;
    }
    y++;
  }
  if (player != 1)
    return (false);
  return (true);
}

t_bool is_map_surrounded(t_cub *cub)
{
  int x;
  int y;

  y = 0;
  while (cub->game_info->map && cub->game_info->map[y])
  {
    x = 0;
    while (cub->game_info->map[y][x])
    {
      if (ft_strchr("02NSWE", cub->game_info->map[y][x]) != 0)
      {
        if (y == 0 || x == 0 || y == (get_maplen(cub->game_info->map) - 1) || x == (ft_strlen(cub->game_info->map[y]) - 1))
          return (false);
        if (y > 0 && cub->game_info->map[y - 1][x] == '9')
          return (false);
        if (y < get_maplen(cub->game_info->map) - 1 && cub->game_info->map[y + 1][x] == '9')
          return (false);
        if (x > 0 && cub->game_info->map[y][x - 1] == '9')
          return (false);
        if (x < ft_strlen(cub->game_info->map[y]) - 1 && cub->game_info->map[y][x + 1] == '9')
          return (false);
      }
      x++;
    }
    y++;
  }
  return (true);
}

void validate_map(t_cub *cub)
{
  if (!is_all_elements_valid(cub))
    error("NOT ALL ELEMS IS NOT VALID");
  if (!is_only_one_player(cub))
    error("NOT ONLY ONE PLAYER");
  if (!is_map_surrounded(cub))
    error("NOT SURROUNDED MAP");
}

t_bool is_filled_url(char **arr)
{
  // TODO : url 이 모두 작성되었는지 확인하기
  return (true);
}

// TODO : floor, ceil 배열 유효성 판단하기 or 0으로 초기화 해서 값 없으면 black으로 만들기
t_bool is_complete_info(t_gameinfo *game_info)
{
  if (game_info->window_h == 0)
    return (false);
  if (game_info->window_w == 0)
    return (false);
  if (game_info->map == NULL)
    return (false);
  if (!is_filled_url(game_info->image_url))
    return (false);
  return (true);
}

void validate_info(t_cub *cub)
{
  if (!is_complete_info(cub->game_info))
    error("NOT COMPLETE INFO");
}

int main(int argc, char *argv[])
{
  int fd;
  t_cub *cub;

  if (argc != 2)
    error("Few Args");
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    error("Cannot Open File");
  cub = new_cub();
  parse_cub(cub, fd);

  printf("FINE~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  print_map(cub);

  validate_info(cub);
  validate_map(cub);
}
