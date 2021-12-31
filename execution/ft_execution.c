/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:44:57 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/31 05:37:41 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_child_process(char **env, t_pipe *pipe_, t_cmd *cmd, char *command)
{
	if (pipe(pipe_->pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pipe_->pid = fork();
	if (pipe_->pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pipe_->pid == 0)
	{
		close(pipe_->pipefd[R]);
		dup2(pipe_->pipefd[W], STDOUT_FILENO);
		execve(command, cmd->args, env);
	}
	else
	{
		close(pipe_->pipefd[W]);
		dup2(pipe_->pipefd[R], STDIN_FILENO);
		waitpid(-1, NULL, 0);
	}
}

char	*ft_check_path(char **env)
{
	char	*path_line;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_memcmp(env[i], "PATH=", 5) == 0)
		{
			path_line = env[i];
			return (path_line + 5);
		}
		i++;
	}
	return (NULL);
}

char	*ft_check_excute(t_cmd *cmd, char **env)
{
	int		i;
	char	**splited_path;
	char	*tmp;
	char	*finall_path;

	splited_path = ft_split(ft_check_path(env), ':');
	i = 0;
	while (splited_path[i])
	{
		if (splited_path[i][ft_strlen(splited_path[i])] != '/')
			tmp = ft_strjoin(splited_path[i], "/");
		else
			tmp = ft_strdup(splited_path[i]);
		finall_path = ft_strjoin(tmp, cmd->command);
		if (access(finall_path, X_OK | F_OK) == 0)
		{
			free(splited_path);
			return (finall_path);
		}
		free(finall_path);
		i++;
	}
	free(splited_path);
	return (NULL);
}


void	ft_execution(char **env, t_pipe *pipe_, t_cmd *cmd)
{
	int		cmd_count;
	char	*command;
	
	command = ft_check_excute(cmd, env);
	if (!command)
	{
		printf("command not found \n");
		return;
	}
	cmd_count = ft_lstsize(cmd);
	// if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	// {
	// 	pre_here_doc(pipe_, argv[2], argc);
	// 	unlink(".here_doc");
	// 	if (argv[3] == NULL || argc == 4)
	// 		return (0);
	// }
	
	if (cmd_count == 1)
	{
		pipe_->pid = fork();
	if (pipe_->pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pipe_->pid == 0)
	{
		execve(command, cmd->args, env);
	}
	else
		waitpid(-1, NULL, 0);
		cmd_count--;
	}
	while (cmd && cmd_count)
	{
		
		printf("%d\n", cmd_count);
		ft_child_process(env, pipe_, cmd, command);
		cmd_count--;
		cmd = cmd->next;
	}
}