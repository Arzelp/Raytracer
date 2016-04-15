/*
** err.c for errors in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Apr 12 13:46:42 2016 alies_a
** Last update Tue Apr 12 14:07:00 2016 alies_a
*/

#include "rt.h"

t_cl_err errors[] = {
  {"CL_SUCCESS", 0},
  {"CL_DEVICE_NOT_FOUND", -1},
  {"CL_DEVICE_NOT_AVAILABLE", -2},
  {"CL_COMPILER_NOT_AVAILABLE", -3},
  {"CL_MEM_OBJECT_ALLOCATION_FAILURE", -4},
  {"CL_OUT_OF_RESOURCES", -5},
  {"CL_OUT_OF_HOST_MEMORY", -6},
  {"CL_PROFILING_INFO_NOT_AVAILABLE", -7},
  {"CL_MEM_COPY_OVERLAP", -8},
  {"CL_IMAGE_FORMAT_MISMATCH", -9},
  {"CL_IMAGE_FORMAT_NOT_SUPPORTED", -10},
  {"CL_BUILD_PROGRAM_FAILURE", -11},
  {"CL_MAP_FAILURE", -12},
  {"CL_INVALID_VALUE", -30},
  {"CL_INVALID_DEVICE_TYPE", -31},
  {"CL_INVALID_PLATFORM", -32},
  {"CL_INVALID_DEVICE", -33},
  {"CL_INVALID_CONTEXT", -34},
  {"CL_INVALID_QUEUE_PROPERTIES", -35},
  {"CL_INVALID_COMMAND_QUEUE", -36},
  {"CL_INVALID_HOST_PTR", -37},
  {"CL_INVALID_MEM_OBJECT", -38},
  {"CL_INVALID_IMAGE_FORMAT_DESCRIPTOR", -39},
  {"CL_INVALID_IMAGE_SIZE", -40},
  {"CL_INVALID_SAMPLER", -41},
  {"CL_INVALID_BINARY", -42},
  {"CL_INVALID_BUILD_OPTIONS", -43},
  {"CL_INVALID_PROGRAM", -44},
  {"CL_INVALID_PROGRAM_EXECUTABLE", -45},
  {"CL_INVALID_KERNEL_NAME", -46},
  {"CL_INVALID_KERNEL_DEFINITION", -47},
  {"CL_INVALID_KERNEL", -48},
  {"CL_INVALID_ARG_INDEX", -49},
  {"CL_INVALID_ARG_VALUE", -50},
  {"CL_INVALID_ARG_SIZE", -51},
  {"CL_INVALID_KERNEL_ARGS", -52},
  {"CL_INVALID_WORK_DIMENSION", -53},
  {"CL_INVALID_WORK_GROUP_SIZE", -54},
  {"CL_INVALID_WORK_ITEM_SIZE", -55},
  {"CL_INVALID_GLOBAL_OFFSET", -56},
  {"CL_INVALID_EVENT_WAIT_LIST", -57},
  {"CL_INVALID_EVENT", -58},
  {"CL_INVALID_OPERATION", -59},
  {"CL_INVALID_GL_OBJECT", -60},
  {"CL_INVALID_BUFFER_SIZE", -61},
  {"CL_INVALID_MIP_LEVEL", -62},
  {"CL_INVALID_GLOBAL_WORK_SIZE", -63},
  {NULL, 0}
};

int	cl_assert(int ret)
{
  int	x;

  x = 1;
  while (errors[x].err != NULL)
    {
      if (ret == errors[x].code)
	{
	  my_putstr(errors[x].err);
	  my_putstr("\n");
	  exit(1);
	}
      x += 1;
    }
  return (0);
}