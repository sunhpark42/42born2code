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

int max(int a, int b)
{
  if (a > b)
    return (a);
  return (b);
}

int min(int a, int b)
{
  if (a > b)
    return (b);
  return (a);
}
