/*
** env.c for  in /home/sepret_f/progelem/PSU_2015_minishell1
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Mon Jan 18 13:27:49 2016 fabrice sepret
** Last update Wed Apr  6 15:25:41 2016 fabrice sepret
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell1.h"

char	**my_str_to_tab(char *str, char *s)
{
  s_var	var;
  char	**tab;

  var.i = 0;
  var.y = 0;
  var.idx = 0;
  if ((tab = malloc(sizeof(char **) * my_strlen(str))) == NULL)
    exit(-1);
  while (var.idx != my_strlen(str))
    {
      if ((tab[var.idx++] = malloc(sizeof(char **) * my_strlen(str))) == NULL)
	exit(-1);
    }
  while (str[var.i] != 0)
    {
      var.x = 0;
      while (str[var.i] != ':' && str[var.i] != 0)
	tab[var.y][var.x++] = str[var.i++];
      tab[var.y][var.x++] = '/';
      var.i += 1;
      var.y += 1;
    }
  return (tab);
}

char	**get_path(int ac, char **av, char **environ, char *s)
{
  s_var	var;
  char	*path;

  var.o = 0;
  var.i = 0;
  var.j = 5;
  while (environ[var.i] != 0)
    {
      if (environ[var.i][0] == 'P' && environ[var.i][1] == 'A'
	  && environ[var.i][2] == 'T' && environ[var.i][3] =='H'
	  && environ[var.i][4] == '=')
	{
	  if ((path = malloc(sizeof(char *)
			     *(my_strlen(environ[var.i])))) == NULL)
	    exit(-1);
	  while (environ[var.i][var.j] != 0)
	    {
	      path[var.o] = environ[var.i][var.j];
	      var.o += 1;
	      var.j += 1;
	    }
	}
      var.i += 1;
    }
  return (my_str_to_tab(path, s));
}

char	*check_s(char *s)
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
  while (s[i] != 0)
    {
      ret[k] = s[i];
      k += 1;
      i += 1;
    }
  return (ret);
}

char	*filename(char *tab, char *s)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (tab[i] != 0)
    i+= 1;
  while ((s[j] == ' ' || s[j] == '\t')&& s[j] != 0)
    j += 1;
  while (s[j] != ' ' && s[j] != '\t' && s[j] != 0)
    {
      tab[i] = s[j];
      i += 1;
      j += 1;
    }
  tab[i + 1] = 0;
  return (tab);
}

int	my_exec(char **tab, char *s, char **environ)
{
  int	i;
  pid_t	pid;

  i = 0;
  if ((pid = fork()) == -1)
    exit(-1);
  while (tab[i][0] != 0)
    {
      if (pid == 0 && (check_s(s)[0] == '/' || check_s(s)[0] == '.'))
	execve(check_s(str_to_tab(s)[0]), str_to_tab(s), environ);
      else if (pid == 0)
	execve(filename(tab[i], s), str_to_tab(s), environ);
      else
	return (1);
      i += 1;
    }
  my_putstr_error(check_s(s));
  my_putstr_error(" : Command not found.\n");
  exit(1);
}
