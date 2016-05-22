/*
** get_next_line.c for  in /home/sepret_f/progelem/CPE_2015_getnextline
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Sun Jan 17 12:14:31 2016 fabrice sepret
** Last update Fri Jan 22 11:29:50 2016 fabrice sepret
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*get_next_line(const int fd)
{
  static s_var	var;

  if ((var.i == 0
       && (var.r = read(fd, var.buf, READ_SIZE)) < 1)
      || var.j == 0 && (var.result = malloc(PRINT_MAX)) == NULL)
    return (NULL);
  while (var.i != var.r)
    {
      if (var.buf[var.i] == 0 || var.buf[var.i] == '\n')
	{
	  var.i++;
	  var.result[var.j] = 0;
	  var.j = 0;
	  return (var.result);
	}
      var.result[var.j++] = var.buf[var.i++];
    }
  var.i = 0;
  get_next_line(fd);
}
