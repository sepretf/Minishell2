/*
** my_atoi.c for  in /home/sepret_f/progelem/CPE_2015_BSQ
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Sun Dec 20 19:28:56 2015 fabrice sepret
** Last update Mon Apr  4 11:21:42 2016 fabrice sepret
*/

int	my_atoi(char *str)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (str[a] != 0)
    {
      if (str[a] >= '0' && str[a] <= '9')
	{
	  b = b * 10;
	  b = b + str[a] - '0';
	}
      a = a + 1;
    }
  return (b);
}

int	my_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != 0)
    {
      my_putstr(env[i++]);
      my_putchar('\n');
    }
}
