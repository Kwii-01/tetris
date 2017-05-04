/*
** flags_handler.c for flags_handler in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Thu Feb 23 20:13:56 2017 alexandre
** Last update Sat Mar 18 16:22:35 2017 alexandre
*/

#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

struct	s_tab g_longflag []=
  {
    {"--level=", &level_longflag},
    {"--key-left=", &left_longflag},
    {"--key-right=", &right_longflag},
    {"--key-turn=", &turn_longflag},
    {"--key-drop=", &drop_longflag},
    {"--key-quit=", &quit_longflag},
    {"--key-pause=", &pause_longflag},
    {"--map-size=", &map_set},
    {"-w", &next_set},
    {"--without-next", &next_set}
  };

struct	s_tab g_simpleflag []=
  {
    {"-l", &level_simpl},
    {"-kl", &left_simpl},
    {"-kr", &right_simpl},
    {"-kd", &drop_simpl},
    {"-kt", &turn_simpl},
    {"-kq", &quit_simpl},
    {"-kp", &pause_simpl},
  };

char	*puts_longkeys(char *str)
{
  char	*key;
  int	nb;

  nb = 0;
  key = NULL;
  while (str[nb] != '\0' && str[nb] != '=')
    nb = nb + 1;
  if (str[nb] != '=')
    return (NULL);
  nb = nb + 1;
  if (str[nb] == '\0')
    return (NULL);
  if ((key = my_cpy_atm(key, str, nb)) == NULL)
    return (NULL);
  return (key);
}

/*
** we have to get the "sequence" of keys and not to declare in rude
*/

void	basics_param(t_game *game)
{
  game->key.left = tigetstr("kcub1");
  game->key.right = tigetstr("kcuf1");
  game->key.turn = tigetstr("kcuu1");
  game->key.drop = tigetstr("kcud1");
  game->key.quit = "q";
  game->key.pause = " ";
  game->level = 1;
  game->tlines = 0;
  game->score = 0;
  game->state.pos.xmax = 20;
  game->state.pos.ymax = 10;
  game->next = 0;
}

/*
** just a little part of the flags_handler
*/

int	my_longflags(t_game *game, char **av, int *nb)
{
  int	count;

  count = 0;
  while (count < 10)
    {
      if (my_strcmp(g_longflag[count].name, av[*nb]) == 1)
	{
	  if (g_longflag[count].flags(game, av) == ERRO)
	    return (ERRO);
	  *nb = *nb + 1;
	  return (1);
	}
      count = count + 1;
    }
  return (0);
}

int	my_simpleflags(t_game *game, char **av, int *nb)
{
  int	count;

  count = 0;
  while (count < 7)
    {
      if (my_strcmp(av[*nb], g_simpleflag[count].name) == 1)
	{
	  if (g_simpleflag[count].flags(game, av) == ERRO)
	    return (ERRO);
	  *nb = *nb + 2;
	  return (1);
	}
      count = count + 1;
    }
  return (0);
}

int	flags_handler(char **av, t_game *game)
{
  int	ret;
  int	nb;
  int	count;
  int	final;

  nb = 1;
  final = 0;
  basics_param(game);
  while (av[nb] != NULL)
    {
      count = 0;
      if ((ret = my_longflags(game, av, &nb)) == ERRO)
	return (my_error("Invalid parameter(s)\n"));
      if (ret == 0)
	if ((count = my_simpleflags(game, av, &nb)) == ERRO)
	  return (my_error("Invalid parameter(s)\n"));
      if (my_strcmp("-d", av[nb]) == 1 || my_strcmp(av[nb], "--debug") == 1)
	{
	  nb = nb + 1;
	  final = 1;
	}
      else if (count == 0 && ret == 0)
	return (my_error("Invalid parameter(s)\n"));
    }
  return (final);
}
