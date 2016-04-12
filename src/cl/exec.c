/*
** exec.c for exec in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Apr 11 18:02:35 2016 alies_a
** Last update Tue Apr 12 10:47:55 2016 alies_a
*/

#include "rt.h"

int		cl_exec(t_data *data, t_core *core)
{
  cl_int	ret;
  cl_kernel	kernel;
  cl_mem	mem;
  size_t	global_item_size;
  size_t	local_item_size;
  
  global_item_size = WIDTH * HEIGHT;
  local_item_size = 1;

  mem = clCreateBuffer(core->context, CL_MEM_COPY_HOST_PTR,
		       sizeof(t_rt), &(data->rt), &ret);
  
  kernel = clCreateKernel(core->program, "calcpixel", &ret);
  ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&(core->buffer));
  ret = clSetKernelArg(kernel, 1, sizeof(t_rt), (void*)&mem);
  
  ret = clEnqueueNDRangeKernel(core->command_queue, kernel, 1, NULL,
			       &global_item_size, &local_item_size, 0, NULL, NULL);
  ret = clEnqueueReadBuffer(core->command_queue, core->buffer, CL_TRUE, 0,
			    core->buffer_size, data->pix->pixels, 0, NULL, NULL);
  ret = clReleaseKernel(kernel);
  ret = clReleaseMemObject(mem);
  return (0);
}
