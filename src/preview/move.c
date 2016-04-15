/*
** move.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Jan 31 14:17:47 2016 Arthur Josso
** Last update Mon Feb 15 18:54:55 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static void	move_cam(t_cam *cam, const bool *key_pressed)
{
  if (key_pressed[BKS_W])
    {
      cam->pos.x += MOVE * cos(cam->rot.z);
      cam->pos.y += MOVE * sin(cam->rot.z);
    }
  if (key_pressed[BKS_S])
    {
      cam->pos.x -= MOVE * cos(cam->rot.z);
      cam->pos.y -= MOVE * sin(cam->rot.z);
    }
  if (key_pressed[BKS_D])
    {
      cam->pos.x -= MOVE * cos(cam->rot.z + M_PI / 2);
      cam->pos.y -= MOVE * sin(cam->rot.z + M_PI / 2);
    }
  if (key_pressed[BKS_A])
    {
      cam->pos.x += MOVE * cos(cam->rot.z + M_PI / 2);
      cam->pos.y += MOVE * sin(cam->rot.z + M_PI / 2);
    }
  if (key_pressed[BKS_R])
    cam->pos.z += MOVE;
  if (key_pressed[BKS_F])
    cam->pos.z -= MOVE;
}

static void	rot_cam(t_cam *cam, const bool *key_pressed)
{
  if (key_pressed[BKS_PAGEUP])
    cam->rot.x += ROT;
  if (key_pressed[BKS_PAGEDOWN])
    cam->rot.x -= ROT;
  if (key_pressed[BKS_DOWN])
    cam->rot.y += ROT;
  if (key_pressed[BKS_UP])
    cam->rot.y -= ROT;
  if (key_pressed[BKS_LEFT])
    cam->rot.z += ROT;
  if (key_pressed[BKS_RIGHT])
    cam->rot.z -= ROT;
}

void		interact_cam(t_cam *cam)
{
  const bool	*key_pressed;

  key_pressed = bunny_get_keyboard();
  move_cam(cam, key_pressed);
  rot_cam(cam, key_pressed);
}
