/*
** my_cpy_atm.c for my_cpy_atm in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Thu Feb 23 12:15:04 2017 alexandre
** Last update Thu Feb 23 12:31:03 2017 alexandre
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

char	*my_cpy_atm(char *str, char *src, int nb)
{
  int	get;

  get = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(src) - nb + 1))) == NULL)
    return (NULL);
  while (src[nb + get] != '\0')
    {
      str[get] = src[nb + get];
      get = get + 1;
    }
  str[get] = '\0';
  return (str);
}
