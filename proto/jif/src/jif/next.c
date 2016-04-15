/*
** next.c for next in /home/alies_a/rendu/gfx_raytracer2/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Apr 14 20:26:14 2016 alies_a
** Last update Fri Apr 15 11:31:32 2016 alies_a
*/

#include <unistd.h>
#include "jif.h"

static int	jif_read(const t_jif *jif, t_bunny_pixelarray *pix)
{
  int		size;
  unsigned int	r;

  size = (pix->clipable).clip_width * (pix->clipable).clip_height;
  r = read(jif->fd, pix->pixels, sizeof(t_color) * size);
  if (r != sizeof(t_color) * size)
    return (1);
  return (0);
}

t_bunny_pixelarray	*jif_next(const t_jif *jif)
{
  t_bunny_pixelarray	*res;

  if (jif->mode != J_READ)
    return (NULL);
  if ((res = bunny_new_pixelarray((jif->head).width,
				  (jif->head).height)) == NULL)
    return (NULL);
  if (jif_read(jif, res))
    {
      bunny_delete_clipable(&(res->clipable));
      return (NULL);
    }
  return (res);
}
