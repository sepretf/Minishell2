/*
** put.c for  in /home/sepret_f/PSU_2015_my_printf
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Wed Nov  4 10:05:26 2015 fabrice sepret
** Last update Wed Apr  6 15:24:13 2016 fabrice sepret
*/

#include <stdlib.h>
#include "minishell1.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i = i + 1;
  return (i);
}

int	size(char **av)
{
  int	i;
  int	len;

  i = 0;
  len = 0;
  while (av[i] != 0)
    {
      if (len < my_strlen(av[i]))
	len = my_strlen(av[i]);
      i = i + 1;
    }
  return (len);
}

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *st)
{
  int	i;

  i = 0;
  if (st ==  '\0')
    {
      write(1, &"(null)", 6);
      return (1);
    }
  while (st[i] != 0)
    {
      my_putchar(st[i]);
      i = i + 1;
    }
  return (0);
}

char	**str_to_tab(char *s)
{
  s_var	var;

  var.i = 0;
  var.y = 0;
  var.idx = 0;
  if ((var.argv = malloc(sizeof(char **) * my_strlen(s))) == NULL)
    exit(-1);
  while (var.idx != my_strlen(s))
    {
      if ((var.argv[var.idx++] =
	   malloc(sizeof(char **) * my_strlen(s))) == NULL)
	exit(-1);
    }
  while (s[var.i] != 0)
    {
      var.x = 0;
      while ((s[var.i] == '\t' || s[var.i] == ' ') && s[var.i++] != 0);
      while (s[var.i] != '\t' && s[var.i] != ' ' && s[var.i] != 0)
	var.argv[var.y][var.x++] = s[var.i++];
      while ((s[var.i] == ' ' || s[var.i] == '\t') && s[var.i] != 0)
	var.i += 1;
      var.y += 1;
    }
  var.argv[var.y] = 0;
  return (var.argv);
}
