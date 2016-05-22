/*
** minishell1.h for  in /home/sepret_f/PSU_2015_minishell1
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Jan 21 15:16:46 2016 fabrice sepret
** Last update Tue Apr 12 12:04:00 2016 fabrice sepret
*/

#ifndef		MINISHELL1_H_
# define	MINISHELL1_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	t_var
{
  int		idx;
  int		i;
  int		x;
  int		y;
  int		e;
  int		j;
  int		o;
  char		**argv;
}		s_var;

char		*get_next_line(const int fd);
char		**str_to_tab(char *s);
void		my_signal(int sign);
char		*my_home(char **environ);
char		*my_oldpwd(char **environ);
char		**my_args(char *s);
int		detect_cmd(char *s);
char		**exec_cmd(char **env, char *s);
void		my_prog(int ac, char **av, char **environ);
char		**my_setenv(char **env, char **tab);
char		**my_unsetenv(char **env, char **args);
char		**sup(char **env, char *name, int i);
char		*check_name(char *ret, char *str);
char		**move_env(char **env, char **tab);
char		**chang_env(char **env, char **tab, int i);
unsigned char	*my_strcat(unsigned char *param, unsigned char *av);
char		**xchdir(char *dest, char **env);
char		**my_chdir(char *path, char *s, char **environ);
char		**com_to_tab(char *str, char c);
char		*check_s(char *s);
char		*add(char **str, int i);
char		*filename(char *tab, char *s);
char		*checkend_s(char *s);

#endif /* !MINISHELL1_H_ */
