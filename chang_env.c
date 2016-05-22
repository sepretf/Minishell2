/*
** chang_env.c for  in /home/sepret_f/sem2/psu/PSU_2015_minishell2
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Mon Apr  4 11:54:30 2016 fabrice sepret
** Last update Wed Apr  6 10:23:47 2016 fabrice sepret
*/

#include <stdlib.h>
#include "minishell1.h"

char	*check_name(char *ret, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (ret[i] != 0)
    i += 1;
  while (str[j] != 0)
    {
      ret[i] = str[j];
      i += 1;
      j += 1;
    }
  ret[i] = 0;
  return (ret);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    i += 1;
  return (i);
}

char	**move_env(char **env, char **tab)
{
  char	**ret;
  int	i;

  i = 0;
  if ((ret = malloc(sizeof(char **) * (my_tablen(env) * 2))) == NULL)
    exit(1);
  while (env[i] != 0)
    {
      if ((ret[i] = malloc(sizeof(char *) * (my_strlen(env[i]) * 2)))
	  == NULL)
	exit(1);
      ret[i] = env[i];
      i += 1;
    }
  ret[i] = check_name(tab[1], "=");
  if (tab[2] != NULL)
    ret[i] = check_name(ret[i], tab[2]);
  return (ret);
}

char	**chang_env(char **env, char **tab, int i)
{
  int	j;
  int	l;
  int	len;
  char	*str;

  j = 0;
  l = 0;
  str = env[i];
  len = my_strlen(str);
  if ((env[i] = malloc(sizeof(char *) * (len + my_strlen(tab[1])) * 2))
      == NULL)
    exit(1);
  while (str[j - 1] != '=')
    {
      env[i][j] = str[j];
      j += 1;
    }
  while (tab[2] != NULL && tab[2][l] != 0)
    {
      env[i][j] = tab[2][l++];
      j += 1;
    }
  return (env);
}
