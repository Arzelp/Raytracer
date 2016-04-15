/*
** tekray.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Feb  1 17:21:03 2016 Arthur Josso
** Last update Sat Mar 12 17:35:48 2016 Arthur Josso
*/

#include <lapin.h>

void	tekray(const t_bunny_position *screen_info, int *x, int *y, int *z)
{
  *x = screen_info[1].x - (screen_info[0].x / 2);
  *y = screen_info[1].y - (screen_info[0].y / 2);
  *z = 100;
}
