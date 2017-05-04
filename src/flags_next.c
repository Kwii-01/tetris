/*
** flags_next.c for flags_next in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Fri Feb 24 16:10:22 2017 alexandre
** Last update Tue Mar 14 12:31:24 2017 alexandre
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

int	level_next(t_game *game, char *str)
{
  char	*nbr;
  int	nb;
  int	num;

  nb = 0;
  nbr = NULL;
  while (str[nb] != '\0' && str[nb] != '=')
    nb = nb + 1;
  if (str[nb] != '=')
    return (ERRO);
  nb = nb + 1;
  if ((nbr = my_cpy_atm(nbr, str, nb)) == NULL)
    return (ERRO);
  if ((num = get_nbr(nbr)) <= 0)
    {
      free(nbr);
      return (ERRO);
    }
  free(nbr);
  game->level = num;
  return (0);
}

int	quit_longflag(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && (my_strcmp("--key-quit=", av[nb]) != 1))
    nb = nb + 1;
  if (av[nb] == NULL)
    return (ERRO);
  if ((game->key.quit = puts_longkeys(av[nb])) == NULL)
    return (ERRO);
  return (0);
}

int	pause_longflag(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && (my_strcmp("--key-pause=", av[nb]) != 1))
    nb = nb + 1;
  if (av[nb] == NULL)
    return (ERRO);
  if ((game->key.pause = puts_longkeys(av[nb])) == NULL)
    return (ERRO);
  return (0);
}

int	map_set(t_game *game, char **av)
{
  int	nb;
  int	count;

  nb = 0;
  count = 0;
  while (av[nb] != NULL && my_strcmp("--map-size=", av[nb]) != 1)
    nb = nb + 1;
  if (av[nb] == NULL)
    return (ERRO);
  while (av[nb][count] != '\0' && av[nb][count] != '=')
    count = count + 1;
  count = count + 1;
  if ((game->state.pos.xmax = get_nbr_atm(av[nb], count)) <= 0)
    return (ERRO);
  while (av[nb][count] != '\0' && av[nb][count] != ',')
    count = count + 1;
  if (av[nb][count] == '\0')
    return (ERRO);
  count = count + 1;
  if ((game->state.pos.ymax = get_nbr_atm(av[nb], count)) <= 0)
    return (ERRO);
  return (0);
}

int	next_set(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && (my_strcmp(av[nb], "-w") != 1 &&
			    my_strcmp("--without-next", av[nb]) != 1))
    nb = nb + 1;
  if (av[nb] == NULL)
    return (ERRO);
  game->next = 1;
  return (0);
}
