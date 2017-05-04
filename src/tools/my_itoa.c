/*
** my_putnbr_base.c for my_putnbr_base in /home/Kiwiv2/PSU_2016_my_printf
** 
** Made by alexandre caila
** Login   <Kiwiv2@epitech.net>
** 
** Started on  Mon Nov 14 15:21:38 2016 alexandre caila
** Last update Tue Mar  7 23:04:13 2017 alexandre
*/

#include <stdlib.h>
#include <unistd.h>

char	*my_itoa(int nb, char *str, int base)
{
  int	count;
  int	get;
  char	*numb;

  get = 1;
  count = 0;
  if ((numb = malloc(sizeof(char) * (100))) == NULL)
    return ("\0");
  if (nb == 0 || str == NULL || base <= 1 || base > 16)
    return ("0");
  while (get <= nb)
    get = get * base;
  while (get > 1)
    {
      get = get / base;
      numb[count] = str[nb / get];
      nb = nb % get;
      count = count + 1;
    }
  numb[count] = '\0';
  return (numb);
}
