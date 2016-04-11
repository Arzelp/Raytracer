/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Mon Mar  7 16:51:15 2016 alies_a
*/

#include "rt.h"
#include "my.h"

int	init_all(t_data *data, const char *file)
{
  if (load_ini(file, &(data->objs)))
    return (1);
  return (0);
}

void		move(t_data *data)
{
  t_objs	*objs;

  objs = &(data->objs);
  if (data->keys != NULL)
    {
      if (data->keys[BKS_UP])
	(objs->cam).beta += 0.05;
      if (data->keys[BKS_DOWN])
	(objs->cam).beta -= 0.05;
      if (data->keys[BKS_RIGHT])
	(objs->cam).alpha -= 0.05;
      if (data->keys[BKS_LEFT])
	(objs->cam).alpha += 0.05;
    }
}

t_bunny_response key_listenner(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data_pt)
{
  t_data        *data;

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
  move(data);
  display(data);
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
  if (init_all(&data, (ac > 1 ? av[1] : "maps/default.ini")))
    {
      my_putstr("File loading failed.\n");
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
