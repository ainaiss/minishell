/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 03:47:11 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/05 02:44:43 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_here_doc(t_cmd *cmd)
{
	char	*tmp;
	char	*buffer;
	buffer = calloc(1, 1);
	while (TRUE)
	{
		write(1, "here_doc> ", 11);
		tmp = get_next_line(0);
		if (!ft_memcmp(tmp, cmd->files->filename, ft_strlen(cmd->files->filename)))
		{
			if (cmd->files->next)
			{
				while (cmd->files)
				{
					cmd->files->next->fd = open(cmd->files->next->filename, O_CREAT | O_TRUNC | O_RDONLY | O_WRONLY, 0644);
					dup2(cmd->files->next->fd, STDOUT_FILENO);
					close (cmd->files->next->fd);
					write (1, buffer, ft_strlen(buffer));
					cmd->files = cmd->files->next;
				}
			}
			else
				write (1, buffer, ft_strlen(buffer));
			break ;
		}
		buffer = ft_strjoin(buffer, tmp);
	}
	free(buffer);
	buffer = NULL;
}
