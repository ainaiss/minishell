/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:23:01 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/01 06:59:52 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(t_cmd *cmd)
{
	char	*buf;

	buf = NULL;
	if (cmd->args[1] && (cmd->args[1][0] != '-' &&( cmd->args[1][1] != 'L' || cmd->args[1][1] != 'P')))
	{
		ft_putstr_fd("pwd: too many arguments\n", 1);
		return ;
	}
	ft_putstr_fd(getcwd(buf, sizeof(buf)), 1);
	ft_putchar_fd('\n', 1);
	free(buf);
}
