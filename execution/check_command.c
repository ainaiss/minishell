/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 01:16:48 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/02 02:19:24 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_command(t_cmd *cmd, t_export *export)
{
	if (!cmd->command)
		return ;
	if (!ft_strcmp(cmd->command, "echo") || !ft_strcmp(cmd->command, "ECHO"))
			ft_echo(cmd);
		else if (!ft_strcmp(cmd->command, "pwd") || !ft_strcmp(cmd->command, "PWD"))
			ft_pwd(cmd, export);
		else if (!ft_strcmp(cmd->command, "exit") || !ft_strcmp(cmd->command, "EXIT"))
			ft_exit(cmd);
		else if (!ft_strcmp(cmd->command, "cd") || !ft_strcmp(cmd->command, "CD"))
			ft_cd(cmd, export);
		else if (!ft_strcmp(cmd->command, "export") || !ft_strcmp(cmd->command, "EXPORT"))
			ft_export(cmd, export);
		else if (!ft_strcmp(cmd->command, "unset") || !ft_strcmp(cmd->command, "UNSET"))
			ft_unset(cmd, export);
		else if (!ft_strcmp(cmd->command, "env") || !ft_strcmp(cmd->command, "ENV"))
			ft_env(export);
}