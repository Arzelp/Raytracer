
typedef struct s_simple_pixelarray
{
  int width;
  int height;
  void *pixels;
} t_simple_pixelarray;

__kernel void calcpixel(__global t_simple_pixelarray *pix,
			__read_only int x,
			__read_only int y)
{
  ((unsigned int*)pix->pixels)[pix->w * y + x] = 16777215;
}
