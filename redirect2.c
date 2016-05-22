/*
** redirect2.c for  in /home/sepret_f/sem2/psu/PSU_2015_minishell2
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Apr  7 19:16:24 2016 fabrice sepret
** Last update Tue Apr 12 12:03:01 2016 fabrice sepret
*/

#include "minishell1.h"

int	ls_redirect(char **tab, char *s, char **env)
{
  char	**str;
  int	fd;

  str = com_to_tab(s, '<');
  if ((fd = open(checkend_s(str[1]), O_RDONLY)) == -1)
    {
      my_putstr_error("Error: ");
      my_putstr_error(check_s(str[1]));
      my_putstr_error(": no such file\n");
    }
  if (my_strncmp(check_s(str[0]), "cat", 3) == 0)
    {
      str[0] = my_strcat(str[0], " ");
      str[0] = my_strcat(str[0], str[1]);
    }
  if ((dup2(0, fd)) == -1)
    exit(0);
  my_exec(tab, str[0], env);
  if ((dup2(fd, 0)) == -1)
    exit(0);
  close(fd);
}

char	*add(char **str, int i)
{
  while (str[i] != 0)
    {
      str[2] = my_strcat(str[2], " ");
      str[2] = my_strcat(str[2], str[i]);
      i += 1;
    }
  return (str[2]);
}

int	bls_redirect(char **tab, char *s, char **env)
{
  char	**str;
  int	fd;

  str = com_to_tab(s, ' ');
  if ((fd = open(checkend_s(str[1]), O_RDONLY)) == -1)
    {
      my_putstr_error("Error: ");
      my_putstr_error(check_s(str[1]));
      my_putstr_error(": no such file\n");
    }
  if (my_strncmp(check_s(str[2]), "cat", 3) == 0 && str[2][0] != 0)
    {
      str[2] = my_strcat(str[2], " ");
      str[2] = my_strcat(str[2], str[1]);
    }
  str[2] = add(str, 3);
  if ((dup2(0, fd)) == -1)
    exit(0);
  my_exec(tab, str[2], env);
  if ((dup2(fd, 0)) == -1)
    exit(0);
  close(fd);
}
