/*
** plan.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Apr 15 17:51:42 2016 Arthur Josso
** Last update Mon Apr 18 16:07:31 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static float	get_hit(t_ray *r, t_plan *p)
{
  float		c1;
  float		c2;

  c1 = p->meta.rot.x * r->beta.x
    + p->meta.rot.y * r->beta.y
    + p->meta.rot.z * r->beta.z;
  c2 = p->meta.rot.x * (r->alpha.x - p->meta.pos.x)
    + p->meta.rot.y * (r->alpha.y - p->meta.pos.y)
    + p->meta.rot.z * (r->alpha.z - p->meta.pos.z);
  return (-c2 / c1);
}

void	find_k_plan(t_ray *ray, t_obj *obj, t_hit *hit)
{
  float	k;
  int	i;

  i = 0;
  while (i < obj->nb.plan)
    {
      k = get_hit(ray, &obj->plan[i]);
      if (k < hit->k && k >= 0)
	{
	  hit->k = k;
	  hit->obj = (void*)&obj->plan[i];
	  hit->obj_type = PLAN;
	  hit->meta = obj->plan[i].meta;
	}
      i++;
    }
}
