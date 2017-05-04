/*
** touch_something.c for touch_something in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src/game
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sun Mar 19 00:27:13 2017 alexandre
** Last update Sun Mar 19 00:41:11 2017 alexandre
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "tetris.h"

int	touch_cond(t_game game, int y, int x)
{
  if (y + 1 == game.state.pos.ymax)
    return (1);
  if (game.map[y + 1][x] >= 8 && game.map[y + 1][x] <= 15)
    return (1);
  return (0);
}

int	touch_something(t_game *game)
{
  int	y;
  int	x;

  y = 0;
  while (y != game->state.pos.ymax)
    {
      x = 0;
      while (x != game->state.pos.xmax)
	{
	  if (game->map[y][x] >= 0 && game->map[y][x] <= 7)
	    if (touch_cond(*game, y , x) == 1)
	      return (1);
	  x = x + 1;
	}
      y = y + 1;
    }
  return (0);
}
