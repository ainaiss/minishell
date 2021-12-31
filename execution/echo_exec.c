/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 05:27:02 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/31 08:54:52 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_echo(t_cmd *cmd)
{
	int		index;
	int		new_line;

	new_line = 0;
	index = 0;
	if (!cmd->args[1])
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	if (cmd->args[1][0] == '-' && cmd->args[1][1] == 'n')
	{
		new_line = 1;
		index = 2;
	}
	else
		index = 1;
	while (cmd->args[index])
	{
		ft_putstr_fd(cmd->args[index], 1);
		if (cmd->args[index + 1])
			ft_putchar_fd(' ', 1);
		index++;
	}
	if (new_line == 0)
		ft_putchar_fd('\n', 1);
}