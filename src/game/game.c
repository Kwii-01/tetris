/*
** game.c for tetris in /home/milasr/Current/PSU_2016_tetris/src/game
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Fri Mar 17 18:38:05 2017 Milas Robin
** Last update Wed Mar 22 10:28:00 2017 alexandre
*/

#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "tetris.h"

/*
** Clear all things that can be boring when return
** to the terminal
*/

void	finish(int sig)
{
  curs_set(1);
  echo();
  endwin();
  setting_term(NULL, 1);
  if (sig)
    exit(sig + 128);
}

int	init(t_game *game, char **env)
{
  srand(time(NULL));
  signal(SIGINT, finish);
  if (!initscr()
      || keypad(stdscr, TRUE) == ERR
      || nonl() == ERR
      || noecho() == ERR
      || cbreak() == ERR
      || curs_set(0) == ERR
      || setting_term(env, 0) == ERRO)
    return (84);
  if (clean_tetriminos(game) < 1)
    return (my_error("No valid tetriminos\n"));
  game->piece = the_piece(*game);
  game->state.pos.xpos = (game->state.pos.xmax / 2) - my_maxlen(*game->piece);
  if (game->state.pos.xpos < 0)
    game->state.pos.xpos = 0;
  if (realloc_full_table(game) < 0 ||
      init_map(game) < 0 ||
      my_colors() == ERR)
    return (84);
  return (0);
}

void	print_border(t_game *game)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  srand(time(NULL));
  attrset(COLOR_PAIR(rand() % 8 + 1) | WA_BOLD);
  while (y < game->state.pos.ymax + 2)
    {
      if (y == 0 || y == game->state.pos.ymax + 1)
	{
	  x = 0;
	  while (x < game->state.pos.xmax + 2)
	    {
	      mvaddch(MAP_POS_Y + y, MAP_POS_X + x, '%');
	      x += 1;
	    }
	}
      else
	{
	  mvaddch(MAP_POS_Y + y, MAP_POS_X, '%');
	  mvaddch(MAP_POS_Y + y, MAP_POS_X + game->state.pos.xmax + 1, '%');
	}
      y += 1;
    }
}

int	loop(t_game *game)
{
  int	nb;
  int	cycles;

  nb = 0;
  cycles = 999 * my_pow(0.8, game->level);
  while (1)
    {
      print_border(game);
      if (commands(game) < 0)
	return (FATAL);
      usleep(1000);
      if (nb >= cycles)
	{
	  if (!can_go_down(game->map, game->state.pos.ymax,
			   game->state.pos.xmax))
	    return (final_map(game));
	  move_down(game->map, game->state.pos.ymax, game->state.pos.xmax);
	  nb = 0;
	}
      print_map(game->map, game->state.pos.ymax, game->state.pos.xmax);
      refresh();
      nb = nb + 1;
    }
  return (0);
}

int	my_tetris(t_game *game, char **env)
{
  if (init(game, env) < 0)
    return (84);
  while (1)
    {
      game->next_piece = the_piece(*game);
      if (print_inform(game) == FATAL)
	return (FATAL);
      if (launch_tetriminos(game, game->piece) < 0)
	{
	  finish(0);
	  return (0);
	}
      print_border(game);
      print_map(game->map, game->state.pos.ymax, game->state.pos.xmax);
      game->tlines += full_lines(game);
      refresh();
      if (loop(game) == FATAL)
	return (FATAL);
      game->piece = game->next_piece;
      clear();
    }
  finish(0);
  return (0);
}
