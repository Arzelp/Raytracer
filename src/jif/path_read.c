/*
** path_read.c for read in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Apr 15 14:54:44 2016 alies_a
** Last update Fri Apr 15 15:02:28 2016 alies_a
*/

#include <unistd.h>
#include "core.h"
#include "jif.h"

int	jif_path_read(t_jif_path *path, void *cam)
{
  int	r;

  if (path->mode != J_READ)
    return (1);
  r = read(path->fd, cam, sizeof(t_cam));
  if (r != sizeof(t_cam))
    return (1);
  return (0);
}
