/*
** rt.h for rt in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Apr 11 15:51:25 2016 alies_a
** Last update Tue Apr 12 10:37:08 2016 alies_a
*/

#ifndef RT_H_
#define RT_H_

#include <lapin.h>
#include "cl.h"

#define WIDTH (500)
#define HEIGHT (500)
#define FPS (30)

/*
** Struct rt defines all data needed to render
** Do not edit it unless you know what you are doing
*/

typedef struct s_rt
{
  cl_int	width;
  cl_int	height;
} t_rt;

typedef struct s_data
{
  t_bunny_pixelarray *pix;
  t_bunny_window *win;
  const bool *keys;
  t_rt rt;
  t_core core;
} t_data;

int     cl_load(t_core *core, const char *file, size_t buffer_size);
int	cl_exec(t_data *data, t_core *core);

#endif
