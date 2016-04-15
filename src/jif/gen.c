/*
** gen.c for gen in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Apr 15 15:54:21 2016 alies_a
** Last update Fri Apr 15 16:05:14 2016 alies_a
*/

#include "rt.h"
#include "core.h"
#include "jif.h"

int	jif_gen(t_data *data)
{
  t_cam	cam;

  while (jif_path_read(data->path, &cam) == 0)
    {
      data->pix = data->big;
      data->obj.cam = cam;
      data->gen_type |= IS_PREVIEW;
      gen_scene(data);
      if (jif_add(data->jif, data->pix))
	return (1);
    }
  return (0);
}
