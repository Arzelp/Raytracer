/*
** gen.c for gen in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Apr 15 15:54:21 2016 alies_a
** Last update Wed Apr 20 11:57:09 2016 alies_a
*/

#include "rt.h"
#include "core.h"
#include "jif.h"
#include "my.h"

int	jif_gen(t_data *data)
{
  t_cam	cam;
  t_cam old;

  my_memset(&old, 0, sizeof(t_cam));
  data->gen_type = 255;
  data->gen_type ^= IS_AA;
  data->gen_type ^= IS_PREVIEW;
  while (jif_path_read(data->path, &cam) == 0)
    {
      data->pix = data->big;
      data->obj.cam = cam;
      if (my_memcmp(&cam, &old, sizeof(t_cam)) != 0)
	gen_scene(data);
      old = cam;
      if (jif_add(data->jif, data->pix))
	return (1);
    }
  return (0);
}
