/*
** info.h for info in /home/alies_a/proto/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 13 12:34:17 2016 alies_a
** Last update Sun May 22 13:43:52 2016 alies_a
*/

#ifndef INFO_H_
# define INFO_H_

# include <lapin.h>
# include "jif.h"

# define FPS (30)

# define FLAG (0)

typedef struct s_data
{
  t_bunny_pixelarray *pix;
  t_bunny_window *win;
  const bool *keys;
  t_jif *jif;
  const char *name;
} t_data;

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

#endif
