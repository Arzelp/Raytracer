
typedef struct s_rt
{
  int width;
  int height;
} t_rt;

__kernel void calcpixel(__global unsigned int *pixels,
			__global t_rt *rt)
{
  int id = get_global_id(0);
  int x;
  int y;

  y = id / rt->width;
  x = id % rt->width;
  
  pixels[id] = 16777215;  
}
