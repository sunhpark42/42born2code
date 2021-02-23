#include "cub3d.h"

void load_textures(t_mlx *mlx)
{
  load_texture(mlx, mlx->n_texture, mlx->game_info->n_image);
  load_texture(mlx, mlx->w_texture, mlx->game_info->w_image);
  load_texture(mlx, mlx->s_texture, mlx->game_info->s_image);
  load_texture(mlx, mlx->e_texture, mlx->game_info->e_image);
}

int load_texture(t_mlx *mlx, t_texture *texture, char *src)
{
  int fd;
  int image_width;
  int image_height;

  texture->image->image = mlx_xpm_file_to_image(mlx->mlx, src, &image_width, &image_height);
  texture->image->data = (int *)mlx_get_data_addr(texture->image->image, &(texture->image->bpp), &(texture->image->size_l), &(texture->image->endian));
  texture->width = image_width;
  texture->height = image_height;

  return (0);
}

t_image *create_image(t_mlx *mlx, int width, int height)
{
  t_image *image;
  image->image = mlx_new_image(mlx->mlx, width, height);
  image->data = (int *)mlx_get_data_addr(image->image, &(image->bpp), &(image->size_l), &(image->endian));
  return image;
}
