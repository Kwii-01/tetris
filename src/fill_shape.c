/*
** fill_shape.c for fill_shape in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Thu Feb 23 14:48:28 2017 alexandre
** Last update Tue Mar 14 22:26:10 2017 alexandre
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"
#include "gnl.h"

char	*fill_name(char *name)
{
  char	*str;
  int	count;
  int	nb;

  nb = my_strlen(name);
  count = my_strlen(name);
  while (count != 0 && name[count] != '.')
    count = count - 1;
  if ((str = malloc(sizeof(char) * ((nb - count) + 1))) == NULL)
    return (NULL);
  nb = 0;
  while (nb != count)
    {
      str[nb] = name[nb];
      nb = nb + 1;
    }
  str[nb] = '\0';
  return (str);
}

int	fill_header(t_shape *shape, char *str, int count)
{
  if (count != 2)
    {
      shape->height = -1;
      shape->width = -1;
      shape->color = -1;
      return (1);
    }
  if (parse_nb(&(shape->width), &str) != 0 ||
      *str != ' ')
    shape->width = -1;
  str += 1;
  if (parse_nb(&(shape->height), &str) != 0 ||
	   *str != ' ')
    shape->height = -1;
  str += 1;
  if (parse_nb(&(shape->color), &str) != 0 ||
	   *str != '\0' ||
	   shape->color > 7)
    shape->color = -1;
  get_nbr_stat(NULL);
  return (0);
}

int	header_read(t_shape *shape, int fd)
{
  char	*str;
  int	nb;
  int	count;
  int	res;

  nb = 0;
  count = 0;
  if ((str = get_next_line(fd)) == NULL)
    {
      shape->shape = NULL;
      shape->height = -1;
      return (1);
    }
  while (str[nb] != '\0')
    {
      if (str[nb] == ' ')
	count = count + 1;
      nb = nb + 1;
    }
  res = fill_header(shape, str, count);
  free(str);
  return (res);
}
