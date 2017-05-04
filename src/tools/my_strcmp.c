/*
** my_strcmp.c for my_strcmp in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/finder_termi
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Mon Feb 20 19:49:14 2017 alexandre
** Last update Sun Mar 19 23:18:33 2017 Milas Robin
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strcmp(char *src, char *dest)
{
  int	count;
  int	nb;

  nb = 0;
  count = 0;
  if (src == NULL || dest == NULL)
    return (-1);
  while (src[count] != '\0')
    {
      if (src[count] == dest[count])
	nb = nb + 1;
      count = count + 1;
    }
  if (nb == count)
    return (1);
  return (-1);
}

int	my_endcmp(char *src, char *dest)
{
  int	count;
  int	nb;
  int	x;

  nb = 0;
  count = 0;
  x = 0;
  if (src == NULL || dest == NULL)
    return (-1);
  while (dest[x] != '\0')
    x = x + 1;
  x = x - 1;
  while (x > 0 && dest[x] != '.')
    x = x - 1;
  while (src[nb] != '\0')
    {
      if (src[nb] == dest[count + x])
	count = count + 1;
      nb = nb + 1;
    }
  if (nb == count && dest[count + x] == '\0')
    return (1);
  return (-1);
}

int	my_strcmp2(char *src, char *dest)
{
  int	count;

  count = 0;
  if (src == NULL || dest == NULL)
    return (-1);
  while (src[count] == dest[count])
    {
      if (src[count] == '\0')
	return (0);
      count += 1;
    }
  return (src[count] - dest[count]);
}
