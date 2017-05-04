/*
** err.c for tetris in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Mar 14 16:48:28 2017 alexandre
** Last update Fri Mar 24 11:24:06 2017 alexandre
*/

#include <unistd.h>
#include "tetris.h"

int	my_error(char *str)
{
  int	len;

  while (str[len])
    len += 1;
  write(2, str, len);
  return (ERRO);
}
