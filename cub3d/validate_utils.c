#include "cub3d.h"

t_bool is_xpm(char *line)
{
  // 끝 4글자가 .xpm 인지 확인
  return (true);
}

t_bool is_exist(char *line)
{
  int fd;

  fd = open(line, O_RDONLY);
  if (fd < 0)
    return (false);
  close(fd);
  return (true);
}