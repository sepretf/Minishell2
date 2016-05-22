/*
** my_strcomp.c for  in /home/sepret_f/PSU_2015_minishell1
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Thu Jan 21 14:48:07 2016 fabrice sepret
** Last update Thu Jan 21 14:50:30 2016 fabrice sepret
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i])
    i += 1;
  return (s1[i] - s2[i]);
}
