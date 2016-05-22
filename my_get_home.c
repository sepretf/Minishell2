/*
** my_get_home.c for  in /home/sepret_f/PSU_2015_minishell1
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Sun Jan 24 16:57:07 2016 fabrice sepret
** Last update Wed Apr  6 14:24:41 2016 fabrice sepret
*/

#include <stdlib.h>
#include "minishell1.h"

char	*my_home(char **environ)
{
  s_var	var;
  char	*dest;

  var.o = 0;
  var.i = 0;
  var.j = 5;
  while (environ[var.i] != 0)
    {
      if (environ[var.i][0] == 'H' && environ[var.i][1] == 'O'
	  && environ[var.i][2] == 'M' && environ[var.i][3] =='E'
	  && environ[var.i][4] == '=')
	{
	  if ((dest = malloc(sizeof(char *)
			     *(my_strlen(environ[var.i])))) == NULL)
	    exit(-1);
	  while (environ[var.i][var.j] != 0)
	    {
	      dest[var.o] = environ[var.i][var.j];
	      var.o += 1;
	      var.j += 1;
	    }
	}
      var.i += 1;
    }
  return (dest);
}

char	*my_oldpwd(char **environ)
{
  s_var	var;
  char	*dest;

  var.o = 0;
  var.i = 0;
  var.j = 7;
  while (environ[var.i] != 0)
    {
      if (environ[var.i][0] == 'O' && environ[var.i][1] == 'L'
	  && environ[var.i][2] == 'D' && environ[var.i][3] =='P'
	  && environ[var.i][4] == 'W' && environ[var.i][5] =='D')
	{
	  if ((dest = malloc(sizeof(char *)
			     *(my_strlen(environ[var.i])))) == NULL)
	    exit(-1);
	  while (environ[var.i][var.j] != 0)
	    {
	      dest[var.o] = environ[var.i][var.j];
	      var.o += 1;
	      var.j += 1;
	    }
	}
      var.i += 1;
    }
  return (dest);
}

int	detect_cmd(char *s)
{
  if (my_strcmp(str_to_tab(s)[0] , "exit") == 0 ||
      my_strcmp(str_to_tab(s)[0] , "cd") == 0 ||
      my_strcmp(str_to_tab(s)[0], "unsetenv") == 0 ||
      my_strcmp(str_to_tab(s)[0], "setenv") == 0 ||
      my_strcmp(str_to_tab(s)[0], "env") == 0)
    return (1);
  return (0);
}

char	**exec_cmd(char **env, char *s)
{
  char **args;

  if (my_strcmp(str_to_tab(s)[0] , "exit") == 0)
    my_exit(str_to_tab(s)[1]);
  else if (my_strcmp(str_to_tab(s)[0] , "cd") == 0
	   && str_to_tab(s)[1] != 0)
    env = my_chdir(str_to_tab(s)[1], s, env);
  else if (my_strcmp(str_to_tab(s)[0] , "cd") == 0
	   && str_to_tab(s)[1] == 0)
    env = xchdir(my_home(env), env);
  else if (my_strcmp(str_to_tab(s)[0], "env") == 0)
    my_env(env);
  else if (my_strcmp(str_to_tab(s)[0], "setenv") == 0)
    env = my_setenv(env, str_to_tab(s));
  else if ((my_strcmp(str_to_tab(s)[0], "unsetenv") == 0 )
	   && str_to_tab(s)[1] == NULL)
    my_putstr_error("unsetenv: Too few arguments.\n");
  else if ((my_strcmp(str_to_tab(s)[0], "unsetenv") == 0 )
	   && str_to_tab(s)[1] != NULL)
    env = my_unsetenv(env, str_to_tab(s));
  return (env);
}

void	my_prog(int ac, char **av, char **environ)
{
  char	*s;
  char	**str;
  int	i;
  pid_t	child_pid;

  while ((s = get_next_line(0)))
    {
      i = 0;
      str = com_to_tab(s, ';');
      while (str[i] != NULL)
	{
	  if (str_to_tab(str[i])[0] == 0);
	  else if (detect_cmd(str[i]) == 1)
	    environ = exec_cmd(environ, str[i]);
	  else
	    check(get_path(ac, av, environ, str[i]), str[i], environ);
	  wait(&child_pid);
	  my_segfault(child_pid);
	  i += 1;
	}
      my_putstr("$> ");
    }
}
