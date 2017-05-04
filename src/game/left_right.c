/*
** down.c for tetris in /home/milasr/Current/PSU_2016_tetris/src/game
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sun Mar 19 13:55:24 2017 Milas Robin
** Last update Sun Mar 19 23:04:41 2017 alexandre
*/

#include "tetris.h"

int	can_go_left(char **map, int height, int width)
{
  int	x;
  int	y;

  x = 0;
  while (x < width)
    {
      y = 0;
      while (y < height)
	{
	  if (map[y][x] != EMPTY && map[y][x] < 8)
	    {
	      if (x - 1 < 0 || map[y][x - 1] >= 8)
		return (0);
	    }
	  y += 1;
	}
      x += 1;
    }
  return (1);
}

int	can_go_right(char **map, int height, int width)
{
  int	x;
  int	y;

  x = 0;
  while (x < width)
    {
      y = 0;
      while (y < height)
	{
	  if (map[y][x] != EMPTY && map[y][x] < 8)
	    {
	      if (x + 1 >= width || map[y][x + 1] >= 8)
		return (0);
	    }
	  y += 1;
	}
      x += 1;
    }
  return (1);
}

void	move_left(char **map, int height, int width)
{
  int	x;
  int	y;

  x = 0;
  while (x < width)
    {
      y = 0;
      while (y < height)
	{
	  if (map[y][x] != EMPTY && map[y][x] < 8)
	    {
	      map[y][x - 1] = map[y][x];
	      map[y][x] = EMPTY;
	    }
	  y += 1;
	}
      x += 1;
    }
}

void	move_right(char **map, int height, int width)
{
  int	x;
  int	y;

  x = width - 1;
  while (x >= 0)
    {
      y = 0;
      while (y < height)
	{
	  if (map[y][x] != EMPTY && map[y][x] < 8)
	    {
	      map[y][x + 1] = map[y][x];
	      map[y][x] = EMPTY;
	    }
	  y += 1;
	}
      x -= 1;
    }
}
