/*
** path_close.c for close in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Apr 15 14:52:58 2016 alies_a
** Last update Fri Apr 15 14:53:46 2016 alies_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "jif.h"

void	jif_path_close(t_jif_path *path)
{
  close(path->fd);
  free(path);
}
