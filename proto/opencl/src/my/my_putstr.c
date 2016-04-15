/*
** my_putstr.c for Day 4 Exercice 3 in /home/alies_a/rendu/Piscine_C_J04
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Oct  1 11:53:30 2015 Arnaud Alies
** Last update Fri Nov 27 14:07:32 2015 Arnaud Alies
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(const char *str)
{
  return (write(1, str, my_strlen(str)));
}
