/*
** my_strcpy.c for Day 6 Exercice 2 in /home/alies_a/rendu/Piscine_C_J06/ex_02
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct  5 10:08:34 2015 Arnaud Alies
** Last update Thu Nov 19 15:59:19 2015 Arnaud Alies
*/

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}
