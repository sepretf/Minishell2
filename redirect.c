/*
** redirect.c for  in /home/sepret_f/sem2/psu/PSU_2015_minishell2
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Wed Apr  6 11:50:28 2016 fabrice sepret
** Last update Sun May 22 16:27:47 2016 fabrice sepret
*/

#include "minishell1.h"

int	brs_redirect(char **tab, char *s, char **env)
{
  char	**str;
  int	fd;
  int	i;

  i = 3;
  str = com_to_tab(s, ' ');
  if (str[2] != 0)
    {
      if ((fd = open(checkend_s(str[1]), O_CREAT | O_WRONLY, 0644)) == -1)
	exit(0);
      if ((dup2(fd, 1)) == -1)
	exit(0);
      while (str[i] != 0)
	{
	  str[2] = my_strcat(str[2], " ");
	  str[2] = my_strcat(str[2], str[i]);
	  i += 1;
	}
      my_exec(tab, str[2], env);
      if ((dup2(0, 1)) == -1)
	exit(0);
      close(fd);
    }
}

int	rs_redirect(char **tab, char *s, char **env)
{
  char	**str;
  int	fd;

  str = com_to_tab(s, '>');
  if ((fd = open(checkend_s(str[1]), O_CREAT | O_WRONLY, 0644)) == -1)
    exit(0);
  if ((dup2(fd, 1)) == -1)
    exit(0);
  my_exec(tab, str[0], env);
  if ((dup2(0, 1)) == -1)
    exit(0);
  close(fd);
}

int	brd_redirect(char **tab, char *s, char **env)
{
  char	**str;
  int	fd;
  int	i;

  i = 3;
  str = com_to_tab(s, ' ');
  if ((fd = open(checkend_s(str[1]), O_CREAT
  | O_WRONLY | O_APPEND, 0644)) == -1)
    exit(0);
  if ((dup2(fd, 1)) == -1)
    exit(0);
  while (str[i] != 0)
    {
      str[2] = my_strcat(str[2], " ");
      str[2] = my_strcat(str[2], str[i]);
      i += 1;
    }
  my_exec(tab, str[2], env);
  if ((dup2(0, 1)) == -1)
    exit(0);
  close(fd);
}

int	rd_redirect(char **tab, char *s, char **env)
{
  char	**str;
  int	fd;

  str = com_to_tab(s, '>');
  if ((fd = open(checkend_s(str[1]), O_CREAT
  | O_WRONLY | O_APPEND, 0644)) == -1)
    exit(0);
  if ((dup2(fd, 1)) == -1)
    exit(0);
  my_exec(tab, str[0], env);
  if ((dup2(0, 1)) == -1)
    exit(0);
  close(fd);
}
