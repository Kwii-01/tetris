/*
** my_getnbr.c for tetris in /home/robin.milas/Current/PSU_2016_tetris
** 
** Made by Robin MILAS
** Login   <robin.milas@epitech.net>
** 
** Started on  Thu Mar  2 22:05:39 2017 Robin MILAS
** Last update Tue Mar 14 15:05:04 2017 alexandre
*/

int	parse_nb(int *i, char **str)
{
  if (**str < '0' || **str > '9')
    return (1);
  *i = 0;
  while (**str >= '0' && **str <= '9')
    {
      if (*i > 300000000)
	return (1);
      *i = *i * 10 + **str - '0';
      if (*i < 0)
	return (1);
      *str += 1;
    }
  return (0);
}
