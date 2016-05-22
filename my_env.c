/*
** my_env.c for  in /home/sepret_f/sem2/psu/PSU_2015_minishell2
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Mon Apr  4 11:42:06 2016 fabrice sepret
** Last update Wed Apr  6 14:22:29 2016 fabrice sepret
*/

#include "minishell1.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n && (s1[i] != 0 || s2[i] != 0))
    {
      if (s1[i] != s2[i])
	return (1);
      i += 1;
    }
  if (i == n)
    return (0);
  return (1);
}

char	**my_setenv(char **env, char **tab)
{
  int	i;

  i = 0;
  if (tab[1] == 0)
    {
      my_env(env);
      return (env);
    }
  while (env[i] != 0)
    {
      if (my_strncmp(env[i++], tab[1], my_strlen(tab[1])) == 0)
	return (chang_env(env, tab, i - 1));
    }
  return (move_env(env, tab));
}
