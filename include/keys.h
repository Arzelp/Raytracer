/*
** keys.h for keys management in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 14:09:11 2016 alies_a
** Last update Wed Apr 20 16:42:24 2016 alies_a
*/

#ifndef KEYS_H_
#define KEYS_H_

#include <lapin.h>

typedef struct s_key_callback
{
  t_bunny_keysym type;
  int (*callback)(t_data *data);
  int instant;
} t_key_callback;

t_bunny_response        update_keys(t_bunny_event_state state,
				    t_bunny_keysym keysym,
				    void *pt_data);
void	manage_keys(t_data *data);

/*
** Callbacks
*/

int     key_up(t_data *data);
int     key_down(t_data *data);
int     key_forward(t_data *data);
int     key_backward(t_data *data);
int     key_left(t_data *data);
int     key_right(t_data *data);
int     key_esc(t_data *data);

#endif
