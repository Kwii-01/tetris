/*
** down.c for tetris in /home/milasr/Current/PSU_2016_tetris/src/game
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sun Mar 19 13:55:24 2017 Milas Robin
** Last update Sun Mar 19 15:40:24 2017 Milas Robin
*/

#include "tetris.h"

int	can_go_down(char **map, int height, int width)
{
  int	x;
  int	y;

  y = 0;
  while (y < height)
    {
      x = 0;
      while (x < width)
	{
	  if (map[y][x] != EMPTY && map[y][x] < 8)
	    {
	      if (y + 1 >= height || map[y + 1][x] >= 8)
		return (0);
	    }
	  x += 1;
	}
      y += 1;
    }
  return (1);
}

void	move_down(char **map, int height, int width)
{
  int	x;
  int	y;

  y = height - 1;
  while (y >= 0)
    {
      x = 0;
      while (x < width)
	{
	  if (map[y][x] != EMPTY && map[y][x] < 8)
	    {
	      map[y + 1][x] = map[y][x];
	      map[y][x] = EMPTY;
	    }
	  x += 1;
	}
      y -= 1;
    }
}

int	final_map(t_game *game)
{
  int	y;
  int	x;

  y = 0;
  while (y != game->state.pos.ymax)
    {
      x = 0;
      while (x != game->state.pos.xmax)
	{
	  if (game->map[y][x] >= 0 && game->map[y][x] < 8)
	    game->map[y][x] = game->map[y][x] + 8;
	  x = x + 1;
	}
      y = y + 1;
    }
  return (0);
}
