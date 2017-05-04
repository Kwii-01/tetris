/*
** remove_line.c for tetris in /home/milasr/Current/PSU_2016_tetris/src/game
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sat Mar 18 18:36:26 2017 Milas Robin
** Last update Sun Mar 19 19:44:44 2017 Milas Robin
*/

#include "tetris.h"

void	remove_line(t_game *game, int line)
{
  char	*tmp;
  int	index;

  tmp = game->map[line];
  while (line > 0)
    {
      game->map[line] = game->map[line - 1];
      line -= 1;
    }
  game->map[0] = tmp;
  index = 0;
  while (index < game->state.pos.xmax)
    {
      game->map[0][index] = EMPTY;
      index += 1;
    }
  print_map(game->map, game->state.pos.ymax, game->state.pos.xmax);
}

int	full_lines(t_game *game)
{
  int	index_h;
  int	index_w;
  char	full;
  int	res;

  res = 0;
  index_h = 0;
  while (index_h < game->state.pos.ymax)
    {
      full = 1;
      index_w = 0;
      while (index_w < game->state.pos.xmax)
	{
	  full = (game->map[index_h][index_w] == EMPTY ||
		  game->map[index_h][index_w] < 8) ? 0 : full;
	  index_w += 1;
	}
      if (full)
	{
	  remove_line(game, index_h);
	  res += 1;
	}
      index_h += 1;
    }
  return (res);
}
