/*
** path_write.c for write in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Apr 15 14:57:22 2016 alies_a
** Last update Wed Apr 20 13:46:26 2016 alies_a
*/

#include <unistd.h>
#include "core.h"
#include "jif.h"

int	jif_path_write(t_jif_path *path, const void *cam)
{
  int	w;

  if (path->mode != J_WRITE)
    return (1);
  w = write(path->fd, cam, sizeof(t_cam));
  if (w != sizeof(t_cam))
    return (1);
  return (0);
}
