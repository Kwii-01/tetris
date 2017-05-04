/*
** get_nbr.c for get_nbr in /home/kiwiv2/epitech/CSFML/raytracer1/tools
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Sun Feb 12 16:10:35 2017 alexandre
** Last update Wed Mar  1 22:31:01 2017 alexandre
*/

#include <unistd.h>

int	get_nbr_stat(char *str)
{
  static int	nb = 0;
  int		num;
  int		neg;

  num = 0;
  neg = 1;
  if (str == NULL)
    return (0);
  if (str[nb] == '\0')
    nb = 0;
  if (str[nb] == '-')
    neg = -neg;
  while (str[nb] != '\0' && (str[nb] >= 48 && str[nb] <= 57))
    {
      num = (10 * num) + (str[nb] - 48);
      nb = nb + 1;
    }
  num = num * neg;
  if (str[nb] != ' ' && str[nb] != '\0')
    return (-1);
  if (str[nb] == ' ' && str[nb] != '\0')
    nb = nb + 1;
  return (num);
}

int	get_nbr(char *str)
{
  int	nb;
  int	num;
  int	neg;

  num = 0;
  nb = 0;
  neg = 1;
  while (str[nb] != '\0' && (str[nb] == '-' || str[nb] == '+'))
    {
      if (str[nb] == '-')
	neg = -neg;
      nb = nb + 1;
    }
  while (str[nb] != '\0' && (str[nb] >= 48 && str[nb] <= 57))
    {
      num = (10 * num) + (str[nb] - 48);
      nb = nb + 1;
    }
  if (str[nb] != '\0')
    return (-1);
  num = num * neg;
  return (num);
}

int	get_nbr_atm(char *str, int nb)
{
  int	num;

  num = 0;
  if (str == NULL || str[nb] == '\0')
    return (-1);
  if (str[nb] < '0' || str[nb] > '9')
    return (-1);
  while (str[nb] >= '0' && str[nb] <= '9')
    {
      num = (10 * num) + (str[nb] - 48);
      nb = nb + 1;
    }
  return (num);
}
