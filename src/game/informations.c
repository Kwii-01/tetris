/*
** informations.c for informations in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src/game
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sat Mar 18 15:48:59 2017 alexandre
** Last update Sun Mar 19 04:54:32 2017 alexandre
*/

#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"

void	init_board(t_game *game)
{
  int	nb;
  int	count;

  nb = 0;
  count = 0;
  while (nb < game->state.pos.xmax - 1)
    {
      if (game->map[game->state.pos.ymax - 1][nb] == - 1)
	count = count + 1;
      nb = nb + 1;
    }
  if (count == 0)
    {
      game->score = game->score + 10;
      game->tlines = game->score / 10;
    }
  if (game->tlines != 0 && game->tlines % 10 == 0)
    game->level = game->level + 1;
}

char	*new_board(char *str, int max, char my, char side)
{
  char	*new;
  int	nb;

  nb = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + max + 1))) == NULL)
    return (NULL);
  while (str[nb] != '\0')
    {
      new[nb] = str[nb];
      nb = nb + 1;
    }
  while (nb < max)
    {
      new[nb] = my;
      nb = nb + 1;
    }
  new[nb] = side;
  new[nb + 1] = '\0';
  free(str);
  return (new);
}

char	*my_board_length(char **board, char *str)
{
  int	nb;
  int	max;

  nb = 0;
  max = 0;
  if ((str = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  while (board[nb] != NULL)
    {
      if (my_strlen(board[nb]) > max)
	max = my_strlen(board[nb]) + 2;
      nb = nb + 1;
    }
  nb = 0;
  while (board[nb] != NULL)
    {
      if (my_strlen(board[nb]) != max)
	if ((board[nb] = new_board(board[nb], max, ' ', '|')) == NULL)
	  return (NULL);
      nb = nb + 1;
    }
  str[0] = '+';
  str[1] = '\0';
  return (new_board(str, max, '-', '+'));
}

int	print_board(t_game *game, int x, int y)
{
  char	**board;
  char	*str;

  if ((board = malloc(sizeof(char *) * 6)) == NULL)
    return (FATAL);
  board[0] = my_strcat(HIGHTSCORE, my_itoa(game->highscore, BASE, 10));
  board[1] = my_strcat(SCORE, my_itoa(game->score, BASE, 10));
  board[2] = my_strcat(LINES_BOARD, my_itoa(game->tlines, BASE, 10));
  board[3] = my_strcat(LEVEL_BOARD, my_itoa(game->level, BASE, 10));
  board[4] = my_strcat(TIMER, my_itoa(1, BASE, 10));
  board[5] = NULL;
  if ((str = my_board_length(board, NULL)) == NULL)
    return (FATAL);
  mvprintw(y + 1, x, str);
  while (board[y] != NULL)
    {
      mvprintw(y + 2, x, board[y]);
      free(board[y]);
      y = y + 1;
    }
  mvprintw(y + 2, x, str);
  free(str);
  free(board);
  return (0);
}

int	print_inform(t_game *game)
{
  int	x;
  int	y;

  x = game->state.pos.xmax + 5;
  y = 0;
  init_board(game);
  if (my_highscore(game) == FATAL)
    return (FATAL);
  game->tlines = game->score / 10;
  if (print_board(game, x, y) == FATAL)
    return (FATAL);
  y = 10;
  if (game->next == 0)
    print_next(game->next_piece, x, y);
  return (0);
}
