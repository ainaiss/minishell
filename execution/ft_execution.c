/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:44:57 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/05 06:37:12 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_child_process(t_pipe *pipe_, t_cmd *cmd, t_export *export)
{
	int		cmd_count;
	char	*command;
	char	**env;

	env = lst_to_array(export);
	cmd_count = ft_lstsize(cmd);
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
		while(cmd_count - 1)
		{
			pipe(pipe_->pipefd);
			pipe_->pid = fork();
			if (pipe_->pid == 0)
			{
				command = ft_check_excute(cmd, env);
						if (cmd->files)
						{
							if (cmd->files->type == 2 || cmd->files->type == 3)
								cmd->files->fd = open(cmd->files->filename, O_CREAT | O_TRUNC | O_RDONLY | O_WRONLY, 0644);
							else if (cmd->files->type == 4)
								cmd->files->fd = open(cmd->files->filename, O_CREAT | O_APPEND | O_RDONLY | O_WRONLY, 0644);
							dup2( cmd->files->fd, STDOUT_FILENO);
							close(cmd->files->fd);
						}
						close(pipe_->pipefd[R]);
				dup2(pipe_->pipefd[W], STDOUT_FILENO);
				printf("write end : %d\n", pipe_->pipefd[W]);
				close(pipe_->pipefd[W]);
				if (check_command(cmd, export) == -1)
					execve(command, cmd->args, env);
			}
			else
			{
				close(pipe_->pipefd[W]);
				dup2(pipe_->pipefd[R], STDIN_FILENO);
				printf("Read end : %d\n", pipe_->pipefd[R]);
				wait(NULL);
			}
			cmd_count--;
			cmd = cmd->next;
		}
		command = ft_check_excute(cmd, env);
		while (cmd->files)
		{
			if (cmd->files->type == 5)
					ft_here_doc(cmd);
			if (cmd->files->type == 2 || cmd->files->type == 3)
			{
				cmd->files->fd = open(cmd->files->filename, O_CREAT | O_TRUNC | O_RDONLY | O_WRONLY, 0644);
				dup2(cmd->files->fd, STDOUT_FILENO);
				close (cmd->files->fd);
			}
			if (cmd->files->type == 4)
			{
				cmd->files->fd = open(cmd->files->filename, O_CREAT | O_APPEND | O_RDONLY | O_WRONLY, 0644);
				dup2(cmd->files->fd, STDOUT_FILENO);
				close (cmd->files->fd);
			}
			cmd->files = cmd->files->next;
		}
		if (check_command(cmd, export) == -1)
			execve(command, cmd->args, env);
		free(command);
		command = NULL;
	}
	else
		waitpid(-1, NULL, 0);
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
		finall_path = NULL;
		i++;
	}
	free(splited_path);
	splited_path = NULL;
	return (NULL);
}
