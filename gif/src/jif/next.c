/*
** next.c for next in /home/alies_a/rendu/gfx_raytracer2/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Apr 14 20:26:14 2016 alies_a
** Last update Thu Apr 14 20:37:50 2016 alies_a
*/

#include <unistd.h>
#include "jif.h"

static t_color	get_buff(t_jif_pix buff)
{
  t_color	res;

  res.argb[0] = buff.r;
  res.argb[1] = buff.g;
  res.argb[2] = buff.b;
  res.argb[3] = 255;
  return (res);
}

static int	jif_read(const t_jif *jif, t_bunny_pixelarray *pix)
{
  int		size;
  int		pos;
  t_jif_pix	buff;

  size = (pix->clipable).clip_width * (pix->clipable).clip_height;
  pos = 0;
  while (pos < size)
    {
      if (read(jif->fd, &buff, sizeof(t_jif_pix)) != sizeof(t_jif_pix))
	return (1);
      ((t_color*)pix->pixels)[pos] = get_buff(buff);
      pos += 1;
    }
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
