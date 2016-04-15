/*
** vector2.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Feb 18 14:43:43 2016 Arthur Josso
** Last update Thu Feb 18 14:48:41 2016 Arthur Josso
*/

#include "rt.h"

void	inv_vec(t_vec *v)
{
  v->x *= -1;
  v->y *= -1;
  v->z *= -1;
}
