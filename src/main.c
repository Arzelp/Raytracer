/*
** main.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 18:33:22 2016 Arthur Josso
** Last update Thu Apr 14 18:53:18 2016 Arthur Josso
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
  bunny_blit(&data->win->buffer, &data->pix->clipable, &origin);
  bunny_display(data->win);
  return (GO_ON);
}

int		main(int ac, char **av)
{
  t_data	data;

  if (ac == 1 && init(&data, "demo/demo1.ini") == ERROR)
    return (ERROR);
  else if (ac >= 2 && init(&data, av[1]) == ERROR)
    return (ERROR);
  rot = 0;
  bunny_set_key_response(&press_key);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, FPS, &data);
  exit_prog(&data);
  return (SUCCESS);
}
