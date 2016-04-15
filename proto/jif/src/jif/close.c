/*
** close.c for close in /home/alies_a/rendu/gfx_raytracer2/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Apr 14 18:52:46 2016 alies_a
** Last update Thu Apr 14 20:25:31 2016 alies_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "jif.h"

void	jif_close(t_jif *jif)
{
  close(jif->fd);
  free(jif);
}
