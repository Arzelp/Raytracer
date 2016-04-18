/*
** add_plan.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Apr 15 17:42:24 2016 Arthur Josso
** Last update Fri Apr 15 18:13:59 2016 Arthur Josso
*/

#include "init.h"

static int	add(t_plan **item, int *nb_item, t_plan new_item)
{
  t_plan	*new;
  int		i;

  if ((new = bunny_malloc((*nb_item + 1) * sizeof(t_plan))) == NULL)
    return (1);
  i = 0;
  while (i < *nb_item)
    {
      new[i] = (*item)[i];
      i++;
    }
  new[*nb_item] = new_item;
  if (*nb_item != 0)
    bunny_free(*item);
  (*item) = new;
  (*nb_item)++;
  return (0);
}

int		add_plan(t_obj *obj, t_bunny_ini_scope *scope)
{
  t_plan	plan;

  if (get_ini_meta(scope, &plan.meta) == 1)
    return (1);
  if (add(&obj->plan, &obj->nb.plan, plan) == 1)
    return (1);
  if (plan.meta.rot.x == 0 &&
      plan.meta.rot.y == 0 &&
      plan.meta.rot.z == 0)
    return (1);
  return (0);
}
