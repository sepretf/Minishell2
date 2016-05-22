/*
** try_pipe.c for  in /home/sepret_f/sem2/psu/PSU_2015_minishell2
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Sun Apr 10 11:25:22 2016 fabrice sepret
** Last update Tue Apr 12 09:40:19 2016 fabrice sepret
*/

#include "minishell1.h"

int	exec_pipe(char **tab, char **s, char **env, int k)
{
  int	i;

  i = 0;
  while (tab[i][0] != 0)
    {
      execve(filename(tab[i], check_s(s[k])),
      str_to_tab(s[k]), env);
      i += 1;
    }
  my_putstr_error(check_s(s[k]));
  my_putstr_error(" : Command not found.\n");
  return (-1);
}

int	init_pipe(char **tab, char *s, char **env)
{
  pid_t	pid;
  int	tab_pid[2];

  if ((pid = fork()) > 0)
    waitpid(pid, 0, 0);
  if (pid == 0)
    {
      if (pipe(tab_pid) == -1 || ((pid = fork()) == -1))
	error();
      if (pid == 0)
	{
	  close(tab_pid[0]);
	  if ((dup2(tab_pid[1], 1)) == -1 ||
	      (exec_pipe(tab, com_to_tab(s, '|'), env, 0)) != -1)
	    exit(1);
	}
      else
	{
	  close(tab_pid[1]);
	  if ((dup2(tab_pid[0], 0)) == -1 ||
	      (exec_pipe(tab, com_to_tab(s, '|'), env, 1)) != -1)
	    exit(1);
	}
    }
}
