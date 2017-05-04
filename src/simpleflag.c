/*
** simpleflag.c for simpleflag in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Mar 14 12:47:31 2017 alexandre
** Last update Sat Mar 18 16:54:07 2017 Milas Robin
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

int	level_simpl(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && my_strcmp(av[nb], "-l") != 1)
    nb = nb + 1;
  if (av[nb] == NULL || av[nb + 1] == NULL)
    return (ERRO);
  if ((game->level = get_nbr(av[nb + 1])) <= 0)
    return (ERRO);
  return (0);
}

int	left_simpl(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && my_strcmp(av[nb], "-kl") != 1)
    nb = nb + 1;
  if (av[nb] == NULL || av[nb + 1] == NULL)
    return (ERRO);
  if ((game->key.left = my_strcpy(NULL, av[nb + 1])) == NULL)
    return (ERRO);
  return (0);
}

int	right_simpl(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && my_strcmp(av[nb], "-kr") != 1)
    nb = nb + 1;
  if (av[nb] == NULL || av[nb + 1] == NULL)
    return (ERRO);
  if ((game->key.right = my_strcpy(NULL, av[nb + 1])) == NULL)
    return (ERRO);
  return (0);
}

int	turn_simpl(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && my_strcmp(av[nb], "-kt") != 1)
    nb = nb + 1;
  if (av[nb] == NULL || av[nb + 1] == NULL)
    return (ERRO);
  if ((game->key.turn = my_strcpy(NULL, av[nb + 1])) == NULL)
    return (ERRO);
  return (0);
}

int	drop_simpl(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && my_strcmp(av[nb], "-kd") != 1)
    nb = nb + 1;
  if (av[nb] == NULL || av[nb + 1] == NULL)
    return (ERRO);
  if ((game->key.drop = my_strcpy(NULL, av[nb + 1])) == NULL)
    return (ERRO);
  return (0);
}
