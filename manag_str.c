/*
** manag_str.c for  in /home/sepret_f/sem2/psu/PSU_2015_minishell2
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Tue Apr 12 11:58:20 2016 fabrice sepret
** Last update Tue Apr 12 12:01:50 2016 fabrice sepret
*/

#include "minishell1.h"

char	*checkend_s(char *s)
{
  int	i;
  int	k;
  char	*ret;

  if ((ret = malloc(sizeof(char *) * my_strlen(s) + 1 )) == NULL)
    exit(0);
  i = 0;
  k = 0;
  while (s[i] != 0 && (s[i] == ' ' || s[i] == '\t'))
    i += 1;
  while (s[i] != 0 && s[i] != ' ' && s[i] != '\t')
    {
      ret[k] = s[i];
      k += 1;
      i += 1;
    }
  ret[k + 1] = 0;
  return (ret);
}
