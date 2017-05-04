/*
** my_tabcat.c for my_tabcat in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/finder_termi
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Mon Feb 20 20:52:42 2017 alexandre
** Last update Tue Feb 28 10:51:56 2017 alexandre
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

int	my_tablen(char **tab)
{
  int	nb;

  nb = 0;
  if (tab == NULL)
    return (0);
  while (tab[nb] != NULL)
    nb = nb + 1;
  return (nb);
}

char	**my_tabcat(char **src, char *str)
{
  char	**new;
  int	nb;

  if ((new = malloc(sizeof(char *) *
		    (my_strlen(str) + my_tablen(src) + 2))) == NULL)
    return (NULL);
  nb = 0;
  if (src != NULL)
    {
      while (src[nb] != NULL)
	{
	  new[nb] = src[nb];
	  nb = nb + 1;
	}
    }
  if ((new[nb] = my_strcpy(new[nb], str)) == NULL)
    return (src);
  new[nb + 1] = NULL;
  return (new);
}
