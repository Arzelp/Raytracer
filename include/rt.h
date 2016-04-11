/*
** rt.h for rt in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Apr 11 15:51:25 2016 alies_a
** Last update Mon Apr 11 15:52:59 2016 alies_a
*/

#ifndef RT_H_
#define RT_H_

#include <lapin.h>

#define WIDTH (500)
#define HEIGHT (500)
#define FPS (30)

typedef struct s_data
{
  t_bunny_pixelarray *pix;
  t_bunny_window *win;
  const bool *keys;
} t_data;

#endif
