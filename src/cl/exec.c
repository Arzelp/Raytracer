/*
** exec.c for exec in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Apr 11 18:02:35 2016 alies_a
** Last update Mon Apr 11 18:34:29 2016 alies_a
*/

#include "rt.h"

int		cl_exec(t_data *data, t_core *core)
{
  cl_int	ret;
  cl_kernel	kernel;
  size_t	global_item_size = WIDTH * HEIGHT;
  size_t	local_item_size = 1;

  kernel = clCreateKernel(core->program, "calcpixel", &ret);
  ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&(core->buffer));
  
  /* Execute OpenCL kernel as data parallel */
  ret = clEnqueueNDRangeKernel(core->command_queue, kernel, 1, NULL,
			       &global_item_size, &local_item_size, 0, NULL, NULL);
  
  /* Copy results from the memory buffer */
  ret = clEnqueueReadBuffer(core->command_queue, core->buffer, CL_TRUE, 0,
			    core->buffer_size, data->pix->pixels, 0, NULL, NULL);
}
