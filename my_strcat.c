/*
** my_strcat.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Feb 25 09:51:44 2016 fabrice sepret
** Last update Mon Apr  4 15:36:02 2016 fabrice sepret
*/

#include <stdlib.h>
#include "minishell1.h"

unsigned char	*my_strcat(unsigned char *param, unsigned char *av)
{
  int		i;
  int		j;
  unsigned char	*new;

  if ((new = malloc(sizeof(char *) *
		    (my_strlen(param) + my_strlen(av)))) == NULL)
    exit(-1);
  i = 0;
  j = 0;
  while (param[i] != 0)
    {
      new[i] = param[i];
      i += 1;
    }
  while (av[j] != 0)
    {
      new[i] = av[j];
      j += 1;
      i += 1;
    }
  new[i] = '\0';
  return (new);
}
