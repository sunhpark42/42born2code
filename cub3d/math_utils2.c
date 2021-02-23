#include "cub3d.h"

t_bool is_zero(double num)
{
  if (fabs(num) < EPS)
    return (true);
  return (false);
}

double deg_to_rad(double num)
{
  return (((num)*M_PI / 180.0));
}

double rad_to_deg(double num)
{
  return (((num)*180.0 / M_PI));
}

double get_fovh(void)
{
  return (deg_to_rad(FOV));
}

double get_fovv(double fovh, double width, double height)
{
  return (fovh * height / width);
}