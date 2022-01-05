/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 01:16:48 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/05 00:42:07 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_command(t_cmd *cmd, t_export *export)
{
	if (cmd->command)
	{
		if (!ft_strcmp(cmd->command, "echo") || !ft_strcmp(cmd->command, "ECHO"))
			return (ft_echo(cmd));
		else if (!ft_strcmp(cmd->command, "pwd") || !ft_strcmp(cmd->command, "PWD"))
			return (ft_pwd(cmd, export));
		else if (!ft_strcmp(cmd->command, "exit") || !ft_strcmp(cmd->command, "EXIT"))
			return (ft_exit(cmd));
		else if (!ft_strcmp(cmd->command, "cd") || !ft_strcmp(cmd->command, "CD"))
			return (ft_cd(cmd, export));
		else if (!ft_strcmp(cmd->command, "export") || !ft_strcmp(cmd->command, "EXPORT"))
			return (ft_export(cmd, export));
		else if (!ft_strcmp(cmd->command, "unset") || !ft_strcmp(cmd->command, "UNSET"))
			return (ft_unset(cmd, export));
		else if (!ft_strcmp(cmd->command, "env") || !ft_strcmp(cmd->command, "ENV"))
			return (ft_env(export));
	}
	return (-1);
}