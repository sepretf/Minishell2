/*
** error.c for  in /home/sepret_f/PSU_2015_minishell1
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Jan 21 11:30:47 2016 fabrice sepret
** Last update Mon Apr  4 15:15:19 2016 fabrice sepret
*/

#include <stdlib.h>

int	my_putchar_error(char c)
{
  write(2, &c, 1);
}

int	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\\' && str[i + 1] == 'n')
	{
	  my_putchar('\n');
	  i += 2;
	}
      my_putchar_error(str[i]);
      i += 1;
    }
}

int	my_exit(char *s)
{
  my_putstr_error("exit\n");
  if (s != NULL)
    exit(my_atoi(s));
  else
    exit(0);
}

int	check_env(char **environ)
{
  if (environ[0] == 0)
    {
      my_putstr_error("ENV is empty\n");
      exit (-1);
    }
  my_putstr("$> ");
}
