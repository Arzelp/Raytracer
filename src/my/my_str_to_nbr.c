/*
** my_str_to_nbr.c for string to number in /home/alies_a/libmy
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Oct 21 15:17:43 2015 Arnaud Alies
** Last update Fri Dec 11 21:29:35 2015 Arnaud Alies
*/

#include "my.h"

int     my_compute(int len, const char *str, int *mul, int *result)
{
  int   add;

  add = 0;
  if (str[len] >= '0' && str[len] <= '9')
    {
      add = *mul * (str[len] - '0');
      *result += add;
      *mul *= 10;
    }
  return (0);
}

int     my_str_to_nbr(const char *str)
{
  int   result;
  int   len;
  int   mul;

  result = 0;
  mul = 1;
  len = my_strlen(str) - 1;
  while (len + 1 > 0)
    {
      my_compute(len, str, &mul, &result);
      len -= 1;
    }
  if (str[0] == '-')
    result = -result;
  return (result);
}
