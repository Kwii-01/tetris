/*
** print_next.c for print_next in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sun Mar 19 04:40:46 2017 alexandre
** Last update Sun Mar 19 13:29:07 2017 Robin MILAS
*/

#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"

int	print_next(t_shape *piece, int x, int y)
{
  int	nb;
  int	col;

  nb = 0;
  mvprintw(nb + y, x, "Next: ");
  x = x + 8;
  while (nb != piece->height)
    {
      col = 0;
      while (col != piece->width)
	{
	  if (piece->shape[nb][col] != EMPTY)
	    mvprintw(nb + y, col + x, "#");
	  else
	    mvprintw(nb + y, col + x, " ");
	  col = col + 1;
	}
      nb = nb + 1;
    }
  return (0);
}
