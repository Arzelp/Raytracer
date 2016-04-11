/*
** cl.h for cl in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Apr 11 16:36:57 2016 alies_a
** Last update Mon Apr 11 18:19:36 2016 alies_a
*/

#ifndef CL_H_
#define CL_H_

#include <CL/cl.h>

typedef struct s_core
{
  cl_uint               num_platform;
  cl_uint               num_device;
  cl_platform_id        platform_id;
  cl_device_id          device_id;
  cl_context            context;
  cl_command_queue      command_queue;
  cl_mem                buffer;
  size_t		buffer_size;
  cl_program            program;
} t_core;

int	cl_load(t_core *core, const char *file, size_t buffersize);

#endif
