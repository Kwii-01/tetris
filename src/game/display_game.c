/*
** display_game.c for display_game in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src/game
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Mar 14 21:05:38 2017 alexandre
** Last update Sun Mar 19 18:35:01 2017 Milas Robin
*/

#include <ncurses.h>
#include "tetris.h"

int	my_colors()
{
  if (start_color() == ERR)
    return (ERRO);
  if (init_pair(1, COLOR_WHITE, COLOR_BLACK) == ERR)
    return (ERRO);
  if (init_pair(2, COLOR_WHITE, COLOR_WHITE) == ERR)
    return (ERRO);
  if (init_pair(3, COLOR_RED, COLOR_RED) == ERR)
    return (ERRO);
  if (init_pair(4, COLOR_GREEN, COLOR_GREEN) == ERR)
    return (ERRO);
  if (init_pair(5, COLOR_YELLOW, COLOR_YELLOW) == ERR)
    return (ERRO);
  if (init_pair(6, COLOR_BLUE, COLOR_BLUE) == ERR)
    return (ERRO);
  if (init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA) == ERR)
    return (ERRO);
  if (init_pair(8, COLOR_RED, COLOR_RED) == ERR)
    return (ERRO);
  return (0);
}
