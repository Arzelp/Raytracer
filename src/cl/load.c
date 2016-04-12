/*
** load.c for load in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Apr 11 16:51:00 2016 alies_a
** Last update Tue Apr 12 14:07:20 2016 alies_a
*/

#include "rt.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SRC "./cl/pixelarray.cl"

static char	*load_file(const char *name, size_t *src_size)
{
  int		fd;
  char		*res;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (NULL);
  res = get_next_line(fd);
  *src_size = my_strlen(res);
  close(fd);
  return (res);
}

int	cl_load(t_core *core, const char *file, size_t buffer_size)
{
  cl_int                ret;
  char                  *src_str;
  size_t                src_size;

  core->buffer_size = buffer_size;
  if ((src_str = load_file(file, &src_size)) == NULL)
    return (1);
  ret = clGetPlatformIDs(1, &(core->platform_id), &(core->num_platform));
  ret = clGetDeviceIDs(core->platform_id, CL_DEVICE_TYPE_DEFAULT, 1,
		       &(core->device_id), &(core->num_device));
  core->context = clCreateContext(NULL, 1, &(core->device_id), NULL, NULL, &ret);
  core->command_queue = clCreateCommandQueue(core->context, core->device_id,
					     CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, &ret);
  core->buffer = clCreateBuffer(core->context, CL_MEM_READ_WRITE,
				buffer_size, NULL, &ret);
  core->program = clCreateProgramWithSource(core->context, 1,
					    (const char **)&src_str,
					    (const size_t *)&src_size, &ret);
  ret = clBuildProgram((core->program), 1, &(core->device_id), NULL, NULL, NULL);
  cl_assert(ret);
  free(src_str);
  return (0);
}
