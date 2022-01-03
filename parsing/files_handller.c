/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_handller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:15:34 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/03 01:04:14 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void	handling_input(t_cmd *cmd)
{
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
