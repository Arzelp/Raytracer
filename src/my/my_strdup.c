/*
** my_strdup.c for strdup in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct  7 20:58:21 2015 Arnaud Alies
** Last update Sat Dec 12 14:43:13 2015 Arnaud Alies
*/

#include <stdlib.h>
#include <lapin.h>
#include "my.h"

char    *my_strdup(const char *src)
{
  char	*dest;

  dest = bunny_malloc(sizeof(char) * (my_strlen(src) + 1));
  if (dest == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
