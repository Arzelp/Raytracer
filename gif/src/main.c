/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Thu Apr 14 20:49:30 2016 alies_a
*/

#include "info.h"

t_bunny_response	key_listenner(t_bunny_event_state state,
				      t_bunny_keysym keysym,
				      void *data_pt)
{
  t_data		*data;

  data = (t_data*)data_pt;
  data->keys = bunny_get_keyboard();
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position      zero;
  t_bunny_position	pos;
  static int		x = 0;
  t_color		c;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  c.full = WHITE;
  x += 1;
  pos.x = x;
  pos.y = x;
  if (FLAG)
    {
      tekpixel(data->pix, &pos, &c);
      jif_add(data->jif, data->pix);
      if (x > 200)
	{
	  jif_close(data->jif);
	  return (EXIT_ON_SUCCESS);
	}
    }
  else
    {
      bunny_delete_clipable(&(data->pix->clipable));
      if ((data->pix = jif_next(data->jif)) == NULL)
	return (EXIT_ON_SUCCESS);
    }
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  bunny_display(data->win);
  return (GO_ON);
}

int		main(int ac, char **av)
{
  t_data	data;

  (void)ac;
  (void)av;
  data.keys = NULL;
  if (FLAG)
    {
      if ((data.jif = jif_new("test.jif", WIDTH, HEIGHT, 100)) == NULL)
	return (1);
    }
  else
    {
      if ((data.jif = jif_open("test.jif")) == NULL)
	return (1);
    }
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "ray")) == NULL)
    return (1);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  return (0);
}
