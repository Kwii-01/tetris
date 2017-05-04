/*
** insert.c for tetris in /home/robin.milas/Current/PSU_2016_tetris/src
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Wed Mar  1 14:44:52 2017 Robin MILAS
** Last update Thu Mar  2 21:16:19 2017 Robin MILAS
*/

#include <stdlib.h>
#include "tetris.h"

static int	my_sort_name(t_shape *elm1, t_shape *elm2)
{
  int		index;

  if (elm1->name == NULL || elm2->name == NULL)
    return (0);
  index = 0;
  while (elm1->name[index] == elm2->name[index])
    {
      if (elm1->name[index] == '\0')
	{
	  return (0);
	}
      index = index + 1;
    }
  return (elm1->name[index] - elm2->name[index]);
}

void		insert(t_shape_list *list, t_shape *elem)
{
  t_shape	*current;

  if (list->first == NULL || my_sort_name(elem, list->first) < 0)
    {
      elem->next = list->first;
      list->first = elem;
    }
  else
    {
      current = list->first;
      while (current->next != NULL &&
	     my_sort_name(elem, current->next) > 0)
	current = current->next;
      elem->next = current->next;
      current->next = elem;
    }
}
