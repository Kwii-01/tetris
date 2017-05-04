/*
** debuger.c for debuger in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sat Feb 25 03:26:28 2017 alexandre
** Last update Sun Mar 19 14:35:29 2017 Milas Robin
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

static void	print_tetriminos_content(t_shape *get)
{
  int		nb;

  my_printf("%s Name %s : Size %d*%d : Color %d :\n", TETRIMINOS,
	    get->name, get->width, get->height, get->color);
  nb = 0;
  while (get->shape[nb] != NULL)
    {
      my_printf("%s\n", get->shape[nb]);
      nb = nb + 1;
    }
}

static void	print_tetriminos(t_game *game)
{
  t_shape	*get;

  get = game->shapes.first;
  while (get)
    {
      if (get->name == NULL)
	my_printf("%sUnamed : Error (This should never occurred\n",
		  TETRIMINOS, get->name);
      else if (tetriminos_is_valid(get, 1))
	print_tetriminos_content(get);
      else
	my_printf("%s Name %s : Error\n", TETRIMINOS, get->name);
      get = get->next;
    }
}

/*
** gonna put this at the norm and need a sort_param for alphabetical
** order and display Error
*/

void	debug_mode(t_game *game)
{
  my_printf(DEBUG_MODE);
  my_printf("%s %s\n", KEY_LEFTS, game->key.left);
  my_printf("%s %s\n", KEY_RIGHTS, game->key.right);
  my_printf("%s %s\n", KEY_TURN, game->key.turn);
  my_printf("%s %s\n", KEY_DROP, game->key.drop);
  my_printf("%s %s\n", KEY_QUIT, game->key.quit);
  my_printf("%s %s\n", KEY_PAUSE, game->key.pause);
  if (game->next == 0)
    my_printf("%s Yes\n", NEXT_MODE);
  else
    my_printf("%s No\n", NEXT_MODE);
  my_printf("%s %d\n", LEVEL_MODE, game->level);
  my_printf("%s %d*%d\n", SIZE_MODE,
	    game->state.pos.xmax, game->state.pos.ymax);
  my_printf("%s %d\n", TETRIMINOS, game->shapes.len);
  print_tetriminos(game);
  my_printf("%s", PRESS);
}

int	debuger(char **av, t_game *game)
{
  int	nb;
  char	c;

  nb = 1;
  while (av[nb] != NULL)
    {
      if (my_strcmp("-d", av[nb]) == 1 || my_strcmp("--debug", av[nb]) == 1)
	{
	  debug_mode(game);
	  while (read(0, &c, 1) <= 0);
	  return (0);
	}
      nb = nb + 1;
    }
  return (0);
}
