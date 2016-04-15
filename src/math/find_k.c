/*
** find_k.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Jan 30 19:51:49 2016 Arthur Josso
** Last update Thu Apr 14 17:34:30 2016 Arthur Josso
*/

#include <stdlib.h>
#include "rt.h"

static void	find_k_ground(t_ray *ray, t_hit *hit)
{
  float		k;
  char		mod;

  if (ray->beta.z)
    {
      k = (-ray->alpha.z) / ray->beta.z;
      if (k < hit->k && k >= 0)
	{
	  hit->k = k;
	  hit->obj = NULL;
	  hit->obj_type= GROUND;
	  hit->pt = get_pt_with_k(hit->k, ray);
	  mod = hit->pt.x * hit->pt.y > 0 ? 1 : 0;
	  hit->meta.color.full = ABS((int)hit->pt.x + (int)hit->pt.y)
	    % 2 == mod ? WHITE : BLACK;
	  hit->meta.reflec = 1;
	  hit->meta.mirroring = 0.4;
	  hit->meta.refrac.ratio = 0;
	  hit->meta.perlin.ratio = 0;
	}
    }
}

void    find_hit(t_data *data, t_ray *ray, t_hit *hit)
{
  hit->k = VIEW_RANGE;
  hit->obj = NULL;
  hit->obj_type = NONE;
  find_k_sphere(ray, &data->obj, hit);
  find_k_cylinder(ray, &data->obj, hit);
  find_k_cone(ray, &data->obj, hit);
  find_k_torus(ray, &data->obj, hit);
  find_k_ground(ray, hit);
  hit->pt = get_pt_with_k(hit->k, ray);
  hit->rot_pt = get_rot_vec(hit->pt, &hit->meta.rot);
  if (hit->obj_type != NONE && hit->meta.perlin.ratio
      && hit->meta.perlin.type != 2)
    hit->meta.color = get_perlin_at(&hit->pt, &hit->meta);
}
