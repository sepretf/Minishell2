/*
** check.c for  in /home/sepret_f/sem2/psu/PSU_2015_minishell2
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Wed Apr  6 11:17:21 2016 fabrice sepret
** Last update Mon Apr 11 09:52:26 2016 fabrice sepret
*/

#include "minishell1.h"

static int	check_end(char *s, int i)
{
  while (s[i] != 0)
    {
      if (s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '\t')
	return (1);
      i += 1;
    }
  return (0);
}

static void	check2(char **tab, char *s, char **environ, int idx)
{
  if (idx == -1 && check_s(s)[0] != '<')
    ls_redirect(tab, check_s(s), environ);
  else if (idx == 1 && check_s(s)[0] == '>')
    brs_redirect(tab, check_s(s), environ);
  else if (idx == 2 && check_s(s)[0] != '>')
    rd_redirect(tab, check_s(s), environ);
  else if (idx == 2 && check_s(s)[0] == '>' && (com_to_tab(s, ' ')[2] != 0))
    brd_redirect(tab, check_s(s), environ);
  else if (idx == -1 && check_s(s)[0] == '<' && (com_to_tab(s, ' ')[2] != 0))
    bls_redirect(tab, check_s(s), environ);
}

static int	check_end_p(char *s, int i)
{
  while (s[i] != 0)
    {
      if (s[i] != ' ' && s[i] != '|' && s[i] != '\t')
	return (1);
      i += 1;
    }
  return (0);
}

static int	check_pipe(char *s)
{
  int		i;

  i = 0;
  while (s[i] != 0)
    {
      if (s[i] == '|' && (check_end_p(s, i) == 1))
	return (1);
      i += 1;
    }
  return (0);
}

void	check(char **tab, char *s, char **environ)
{
  int	i;
  int	idx;
  int	pipe;

  idx = 0;
  i = 0;
  pipe = check_pipe(s);
  while (s[i] != 0)
    {
      if ((idx == 1 && s[i] == '>' && s[i - 1] == '>'
	   || idx == 0 && s[i] == '>') && (check_end(s, i) == 1))
	idx += 1;
      else if ((idx == 1 && s[i] == '<' && s[i - 1] == '<'
		|| idx == 0 && s[i] == '<') && (check_end(s, i) == 1))
	idx -= 1;
      i += 1;
    }
  if (pipe == 1 && idx == 0)
    init_pipe(tab, check_s(s), environ);
  if (idx == 0 && pipe == 0)
    my_exec(tab, s, environ);
  else if (idx == 1 && check_s(s)[0] != '>')
    rs_redirect(tab, check_s(s), environ);
  else
    check2(tab, s, environ, idx);
}
