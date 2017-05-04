/*
** get_next_line.h for get_next_line in /home/robin.milas/Current/CPE_2017_getnextline
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Mon Jan  2 17:42:15 2017 Robin MILAS
** Last update Wed Mar  1 20:21:05 2017 Robin MILAS
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define GNL_FREE	-1

# ifndef READ_SIZE
#  define READ_SIZE	4096
# endif

typedef struct	s_buffer {
  char		*buffer;
  long		length;
}		t_buffer;

char	*get_next_line(const int fd);

#endif
