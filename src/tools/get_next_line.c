/*
** get_next_line.c for get_next_line in /home/robin.milas/Current
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Mon Jan  2 17:40:30 2017 Robin MILAS
** Last update Thu Mar  2 14:26:21 2017 Robin MILAS
*/

#include <unistd.h>
#include <stdlib.h>
#include "gnl.h"

int	get_breakline(t_buffer *buf)
{
  long	index;

  index = 0;
  if (buf->buffer != NULL)
    {
      while (index < buf->length)
	{
	  if (buf->buffer[index] == '\n')
	    {
	      return (index);
	    }
	  index = index + 1;
	}
    }
  return (-1);
}

void	replace_old_buffer(t_buffer *buf, long pos)
{
  char	*n_buffer;
  long	n_length;
  long	index;

  n_buffer = NULL;
  n_length = 0;
  if (pos < buf->length - 1)
    {
      n_buffer = malloc(sizeof(*n_buffer) * (buf->length - pos));
      if (n_buffer == NULL)
	return ;
      n_length = (buf->length - pos - 1);
      pos += 1;
      index = 0;
      while (pos + index < buf->length)
	{
	  n_buffer[index] = buf->buffer[pos + index];
	  index += 1;
	}
    }
  if (buf->buffer != NULL)
    free(buf->buffer);
  buf->buffer = n_buffer;
  buf->length = n_length;
}

char	buffer_cat(t_buffer *buf, char *r_buf, int r_size)
{
  char	*n_buf;
  long	index;

  if ((n_buf = malloc(sizeof(*buf) * (buf->length + r_size))) == NULL)
    return (-1);
  if (buf->buffer != NULL)
    {
      index = 0;
      while (index < buf->length)
	{
	  n_buf[index] = buf->buffer[index];
	  index = index + 1;
	}
    }
  index = 0;
  while (index < r_size)
    {
      n_buf[buf->length + index] = r_buf[index];
      index = index + 1;
    }
  if (buf->buffer != NULL)
    free(buf->buffer);
  buf->buffer = n_buf;
  buf->length += r_size;
  return (0);
}

char	*get_line(t_buffer *buf, long pos)
{
  char	*res;
  long	index;

  if (buf->buffer == NULL)
    return (NULL);
  res = malloc(sizeof(*res) * (1 + pos));
  if (res == NULL)
    return (NULL);
  index = 0;
  while (index < pos)
    {
      res[index] = buf->buffer[index];
      index = index + 1;
    }
  res[index] = '\0';
  replace_old_buffer(buf, pos);
  return (res);
}

char			*get_next_line(const int fd)
{
  static t_buffer	buf = {NULL, 0};
  long			pos;
  long			r_size;
  char			temp[READ_SIZE];

  if (fd == GNL_FREE)
    {
      free(buf.buffer);
      buf.length = 0;
      return (buf.buffer = NULL);
    }
  if (buf.buffer != NULL)
    if ((pos = get_breakline(&buf)) > -1)
      return (get_line(&buf, pos));
  while ((pos = get_breakline(&buf)) < 0)
  {
    r_size = read(fd, temp, READ_SIZE);
    if (r_size < 0)
      return (NULL);
    if (r_size == 0)
      return (get_line(&buf, buf.length));
    if (buffer_cat(&buf, temp, r_size) < 0)
      return (NULL);
  }
  return (get_line(&buf, pos));
}
