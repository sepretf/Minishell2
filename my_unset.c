/*
** my_unset.c for  in /home/sepret_f/sem2/psu/PSU_2015_minishell2
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Mon Apr  4 12:14:01 2016 fabrice sepret
** Last update Mon Apr 11 10:25:08 2016 fabrice sepret
*/

#include "minishell1.h"

char	**my_unsetenv(char **env, char **av)
{
  int	i;
  int	j;
  int	k;
  char	*new;

  i = 0;
  while (av[++i])
    {
      j = -1;
      while (env[++j])
	{
	  new = my_strcat(av[i], "=");
	  if (my_strncmp(env[j], new, my_strlen(new)) == 0)
	    {
	      k = j;
	      while (env[k + 1] != 0)
		{
		  env[k] = env[k + 1];
		  k++;
		}
	      env[k] = 0;
	    }
	}
    }
  return (env);
}
