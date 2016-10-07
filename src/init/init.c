/*
** init.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 18:38:07 2016 Arthur Josso
** Last update Fri Oct  7 14:05:26 2016 alies_a
*/

#include "rt.h"

static void		put_in_black(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_color		color;

  color.full = BLACK;
  pos.x = 0;
  while (pos.x < pix->clipable.clip_width)
    {
      pos.y = 0;
      while (pos.y < pix->clipable.clip_height)
	{
	  tekpixel(pix, &pos, &color);
	  pos.y++;
	}
      pos.x++;
    }
}

static int	win_init(t_data *data)
{
  if ((data->win = bunny_start(W_X, W_Y, FULL_SCR, "RT")) == NULL)
    return (E_ERROR);
  if ((data->big = bunny_new_pixelarray(W_X, W_Y)) == NULL)
    return (E_ERROR);
  put_in_black(data->big);
  if ((data->small = bunny_new_pixelarray(W_X / 10, W_Y / 10)) == NULL)
    return (E_ERROR);
  put_in_black(data->small);
  return (E_SUCCESS);
}

int	init(t_data *data, const char *file)
{
  data->keys = NULL;
  data->gen_type = IS_PREVIEW;
  if (win_init(data) == E_ERROR)
    return (E_ERROR);
  if (load_scene(&data->obj, file) == E_ERROR)
    return (E_ERROR);
  return (E_SUCCESS);
}
