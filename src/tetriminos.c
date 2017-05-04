/*
** tetriminos.c for tetris in /home/robin.milas/Current/PSU_2016_tetris
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Thu Mar  2 15:19:23 2017 Robin MILAS
** Last update Thu Mar  2 15:56:24 2017 Robin MILAS
*/

#include <stdlib.h>
#include "tetris.h"

char	tetriminos_is_valid(t_shape *shape, char need_content)
{
  if (shape->width <= 0 || shape->height <= 0 ||
      shape->color < 0 || (shape->shape == NULL && need_content))
    return (0);
  return (1);
}
