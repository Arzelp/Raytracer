/*
** normal_vec_hard.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Apr 15 13:44:19 2016 Arthur Josso
** Last update Fri Apr 15 14:36:44 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

t_vec		get_torus_n(t_hit *hit)
{
  t_vec		n;
  double	alpha;
  t_torus	*torus;
  t_vec		pt;

  pt = hit->rot_pt;
  pt.x -= hit->meta.pos.x;
  pt.y -= hit->meta.pos.y;
  pt.z -= hit->meta.pos.z;
  torus = hit->obj;
  alpha = torus->radius / sqrt(POW(pt.x) +
			       POW(pt.y));
  alpha = 1 - alpha;
  n.x = alpha * pt.x;
  n.y = alpha * pt.y;
  n.z = pt.z;
  set_uni_vec(&n);
  rot_vec_inv(&n, &hit->meta.rot);
  return (n);
}
