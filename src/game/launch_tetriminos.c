/*
** my_tetris.c for my_tetris in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Mar 14 17:09:01 2017 alexandre
** Last update Sun Mar 19 19:06:55 2017 Milas Robin
*/

#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "tetris.h"

/*
** Choose randomly the tetrimino
*/

t_shape		*the_piece(t_game game)
{
  t_shape	*piece;
  int		nb;
  int		count;

  count = 0;
  piece = game.shapes.first;
  nb = (rand() % (game.shapes.len - 0) + 0);
  while (piece != NULL)
    {
      if (nb == count && piece->height != -1)
	return (piece);
      else if (nb == count && piece->height == -1)
	return (the_piece(game));
      count = count + 1;
      piece = piece->next;
    }
  return (piece);
}

int	launch_tetriminos(t_game *game, t_shape *piece)
{
  int	row;
  int	col;
  int	nb;
  int	offset;

  offset = game->state.pos.xmax / 2 - piece->width / 2;
  row = 0;
  nb = 0;
  while (piece->shape[row] != NULL)
    {
      col = 0;
      while (col != piece->width)
	{
	  if (piece->shape[row][col] != EMPTY)
	    {
	      if (game->map[row][col + offset] == EMPTY)
		game->map[row][col + offset] = piece->color;
	      else
		return (-1);
	    }
	  col = col + 1;
	}
      row = row + 1;
    }
  return (nb);
}

int	my_maxlen(t_shape piece)
{
  int		max;
  int		y;
  int		x;

  y = 0;
  max = 0;
  while (piece.shape[y] != NULL)
    {
      x = 0;
      while (x != piece.width)
	x = x + 1;
      if (x > max)
	max = x;
      y = y + 1;
    }
  max = max / 2;
  return (max);
}
