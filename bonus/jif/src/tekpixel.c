/*
** tekpixel.c for tek in /home/alies_a/proto/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 13 12:36:55 2016 alies_a
** Last update Wed Apr 13 12:37:08 2016 alies_a
*/

#include <lapin.h>

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int   w;
  int   h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if ((pos->x < w && pos->y < h) && (pos->x >= 0 && pos->y >= 0))
    (((t_color*)pix->pixels)[w * pos->y + pos->x]).full = color->full;
}
