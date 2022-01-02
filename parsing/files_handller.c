/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_handller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:15:34 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/02 23:20:58 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	open_files(t_cmd *cmd)
{
	while (cmd->files)
	{
		if (cmd->files->type == 2)
			cmd->files->fd = open(cmd->files->filename, O_CREAT | O_RDWR, 0644);
		else if(cmd->files->type == 3)
			cmd->files->fd = open(cmd->files->filename, O_CREAT | O_RDWR, 0644);
		else if(cmd->files->type == 4)
			cmd->files->fd = open(cmd->files->filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
		//else if(cmd->files->type == 5)
			//hredoc
		cmd->files = cmd->files->next;
	}
}

void	handling_input(t_cmd *cmd)
{
	printf("%d\n", cmd->files->type);
	printf("%d\n", cmd->files->fd);
	puts(cmd->files->filename);
	while (cmd->files)
	{
		if (cmd->files->type == 2)
		{
			dup2(cmd->files->fd, STDOUT_FILENO);
			close(cmd->files->fd);
		}
		else if (cmd->files->type == 3)
		{
			dup2(cmd->files->fd, STDOUT_FILENO);
			close(cmd->files->fd);
		}
		cmd->files = cmd->files->next;
	}
}
