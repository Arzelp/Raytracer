/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Tue Apr 12 16:35:18 2016 alies_a
*/

#include "rt.h"

static void	init_rt(t_rt *rt)
{
  rt->width = WIDTH;
  rt->height = HEIGHT;
  rt->cam.alpha = -M_PI / 2;
  rt->cam.beta = 0;
  rt->cam.pos.x = 0;
  rt->cam.pos.y = 4;
  rt->cam.pos.z = 0;
  
  //rt->width = 0;
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
  //data->rt.width += 1;
  data->rt.cam.alpha += 0.1;
  if (data->keys != NULL)
    {
      if (data->keys[BKS_LEFT])
	data->rt.cam.alpha += 0.5;
      if (data->keys[BKS_RIGHT])
	data->rt.cam.alpha -= 0.5;
      printf("%f\n", data->rt.cam.alpha);
    }
  cl_exec(data, &(data->core));
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  bunny_display(data->win);
  return (GO_ON);
}

int		main(int ac, char **av)
{
  t_data	data;

  (void)ac;
  (void)av;
  init_rt(&(data.rt));
  data.keys = NULL;
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "ray")) == NULL)
    return (1);
  //
  if (cl_load(&(data.core), "./cl/pixelarray.cl",
	      WIDTH * HEIGHT * sizeof(unsigned int)))
    return (1);
  //
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  return (0);
}
