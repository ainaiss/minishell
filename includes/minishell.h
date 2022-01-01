/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:54:20 by fel-boua          #+#    #+#             */
/*   Updated: 2022/01/01 08:12:25 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
# define W 1
# define R 0
# define PIPE -1
# define REDIRECTION_IN -2
# define REDIRECTION_OUT -3
# define REDIRECTION_OUT_APPEND -4
# define HER_DOC -5
# define DOLLAR_SIGNE -6
# define SPACE -7
# define DOUBLE_QUOTES -8
# define SINGLE_QUOTES -9
# define BACK_SLASH -10

typedef struct t_export
{
	char						*variable;
	int							print_exec;
	struct t_export				*next;
}	t_export;

typedef struct s_words
{
	char			*words;
	struct s_words	*next;
}	t_words;

typedef struct s_files
{
	int				type;
	char			*filename;
	struct s_files	*next;

}	t_files;

typedef struct		s_cmd
{
	char				*command;
	int					red_pipe;
	char				**args;
	t_files				*files;
	struct s_cmd		*next;
}					t_cmd;

typedef struct s_pipe
{
	pid_t	pid;
	int		pipefd[2];
}	t_pipe;

/************************************** SOURCES *******************************************************/

void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(const char *s);
int			ft_strlen_2d(char **s);
char		*get_next_line(int fd);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_strchr_index(char *s, int c);
char   		*remchar(char *s, char c);
int			ft_isalpha(int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, int start, size_t len);
int			ft_atoi(const char *str);
char		*ft_strndup(const char *s, int n);
void		ft_free_2d(char **av);
int			ft_isdigit(int c);

					/****** linked list *********/

t_words		*ft_lstnew_words(void *content);
t_export	*ft_lstnew(void *content);
t_files		*ft_lstnew_files(void *content);
t_cmd		*ft_lstnew_cmd(char **content);
void		ft_del_node(t_export *lst, char *content);
void		ft_clear_list(t_words *words);
void		ft_lstadd_back(t_export *lst, t_export *new);
void		ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new);
void		ft_lstadd_back_words(t_words *lst, t_words *new);
void		ft_lstadd_back_file(t_files **lst, t_files *new);
int			ft_lstsize(t_cmd *lst);
void		ft_del_node_cmd(t_cmd *lst);
void		ft_clear_list_cmd(t_cmd *cmd);

/******************************** minishell *************************************************************/

						/******** builtins *******/

void		ft_pwd(t_cmd *cmd);
void		ft_cd(char *command);
void		ft_echo(t_cmd *cmd);
void		ft_exit(t_cmd *cmd);
void		ft_export(char *var, t_export *export, int exec_print);
void		ft_unset(char *command, t_export *export);
void		env_command(t_export *export);

						/********** lixing **********/

char		*lexing(char *command, int **lampe);
int			check_lexing_syntax(char *command);
int			checke_near_token(char *command);
int			lexing_first_char(char *command);
int			lexing_last_char(char *command);
int			check_quotes(char *command);

						/******** parsing *******/

void		check_command(char *command, char **env, t_export *export);
void		environment_init(char **env, t_export *export);
void		parsing_export_command(char *command, t_export *export);
void		print_export(t_export *export);
void		parsing_word(char *command, t_words *cmds);
t_cmd		*parse_commands(t_words *words, t_cmd *cmd);
t_cmd		*parsing(t_words *words, t_cmd *cmd);
void		parse_dollar_signe(t_cmd *cmd, t_export *export);
char		*get_var(char *var, t_export *export);
char		*get_var_value(char *variable);
char		**delete_array(char **av);

						/********* EXECUTION *************/

void	ft_execution(char **env, t_pipe *pipe_, t_cmd *cmd);
void	ft_child_process(char **env, t_pipe *pipe_, t_cmd *cmd, char *command);
void	ft_one_command(char **env, t_pipe *pipe_, t_cmd *cmd);
char	*ft_check_excute(t_cmd *cmd, char **env);
char	*ft_check_path(char **env);
					/******** temporary_functions *******/

void	put_lexing(char *command);
#endif