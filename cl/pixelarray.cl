
typedef struct s_rt
{
  int width;
  int height;
} t_rt;



__kernel void calcpixel(__global unsigned int *pixels,
			__constant t_rt *rt)
{
  int id = get_global_id(0);
  int x;
  int y;

  y = id / rt->width;
  x = id % rt->width;
  if (x > rt->width / 2)
    pixels[id] = 13777215;
  else
    pixels[id] = 17777215;
}
