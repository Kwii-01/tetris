/*
** highscore.c for highscore in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sat Mar 18 18:28:27 2017 alexandre
** Last update Sat Mar 18 19:19:10 2017 alexandre
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>
#include "tetris.h"
#include "gnl.h"

int	write_new_highscore(char *str)
{
  int	fd;

  if ((fd = open("highscore", O_CREAT | O_WRONLY | O_TRUNC,
		 0644)) == -1)
    return (FATAL);
  write(fd, str, my_strlen(str));
  close(fd);
  return (0);
}

int	my_highscore_is(t_game *game, char *str)
{
  int	nb;

  nb = get_nbr(str);
  if (nb > game->score)
    game->highscore = nb;
  else
    {
      game->highscore = nb;
      if (write_new_highscore(my_itoa(game->score, BASE, 10)) == FATAL)
	return (FATAL);
    }
  free(str);
  return (0);
}

int	my_highscore(t_game *game)
{
  int	fd;
  char	*str;

  get_next_line(GNL_FREE);
  if ((fd = open("highscore", O_RDONLY)) == -1)
    return (FATAL);
  if ((str = get_next_line(fd)) == NULL)
    {
      close(fd);
      if (write_new_highscore(my_itoa(game->score, BASE, 10)) == FATAL)
	return (FATAL);
      game->highscore = game->score;
      return (0);
    }
  close(fd);
  return (my_highscore_is(game, str));
}
