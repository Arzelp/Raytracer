
__kernel void calcpixel(__global unsigned int *pixels)
{
  pixels[get_global_id(0)] = 16777215;
}
