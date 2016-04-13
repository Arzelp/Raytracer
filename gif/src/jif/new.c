/*
** new.c for new in /home/alies_a/rendu/gfx_raytracer2/gif/src/jif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 13 17:18:37 2016 alies_a
** Last update Wed Apr 13 18:06:36 2016 alies_a
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "jif.h"

static int      jif_write_header(int fd, int width, int height, int delay)
{
  t_jif_header	header;

  header.magic = JIF_MAGIC;
  header.width = width;
  header.height = height;
  header.delay = delay;
  if (write(fd, &header, sizeof(t_jif_header)) != sizeof(t_jif_header))
    return (1);
  return (0);
}

t_jif   *jif_new(const char *file, int width, int height, int delay)
{
  t_jif	*res;

  if ((res = malloc(sizeof(t_jif))) == NULL)
    return (NULL);
  res->mode = J_WRITE;
  if ((res->fd = open(file, O_RDONLY)) == -1)
    {
      free(res);
      return (NULL);
    }
  if (jif_write_header(res->fd, width, height, delay))
    {
      close(res->fd);
      free(res);
      return (NULL);
    }
  return (res);
}
