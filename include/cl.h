/*
** cl.h for cl in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Apr 11 16:36:57 2016 alies_a
** Last update Tue Apr 12 15:27:53 2016 alies_a
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

typedef struct s_cl_err
{
  const char *err;
  int code;
} t_cl_err;

/*
** Struct rt defines all data needed to render
** Do not edit it unless you know what you are doing
*/

typedef struct s_vec
{
  cl_float x;
  cl_float y;
  cl_float z;
} t_vec;

typedef struct s_ray
{
  t_vec alpha;
  t_vec beta;
} t_ray;

typedef struct s_cam
{
  t_vec pos;
  cl_float alpha;
  cl_float beta;
} t_cam;

typedef struct s_rt
{
  cl_int width;
  cl_int height;
  t_cam cam;
} t_rt;

#endif
