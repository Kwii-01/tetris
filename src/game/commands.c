/*
** commands.c for commands in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src/game
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sun Mar 19 20:32:14 2017 alexandre
** Last update Sun Mar 19 23:25:39 2017 alexandre
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

void	my_pause(t_game *game)
{
  char	buf[11];
  int	size;

  while (42)
    {
      if ((size = read(0, &buf, 10)) < 0)
	return ;
      buf[size] = '\0';
      if (my_strcmp2(buf, game->key.pause) == 0)
	return ;
    }
}

int	commands(t_game *game)
{
  char	buf[11];
  int	size;

  if ((size = read(0, &buf, 10)) < 0)
    return (0);
  buf[size] = '\0';
  if (my_strcmp2(buf, game->key.left) == 0 &&
      can_go_left(game->map, game->state.pos.ymax, game->state.pos.xmax))
    move_left(game->map, game->state.pos.ymax, game->state.pos.xmax);
  else if (my_strcmp2(buf, game->key.right) == 0 &&
	   can_go_right(game->map, game->state.pos.ymax, game->state.pos.xmax))
    move_right(game->map, game->state.pos.ymax, game->state.pos.xmax);
  else if (my_strcmp2(buf, game->key.drop) == 0 &&
	   can_go_down(game->map, game->state.pos.ymax, game->state.pos.xmax))
    move_down(game->map, game->state.pos.ymax, game->state.pos.xmax);
  else if (my_strcmp2(buf, game->key.quit) == 0)
    return (-1);
  else if (my_strcmp2(buf, game->key.pause) == 0)
    my_pause(game);
  return (0);
}
