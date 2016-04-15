/*
** my_strcat.c for my_strcat in /home/alies_a/rendu/Piscine_C_J07
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Oct  6 11:29:54 2015 Arnaud Alies
** Last update Wed Oct  7 21:09:51 2015 Arnaud Alies
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	len;
  int	x;

  x = 0;
  len = my_strlen(dest);
  while (src[x] != '\0')
    {
      dest[x + len] = src[x];
      x += 1;
    }
  dest[x + len] = '\0';
  return (dest);
}
