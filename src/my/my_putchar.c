/*
** my_putchar.c for my_putchar in /home/alies_a/rendu/Piscine_C_J03
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Sep 30 10:59:18 2015 Arnaud Alies
** Last update Fri Nov 13 17:04:57 2015 Arnaud Alies
*/

#include <unistd.h>

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}
