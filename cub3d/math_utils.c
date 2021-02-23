#include "cub3d.h"

int sign(double num)
{
  return (is_zero(num) ? 0 : ((num > 0) ? 1 : -1));
}

double l2dist(double x0, double y0, double x1, double y1)
{
  double dx;
  double dy;

  dx = x0 - x1;
  dy = y0 - y1;
  return sqrt(dx * dx + dy * dy);
}

double max(double a, double b)
{
  if (a > b)
    return (a);
  return (b);
}

double min(double a, double b)
{
  if (a > b)
    return (b);
  return (a);
}
