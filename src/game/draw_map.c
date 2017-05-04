/*
** draw_map.c for tetris in /home/milasr/Current/PSU_2016_tetris/src/game
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sat Mar 18 19:37:42 2017 Milas Robin
** Last update Sun Mar 19 18:36:40 2017 Milas Robin
*/

#include <ncurses.h>
#include "tetris.h"

void	print_cell(char cell, int x, int y)
{
  if (cell == EMPTY)
    {
      attrset(COLOR_PAIR(0));
      mvaddch(MAP_POS_Y + y + 1, MAP_POS_X + x + 1, '.');
    }
  else if (cell < 8)
    {
      attrset(COLOR_PAIR(cell + 1));
      mvaddch(MAP_POS_Y + y + 1, MAP_POS_X + x + 1, '%');
    }
  else
    {
      attrset(COLOR_PAIR(cell - 8 + 1));
      mvaddch(MAP_POS_Y + y + 1, MAP_POS_X + x + 1, '#');
    }
}

void	print_map(char **map, int height, int width)
{
  int	x;
  int	y;

  y = 0;
  while (y < height)
    {
      x = 0;
      while (x < width)
	{
	  print_cell(map[y][x], x, y);
	  x += 1;
	}
      y += 1;
    }
}
