/*
** simpleflag_next.c for simpleflag_next in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Mar 14 13:04:18 2017 alexandre
** Last update Tue Mar 14 13:11:52 2017 alexandre
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

int	quit_simpl(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && my_strcmp(av[nb], "-kq") != 1)
    nb = nb + 1;
  if (av[nb] == NULL || av[nb + 1] == NULL)
    return (ERRO);
  if ((game->key.quit = my_strcpy(NULL, av[nb + 1])) == NULL)
    return (ERRO);
  return (0);
}

int	pause_simpl(t_game *game, char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL && my_strcmp(av[nb], "-kp") != 1)
    nb = nb + 1;
  if (av[nb] == NULL || av[nb + 1] == NULL)
    return (ERRO);
  if ((game->key.pause = my_strcpy(NULL, av[nb + 1])) == NULL)
    return (ERRO);
  return (0);
}
