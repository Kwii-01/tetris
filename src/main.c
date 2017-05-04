/*
** main.c for main in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Feb 21 18:26:19 2017 alexandre
** Last update Sun Mar 19 22:29:52 2017 alexandre
*/

#include <curses.h>
#include <unistd.h>
#include "tetris.h"

int	my_help(char **av)
{
  my_printf("Usage:  %s [options]\n", av[0]);
  write(1, OPTIONS, my_strlen(OPTIONS));
  write(1, HELP, my_strlen(HELP));
  write(1, LEVEL, my_strlen(LEVEL));
  write(1, LEFT, my_strlen(LEFT));
  write(1, RIGHT, my_strlen(RIGHT));
  write(1, TURN, my_strlen(TURN));
  write(1, DROP, my_strlen(DROP));
  write(1, QUIT, my_strlen(QUIT));
  write(1, PAUSE, my_strlen(PAUSE));
  write(1, MAPSIZE, my_strlen(MAPSIZE));
  write(1, NEXT, my_strlen(NEXT));
  write(1, DEBUG, my_strlen(DEBUG));
  return (1);
}

int	flag_help(char **av)
{
  int	nb;

  nb = 0;
  while (av[nb] != NULL)
    {
      if (my_strcmp(av[nb], "-h") == 1 || my_strcmp(av[nb], "--help") == 1)
	return (my_help(av));
      nb = nb + 1;
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_game	game;
  int		ret;

  ac = ac;
  if (flag_help(av) == 1)
    return (0);
  if (setting_term(env, 0) == ERRO)
    return (ERRO);
  if (get_shapes(&(game.shapes)) == ERRO)
    return (ERRO);
  if ((ret = flags_handler(av, &game)) == ERRO)
    return (ERRO);
  if (ret == 1)
    if (debuger(av, &game) == ERRO)
      return (ERRO);
  if (setting_term(env, 1) == ERRO)
    return (ERRO);
  if (my_tetris(&game, env) == ERRO)
    return (ERRO);
  if (setting_term(env, 1) < 0)
    return (ERRO);
  return (0);
}
