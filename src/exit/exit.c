/*
** exit.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Feb 18 17:59:57 2016 Arthur Josso
** Last update Sat Feb 20 17:14:36 2016 Arthur Josso
*/

#include "rt.h"

void	exit_prog(t_data *data)
{
  int	i;

  bunny_delete_clipable(&data->big->clipable);
  bunny_delete_clipable(&data->small->clipable);
  i = 0;
  while (i < data->obj.nb.sphere)
    {
      if (data->obj.sphere[i].meta.tex)
	bunny_delete_clipable(&data->obj.sphere[i].meta.tex->clipable);
      i++;
    }
  bunny_stop(data->win);
}
