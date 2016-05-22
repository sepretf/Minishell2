/*
** main.c for  in /home/sepret_f/progelem/PSU_2015_minishell1
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Fri Jan 15 11:12:35 2016 fabrice sepret
** Last update Thu Apr  7 14:06:01 2016 fabrice sepret
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "minishell1.h"

char	**xchdir(char *dest, char **env)
{
  if (chdir(dest) == -1)
    my_putstr_error("Chdir fail.\n");
  return (env);
}

char	**my_chdir(char *path, char *s, char **environ)
{
  char	old[10000];

  getcwd(old, 40000);
  if (access(str_to_tab(s)[1], X_OK) == -1 && str_to_tab(s)[1][0] != '-')
    {
      my_putstr_error(str_to_tab(s)[1]);
      my_putstr_error(" : Permission denied.\n");
    }
  else if (str_to_tab(s)[1][0] == '-' && str_to_tab(s)[1][1] == 0)
    xchdir(my_oldpwd(environ), environ);
  else if (chdir(str_to_tab(s)[1]) == -1)
    {
      my_putstr_error(str_to_tab(s)[1]);
      my_putstr_error(" : Not a directory.\n");
    }
  environ = my_setenv(environ, str_to_tab(my_strcat("setenv ",
  my_strcat("OLDPWD ", old))));
  return (environ);
}

void	my_signal(int sign)
{
  if (sign == SIGINT)
    {
      my_putchar('\n');
      my_putstr("$> ");
    }
}

void	my_segfault(pid_t pid)
{
  if (WIFSIGNALED(pid))
    {
      if (WTERMSIG(pid) == SIGSEGV)
	my_putstr_error("Segmentation fault\n");
    }
}

int	main(int ac, char **av, char **environ)
{
  char	*s;
  int	i;
  pid_t	child_pid;

  check_env(environ);
  signal(SIGINT, my_signal);
  my_prog(ac, av, environ);
  my_putstr_error("exit\n");
  exit(0);
}
