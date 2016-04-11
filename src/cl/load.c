/*
** load.c for load in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Apr 11 16:51:00 2016 alies_a
** Last update Mon Apr 11 17:17:31 2016 alies_a
*/

#include "rt.h"

#include <stdlib.h>
#include <stdio.h>

#define SRC "./cl/pixelarray.cl"
#define SRC_SIZE (0x100000)

#define MEM_SIZE (128)

static char	*load_file(const char *name, size_t *src_size)
{
  FILE		*fp;
  char		*src_str;

  *src_size = 0;
  if ((fp = fopen(name, "r")) == NULL)
    return (NULL);
  if ((src_str = malloc(sizeof(char) * SRC_SIZE)) == NULL)
    return (NULL);
  *src_size = fread(src_str, 1, SRC_SIZE, fp);
  fclose(fp);
  return (src_str);
}

int	cl_load(t_core *core, const char *file, size_t buffersize)
{
  cl_int                ret;
  char                  *src_str;
  size_t                src_size;

  if ((src_str = load_file(file, &src_size)) == NULL)
    return (1);

  ret = clGetPlatformIDs(1, &(core->platform_id), &(core->num_platform));
  ret = clGetDeviceIDs(core->platform_id, CL_DEVICE_TYPE_DEFAULT, 1,
		       &(core->device_id), &(core->num_device));

  core->context = clCreateContext(NULL, 1, &(core->device_id), NULL, NULL, &ret);
  core->command_queue = clCreateCommandQueue(core->context, core->device_id, 0, &ret);

  core->buffer = clCreateBuffer(core->context, CL_MEM_READ_WRITE,
				buffersize, NULL, &ret);

  core->program = clCreateProgramWithSource(core->context,
					    1,
					    (const char **)&src_str,
					    (const size_t *)&src_size,
					    &ret);

  ret = clBuildProgram((core->program), 1, &(core->device_id), NULL, NULL, NULL);
  return (0);
}
