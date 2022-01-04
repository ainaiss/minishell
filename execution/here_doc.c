/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 03:47:11 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/04 14:39:39 by abarchil         ###   ########.fr       */
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
			write (1, buffer, ft_strlen(buffer));
			break ;
		}
		buffer = ft_strjoin(buffer, tmp);
	}
	free(buffer);
	buffer = NULL;
}
