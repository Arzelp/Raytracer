/*
** my_epurstr.c for my in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Apr 21 15:21:28 2016 Arthur Josso
** Last update Thu Apr 21 15:46:51 2016 Arthur Josso
*/

static void	epur_from(char *s)
{
  int		i;
  int		j;

  i = 0;
  while (s[i] && (s[i] == ' ' || s[i] == '\t'))
    i++;
  j = 0;
  while (s[i])
    s[j++] = s[i++];
  s[j] = '\0';
}

void	my_epurstr(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] == ' ' || s[i] == '\t')
	{
	  if (s[i] == '\t')
	    s[i] = ' ';
	  if (i)
	    epur_from(s + i + 1);
	  else
	    epur_from(s + i);
	  if (!s[i + 1])
	    s[i] = '\0';
	}
      i++;
    }
}
