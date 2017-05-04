/*
** my_strcpy.c for my_strcpy in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Thu Feb 23 18:14:29 2017 alexandre
** Last update Thu Feb 23 18:23:20 2017 alexandre
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

char	*my_strcpy(char *str, char *dest)
{
  int	nb;

  nb = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(dest) + 1))) == NULL)
    return (NULL);
  while (dest[nb] != '\0')
    {
      str[nb] = dest[nb];
      nb = nb + 1;
    }
  str[nb] = '\0';
  return (str);
}
