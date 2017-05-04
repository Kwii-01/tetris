/*
** get_shapes.c for get_shapes in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris/src
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Feb 21 19:18:32 2017 alexandre
** Last update Sun Mar 19 14:42:14 2017 Milas Robin
*/

#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "tetris.h"
#include "gnl.h"

static int	fill_shapes_data(t_shape *s, int fd)
{
  int		current;
  int		index;
  char		*str;

  if (tetriminos_is_valid(s, 0))
    {
      index = 0;
      if ((s->shape = malloc((sizeof(*(s->shape))) * (s->height + 1))) == NULL)
	return (FATAL);
      while ((str = get_next_line(fd)) != NULL && index < s->height)
	{
	  current = 0;
	  while (str[current] == ' ' ||
		 str[current] == '*')
	    current = current + 1;
	  if (str[current] != '\0')
	    s->width = -1;
	  s->shape[index] = str;
	  index += 1;
	}
      s->shape[index] = NULL;
      if (index < s->height)
	s->width = -1;
    }
  return (0);
}

/*
** I don't know how to verif at 100 % with special case like in pdf
*/

static int	verif_width(t_shape *shape)
{
  int		y_pos;
  int		x_pos;
  int		max;

  max = 0;
  y_pos = 0;
  while (y_pos < shape->height && shape->shape &&
	 shape->shape[y_pos] != NULL)
    {
      x_pos = 0;
      while (shape->shape[y_pos][x_pos] != '\0')
	{
	  if (shape->shape[y_pos][x_pos] == '*' && x_pos >= max)
	    max = x_pos + 1;
	  x_pos += 1;
	}
      y_pos = y_pos + 1;
    }
  if (max != shape->width)
    shape->height = -1;
  return (0);
}

static int	fill_shapes(t_shape *shape, char *name,
			    char *path)
{
  int		fd;

  shape->width = 0;
  shape->height = 0;
  shape->color = 0;
  shape->shape = NULL;
  if ((shape->name = fill_name(name)) == NULL)
    return (FATAL);
  if ((fd = open(path, O_RDONLY)) > 0)
    {
      if (header_read(shape, fd) != FATAL &&
	  fill_shapes_data(shape, fd) != FATAL)
	{
	  get_next_line(GNL_FREE);
	  verif_width(shape);
	  close(fd);
	  return (0);
	}
      get_next_line(GNL_FREE);
      close(fd);
      return (FATAL);
    }
  return (ERRO);
}
/*
** Add the shape to the shape list
*/

static int	add_shape(t_shape_list *list, char *filename,
			  char *path)
{
  t_shape	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (FATAL);
  if (fill_shapes(elem, filename, path) == FATAL)
    return (FATAL);
  elem->next = NULL;
  insert(list, elem);
  list->len += 1;
  free(path);
  return (0);
}

int	get_shapes(t_shape_list *list)
{
  char		*onepath;
  DIR		*rep;
  struct dirent	*file;

  list->len = 0;
  list->first = NULL;
  if ((rep = opendir(PATH)) == NULL)
    return (ERRO);
  while ((file = readdir(rep)) != NULL)
    {
      if (my_endcmp(FILTER, file->d_name) == 1)
	{
	  if ((onepath = my_strcat(PATH, file->d_name)) == NULL ||
	      add_shape(list, file->d_name, onepath) == FATAL)
	    return (FATAL);
	}
    }
  closedir(rep);
  return (0);
}
