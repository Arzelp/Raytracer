/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Fri Apr 15 16:39:27 2016 alies_a
*/

#include <unistd.h>
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

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  if (jif_next_fill(data->jif, data->pix))
    {
      jif_close(data->jif);
      if ((data->jif = jif_open(data->name)) == NULL)
	return (EXIT_ON_ERROR);
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
  if (ac <= 1)
    {
      write(1, "PD\n", 3);
      return (1);
    }
  data.name = av[1];
  if ((data.jif = jif_open(data.name)) == NULL)
    return (1);
  if ((data.pix = bunny_new_pixelarray(data.jif->head.width,
				       data.jif->head.height)) == NULL)
    return (1);
  if ((data.win = bunny_start(data.jif->head.width,
			      data.jif->head.height, false, "anal")) == NULL)
    return (1);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  return (0);
}
