/*
** main.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 18:33:22 2016 Arthur Josso
** Last update Fri Apr 15 16:03:10 2016 alies_a
*/

#include "rt.h"

t_bunny_response        press_key(t_bunny_event_state state,
				  t_bunny_keysym keysym,
				  void *pt_data)
{
  t_data	*data;

  data = pt_data;
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  if (keysym == BKS_SPACE && state == GO_DOWN)
    data->gen_type ^= IS_PREVIEW;
  if (keysym == BKS_U && state == GO_DOWN)
    data->gen_type ^= IS_PHONG;
  if (keysym == BKS_I && state == GO_DOWN)
    data->gen_type ^= IS_REFLEC;
  if (keysym == BKS_O && state == GO_DOWN)
    data->gen_type ^= IS_REFRAC;
  if (keysym == BKS_P && state == GO_DOWN)
    data->gen_type ^= IS_AA;
  return (GO_ON);
}

t_bunny_response        mainloop(void *pt_data)
{
  t_data		*data;
  t_bunny_position	origin;

  origin.x = 0;
  origin.y = 0;
  data = pt_data;
  rot += 0.05;
  if (data->gen_type & IS_PREVIEW)
    {
      data->pix = data->small;
      interact_cam(&data->obj.cam);
      gen_scene(data);
    }
  else
    {
      data->pix = data->big;
      gen_scene(data);
      data->gen_type ^= IS_PREVIEW;
    }
  //
  if (jif_path_write(data->path, &(data->obj.cam)))
    return (EXIT_ON_ERROR);
  //
  bunny_blit(&data->win->buffer, &data->big->clipable, &origin);
  bunny_blit(&data->win->buffer, &data->small->clipable, &origin);
  bunny_display(data->win);
  return (GO_ON);
}

static int	setup(int ac, char **av, t_data *data)
{
  if (ac >= 2)
    {
      if (init(data, av[1]) == ERROR)
	return (ERROR);
      if (ac == 3)
	{
	  if ((data->path = jif_path_open(av[2], J_READ)) == NULL)
	    return (ERROR);
	  if ((data->jif = jif_new("gen.jif", W_X, W_Y, 10)) == NULL)
	    return (ERROR);
	}
    }
  else
    {
      if (init(data, "demo/demo1.ini") == ERROR)
	return (ERROR);
    }
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  t_data	data;

  data.path = NULL;
  data.jif = NULL;
  rot = 0;
  if (setup(ac, av, &data) == ERROR)
    return (ERROR);
  if (data.path == NULL)
    {
      if ((data.path = jif_path_open("camera.path", J_WRITE)) == NULL)
	return (ERROR);
    }
  if (data.jif != NULL)
    jif_gen(&data);
  bunny_set_key_response(&press_key);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, FPS, &data);
  exit_prog(&data);
  return (SUCCESS);
}
