/*
** set_term.c for set_term in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Feb 28 11:30:19 2017 alexandre
** Last update Sun Mar 19 21:56:54 2017 alexandre
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "tetris.h"

char	*find_term(char **env, char *term)
{
  int	nb;

  nb = 0;
  while (env[nb] != NULL)
    {
      if (my_strcmp(TERM, env[nb]) == 1)
	return (my_cpy_atm(term, env[nb], 5));
      nb = nb + 1;
    }
  return (NULL);
}

int	setting_term(char **env, char reset)
{
  static struct termios	oldt;
  struct termios	newt;
  char	*term;
  int	ret;
  int	set;

  if (reset == 1)
    return (ioctl(0, TCSETS, &oldt));
  term = NULL;
  if ((term = find_term(env, term)) == NULL)
    return (ERRO);
  if ((set = setupterm(term, 1, &ret)) == ERR)
    return (ERRO);
  if (ioctl(0, TCGETS, &oldt) == -1 || ioctl(0, TCGETS, &newt) == -1)
    return (ERRO);
  newt = oldt;
  newt.c_lflag &= ~ECHO;
  newt.c_lflag &= ~ICANON;
  newt.c_cc[VMIN] = 0;
  newt.c_cc[VTIME] = 0;
  if (ioctl(0, TCSETS, &newt) == -1)
    return (ERRO);
  free(term);
  return (0);
}
