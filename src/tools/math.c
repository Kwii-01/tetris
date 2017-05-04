/*
** math.c for tetris in /home/milasr/Current/PSU_2016_tetris
** 
** Made by Milas Robin
** Login   <milasr@epitech.net>
** 
** Started on  Sun Mar 19 15:32:35 2017 Milas Robin
** Last update Sun Mar 19 15:34:27 2017 Milas Robin
*/

float	my_pow(float nb, int rank)
{
  float	res;

  res = 1;
  while (rank > 0)
    {
      res *= nb;
      rank -= 1;
    }
  while (rank < 0)
    {
      res /= nb;
      rank += 1;
    }
  return (res);
}
