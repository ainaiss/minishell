/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:44:57 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/06 18:50:01 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
void	execute_command(t_pipe *pipe_, t_cmd *cmd, t_export *export)
{
	char	*command;
	char	**env;

	env = lst_to_array(export);
	pipe(pipe_->pipefd);
	pipe_->pid = fork();
	if (pipe_->pid == 0)
	{
		command = ft_check_excute(cmd, env);
		multi_redirection(cmd);
		close(pipe_->pipefd[R]);
		dup2(pipe_->pipefd[W], STDOUT_FILENO);
		if (check_command(cmd, export) == -1)
			execve(command, cmd->args, env);
	}
	else
	{
		close(pipe_->pipefd[W]);
		dup2(pipe_->pipefd[R], STDIN_FILENO);
		wait(NULL);
	}
}

void	ft_execution(t_pipe *pipe_, t_cmd *cmd, t_export *export)
{
	int		cmd_count;
	char	*command;
	char	**env;

	env = lst_to_array(export);
	cmd_count = ft_lstsize(cmd);
	if (!ft_strcmp(cmd->command, "exit")
			|| !ft_strcmp(cmd->command, "EXIT"))
		ft_exit(cmd);
	if (pipe(pipe_->pipefd) == -1)
		return (perror("pipe"));
	pipe_->pid = fork();
	if (pipe_->pid == -1)
		return (perror("fork"));
	if (pipe_->pid == 0)
	{
		while(cmd_count - 1)
		{
			execute_command(pipe_, cmd, export);
			cmd_count--;
			cmd = cmd->next;
		}
		command = ft_check_excute(cmd, env);
		multi_redirection(cmd);
		if(check_command(cmd, export) == -1)
			execve(command, cmd->args, env);
		close (cmd->files->fd);
		free(command);
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
	if (ft_strchr(cmd->command, '/'))
		return(cmd->command);
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
			//free 2D array;
			return (finall_path);
		}
		free(finall_path);
		finall_path = NULL;
		i++;
	}
	printf("minishell: %s: command not found\n", cmd->command);
	free(splited_path);
	splited_path = NULL;
	return (NULL);
}
