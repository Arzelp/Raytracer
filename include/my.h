/*
** my.h for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 15:29:45 2016 Arthur Josso
** Last update Wed Mar 16 11:55:42 2016 Arthur Josso
*/

#ifndef MY_H_
# define MY_H_

#include <lapin.h>

#define BUFF_SIZE (10)

int     my_strcmp(char *s1, char *s2);
int     get_nbr(char *s);
double  get_double(char *s);
t_color get_pixel(t_bunny_pixelarray *pix,
		  t_bunny_position *pos);

#endif
