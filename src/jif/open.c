/*
** open.c for open in /home/alies_a/rendu/gfx_raytracer2/gif/src/jif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 13 18:23:02 2016 alies_a
** Last update Thu Apr 14 18:40:43 2016 alies_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "jif.h"

static int	jif_read(int fd, t_jif_header *head)
{
  if (read(fd, head, sizeof(t_jif_header)) != sizeof(t_jif_header))
    return (1);
  return (0);
}

t_jif	*jif_open(const char *file)
{
  t_jif *res;

  if ((res = malloc(sizeof(t_jif))) == NULL)
    return (NULL);
  res->mode = J_READ;
  if ((res->fd = open(file, O_RDONLY)) == -1)
    {
      free(res);
      return (NULL);
    }
  if (jif_read(res->fd, &(res->head)))
    {
      close(res->fd);
      free(res);
      return (NULL);
    }
  return (res);
}