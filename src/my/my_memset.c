/*
** my_memset.c for my_memset in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Mar  7 13:08:49 2016 alies_a
** Last update Mon Mar  7 13:09:18 2016 alies_a
*/

#include <stddef.h>

void            my_memset(void *s, char c, size_t n)
{
  size_t        x;

  x = 0;
  while (x < n)
    {
      ((char*)s)[x] = c;
      x += 1;
    }
}
