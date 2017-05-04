/*
** flags.c for flags in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Fri Feb 24 16:02:33 2017 alexandre
** Last update Tue Mar 14 15:04:06 2017 alexandre
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

int	level_longflag(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && (my_strcmp("--level=", av[nb]) != 1))
    nb = nb + 1;
  if (av[nb] == NULL)
    return (ERRO);
  if (level_next(game, av[nb]) == ERRO)
    return (ERRO);
  return (0);
}

int	left_longflag(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && (my_strcmp("--key-left=", av[nb]) != 1))
    nb = nb + 1;
  if (av[nb] == NULL)
    return (ERRO);
  if ((game->key.left = puts_longkeys(av[nb])) == NULL)
    return (ERRO);
  return (0);
}

int	right_longflag(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && (my_strcmp("--key-right=", av[nb]) != 1))
    nb = nb + 1;
  if (av[nb] == NULL)
    return (ERRO);
  if ((game->key.right = puts_longkeys(av[nb])) == NULL)
    return (ERRO);
  return (0);
}

int	turn_longflag(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && (my_strcmp("--key-turn=", av[nb]) != 1))
    nb = nb + 1;
  if (av[nb] == NULL)
    return (ERRO);
  if ((game->key.turn = puts_longkeys(av[nb])) == NULL)
    return (ERRO);
  return (0);
}

int	drop_longflag(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && (my_strcmp(av[nb], "--key-drop=") != 1))
    nb = nb + 1;
  if (av[nb] == NULL)
    return (ERRO);
  if ((game->key.drop = puts_longkeys(av[nb])) == NULL)
    return (ERRO);
  return (0);
}
