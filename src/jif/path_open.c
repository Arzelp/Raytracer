/*
** path_open.c for path_open in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Apr 15 14:40:24 2016 alies_a
** Last update Wed Apr 20 13:46:33 2016 alies_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "jif.h"

t_jif_path	*jif_path_open(const char *file, t_jif_mode mode)
{
  t_jif_path	*res;

  if ((res = malloc(sizeof(t_jif_path))) == NULL)
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
