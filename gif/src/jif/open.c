/*
** open.c for open in /home/alies_a/rendu/gfx_raytracer2/gif/src/jif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 13 18:23:02 2016 alies_a
** Last update Wed Apr 13 18:28:11 2016 alies_a
*/

#include "jif.h"

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
  return (res);
}
