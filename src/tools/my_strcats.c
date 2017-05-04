/*
** my_strcats.c for my_strcats in /home/kiwiv2/epitech/PSU/minishell1/tools
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Thu Jan 19 00:47:11 2017 alexandre
** Last update Tue Feb 21 19:43:10 2017 alexandre
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

char	*my_strcat(char *path, char *func)
{
  char	*new;
  int	nb;
  int	x;

  if ((new = malloc(sizeof(char) *
		    (my_strlen(path) + my_strlen(func) + 1))) == NULL)
    return (NULL);
  nb = 0;
  x = 0;
  if (path != NULL)
    {
      while (path[nb] != '\0')
	{
	  new[nb] = path[nb];
	  nb = nb + 1;
	}
    }
  while (func[x] != '\0')
    {
      new[nb] = func[x];
      nb = nb + 1;
      x = x + 1;
    }
  new[nb] = '\0';
  return (new);
}
