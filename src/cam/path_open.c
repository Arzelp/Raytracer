/*
** path_open.c for open in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 19:18:33 2016 alies_a
** Last update Wed Apr 20 19:19:04 2016 alies_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "jif.h"
#include "cam.h"

t_cam_path	*cam_path_open(const char *file, t_jif_mode mode)
{
  t_cam_path	*res;

  if ((res = malloc(sizeof(t_cam_path))) == NULL)
    return (NULL);
  res->mode = mode;
  if (mode == J_WRITE)
    {
      if ((res->fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
	return (NULL);
    }
  else
    {
      if ((res->fd = open(file, O_RDONLY)) == -1)
	return (NULL);
    }
  return (res);
}
