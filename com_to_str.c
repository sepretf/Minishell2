/*
** com_to_str.c for  in /home/sepret_f/sem2/psu/PSU_2015_minishell2
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Tue Apr  5 17:05:10 2016 fabrice sepret
** Last update Wed Apr  6 14:38:18 2016 fabrice sepret
*/

#include <stdlib.h>
#include "minishell1.h"

char	**com_to_tab(char *str, char c)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  if ((tab = malloc(sizeof(char **) * my_strlen(str))) == NULL)
    exit(0);
  i = 0;
  j = 0;
  if (str[0] == c)
    i = 1;
  while (str[i] != 0)
    {
      k = 0;
      if ((tab[j] = malloc(sizeof(char *) * my_strlen(str))) == NULL)
	exit(0);
      while ((str[i] == c) && str[i++] != 0);
      while (str[i] != c && str[i] != 0)
	tab[j][k++] = str[i++];
      tab[j++][k] = 0;
      while ((str[i] == c) && str[i++] != 0);
    }
  tab[j] = NULL;
  return (tab);
}
