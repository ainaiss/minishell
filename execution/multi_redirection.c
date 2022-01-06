/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 07:50:07 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/06 07:55:02 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	multi_redirection(t_cmd *cmd)
{
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
}