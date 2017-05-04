/*
** init.c for tetris in /home/milasr/Current/PSU_2016_tetris/src/game
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Fri Mar 17 18:56:27 2017 Milas Robin
** Last update Sun Mar 19 13:25:14 2017 Robin MILAS
*/

#include <stdlib.h>
#include "tetris.h"

int		clean_tetriminos(t_game *game)
{
  t_shape	**tmp;
  t_shape	*f;

  tmp = &(game->shapes.first);
  while (*tmp != NULL)
    {
      if ((*tmp)->height < 0 || (*tmp)->width < 0 ||
	  (*tmp)->color < 0 || (*tmp)->name == NULL ||
	  (*tmp)->height > game->state.pos.ymax ||
	  (*tmp)->width > game->state.pos.xmax)
	{
	  f = *tmp;
	  *tmp = (*tmp)->next;
	  free(f->name);
	  free(f);
	  game->shapes.len -= 1;
	}
      else
	{
	  tmp = &((*tmp)->next);
	}
    }
  return (game->shapes.len);
}

void	realloc_full_table_line(t_shape *shape, char *t, int line)
{
  char	end;
  int	index;

  end = 0;
  index = 0;
  while (index < shape->width)
    {
      if (end || shape->shape[line][index] == '\0')
	{
	  end = 1;
	  t[index] = EMPTY;
	}
      else if (shape->shape[line][index] == '*')
	{
	  t[index] = shape->color;
	}
      else
	{
	  t[index] = EMPTY;
	}
      index += 1;
    }
}

int		realloc_full_table(t_game *game)
{
  t_shape	*shape;
  char		*line;
  int		h;

  shape = game->shapes.first;
  while (shape != NULL)
    {
      h = 0;
      while (h < shape->height)
	{
	  if ((line = malloc(shape->width)) == NULL)
	    return (84);
	  realloc_full_table_line(shape, line, h);
	  free(shape->shape[h]);
	  shape->shape[h] = line;
	  h += 1;
	}
      shape = shape->next;
    }
  return (0);
}

int	init_map(t_game *game)
{
  int	h;
  int	w;

  if ((game->map = malloc(sizeof(*(game->map)) *
			  (game->state.pos.ymax))) == NULL)
    return (84);
  h = 0;
  while (h < game->state.pos.ymax)
    {
      if ((game->map[h] = malloc(sizeof(**(game->map)) *
				 (game->state.pos.xmax))) == NULL)
	return (84);
      w = 0;
      while (w < game->state.pos.xmax)
	{
	  game->map[h][w] = EMPTY;
	  w += 1;
	}
      h += 1;
    }
  return (0);
}
