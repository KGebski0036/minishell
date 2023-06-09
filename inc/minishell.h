/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:56:14 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/09 13:04:11 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>     //* Standard Input/Output
//*							- printf();
#include <stdlib.h>    //* Memory Allocation
//*							- malloc();
//*							- free();

#include <termcap.h>   //* Terminal Capability
//*                    - tgetent();
//*                    - tgetflag();
//*                    - tgetnum();
//*                    - tgetstr();
//*                    - tgoto();
//*                    - tputs();

#include <readline/readline.h>   //* Readline
//*                             - readline();
//*                             - rl_clear_history();
//*                             - rl_on_new_line();
//*                             - rl_replace_line();
//*                             - rl_redisplay();
//*                             - add_history();

#include <unistd.h>    //* File Operations, Process Control
//*                    - write();
//*                    - access();
//*                    - open();
//*                    - read();
//*                    - close();

#include <dirent.h>    //* Directory Operations
//*                    - opendir();
//*                    - readdir();
//*                    - closedir();

#include <string.h>    //* Error Handling
//*                    - strerror();
//*                    - perror();

#include <termios.h>   //* Terminal I/O
//*                    - isatty();
//*                    - ttyname();
//*                    - ttyslot();
//*                    - ioctl();
//*                    - tcsetattr();
//*                    - tcgetattr();

#include <sys/stat.h>  //* File System
//*                    - stat();
//*                    - lstat();
//*                    - fstat();

#include <signal.h>    //* Process Control
//*                    - signal();
//*                    - sigaction();
//*                    - sigemptyset();
//*                    - sigaddset();
//*                    - kill();
//*                    - exit();

#include <curses.h>    //* Terminal Capability
//*                    - tgetflag();
//*                    - tgetnum();
//*                    - tgetstr();
//*                    - tgoto();
//*                    - tputs();

typedef struct s_env
{

}	t_env;

//*		--=[ exit.c ]=--
void		ft_exit(t_env *e, char *msg, int failure);

//*		--=[ init.c ]=--
void		input_check(t_env *e, int ac, char **av);
void		env_init(t_env *e);

//*		--=[ debug.c ]=--
void		ft_printf_env(t_env *e);

#endif
