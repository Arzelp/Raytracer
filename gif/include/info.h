/*
** info.h for info in /home/alies_a/proto/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 13 12:34:17 2016 alies_a
** Last update Wed Apr 13 12:40:00 2016 alies_a
*/

#ifndef INFO_H_
#define INFO_H_

#include <lapin.h>
#include "gif.h"

#define WIDTH (500)
#define HEIGHT (500)
#define FPS (5)

typedef struct s_data
{
  t_bunny_pixelarray *pix;
  t_bunny_window *win;
  const bool *keys;
} t_data;

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

#endif
