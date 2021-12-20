/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:54:20 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/20 00:07:22 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# define GREEN "\e[0;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define TRUE 1
# define YES 1
# define FALSE 0
# define NO 0
typedef struct t_export_variable
{
	char					*variable;
	int						print_exec;
	struct t_export_variable *next;
} t_export;

typedef struct t_command_history
{
	char					*command;
	struct t_command_history *next;
	struct t_command_history *previous;
	
	
} t_history;


/** libft **/
void		ft_bzero(void *s, size_t n);
void		ft_lstadd_back(t_export *lst, t_export *new);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
t_export	*ft_lstnew(void *content);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*get_next_line(int fd);
int    		ft_strcmp(const char *s1, const char *s2);
t_export	*ft_lstlast(t_export *lst);
char		*ft_strchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);

/* export command */

void		ft_pwd(void);
void		history_init(t_history *history, char *command);
void		env_command(t_export *export);
void		check_command(char *command, char **env, t_export *export);
void		ft_export(char *var, t_export *export, int exec_print);
void		environment_init(char **env, t_export *export);
t_export	*ft_lstnew(void *content);
void		ft_lstadd_back(t_export *lst, t_export *new);
void		parsing_export_command(char *command, t_export *export);
void 		print_export(t_export *export);
#endif