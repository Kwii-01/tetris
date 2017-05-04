/*
** my_strlen.c for my_strlen in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/tools
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Feb 21 19:10:49 2017 alexandre
** Last update Tue Feb 21 19:11:30 2017 alexandre
*/

int	my_strlen(char *str)
{
  int	nb;

  nb = 0;
  while (str[nb] != '\0')
    nb = nb + 1;
  return (nb);
}
