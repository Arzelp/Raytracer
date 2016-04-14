/*
** add.c for add in /home/alies_a/rendu/gfx_raytracer2/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Apr 14 18:31:33 2016 alies_a
** Last update Thu Apr 14 18:51:13 2016 alies_a
*/

#include <unistd.h>
#include "jif.h"

static void	set_buff(t_color from, t_jif_pix *to)
{
  to->r = from.argb[0];
  to->g = from.argb[1];
  to->b = from.argb[2];
}

static int	jif_write(const t_jif *jif, const t_bunny_pixelarray *pix)
{
  int		pos;
  int		size;
  t_jif_pix	buff;

  size = (pix->clipable).clip_width * (pix->clipable).clip_height;
  pos = 0;
  while (pos < size)
    {
      set_buff(((t_color*)pix->pixels)[pos], &buff);
      if (write(jif->fd, &buff, sizeof(t_jif_pix)) != sizeof(t_jif_pix))
	return (1);
      pos += 1;
    }
  return (0);
}

int			jif_add(const t_jif *jif, const t_bunny_pixelarray *pix)
{
  t_bunny_pixelarray	*res;

  if (jif->mode != J_WRITE)
    return (1);
  if ((int)(jif->head).width != (pix->clipable).clip_width ||
      (int)(jif->head).height != (pix->clipable).clip_height)
    return (1);
  if ((res = bunny_new_pixelarray((jif->head).width,
				  (jif->head).height)) == NULL)
    return (1);
  if (jif_write(jif, pix))
    return (1);
  return (0);
}
