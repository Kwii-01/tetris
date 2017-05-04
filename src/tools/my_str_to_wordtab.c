/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/kiwiv2/epitech/PSU/minishell1/tools
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Thu Jan 19 00:13:03 2017 alexandre
** Last update Thu Feb 23 15:55:32 2017 alexandre
*/

#include <stdlib.h>
#include <unistd.h>

int	my_words(char *str)
{
  int	nb;
  int	count;

  nb = 0;
  count = 0;
  if (str[nb] == '\0')
    return (1);
  while (str[nb] != '\0')
    {
      if (str[nb] == ' ')
	count = count + 1;
      nb = nb + 1;
    }
  return (count);
}

int	my_len(char *str, int nb)
{
  int	count;

  count = 0;
  while (str[nb] != '\0' && str[nb] != ' ')
    {
      nb = nb + 1;
      count = count + 1;
    }
  return (count);
}

int	my_loop(char *str, char **line, int count, int nb)
{
  int	cha;

  cha = 0;
  while (str[nb] != '\0' && str[nb] != ' ')
    {
      line[count][cha] = str[nb];
      cha = cha + 1;
      nb = nb + 1;
    }
  line[count][cha] = '\0';
  return (nb);
}

char	**my_str_to_wordtab(char *str)
{
  char	**line;
  int	count;
  int	nb;

  nb = 0;
  count = 0;
  if ((line = malloc(sizeof(char *) * (my_words(str) + 2))) == NULL)
    return (NULL);
  while (str[nb] != '\0')
    {
      if ((line[count] = malloc(sizeof(char) * (my_len(str, nb) + 1))) == NULL)
	return (NULL);
      nb = my_loop(str, line, count, nb);
      count = count + 1;
      if (str[nb] != '\0')
	nb = nb + 1;
    }
  line[count] = NULL;
  return (line);
}
