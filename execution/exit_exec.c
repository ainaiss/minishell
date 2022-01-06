/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 07:58:13 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/06 07:13:23 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(t_cmd *cmd)
{
	if (!cmd || ft_strlen_2d(cmd->args) == 1)
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	if (ft_strlen_2d(cmd->args) > 2)
		ft_putstr_fd("exit: too many arguments\n", 1);
	else if (!ft_isnumber(cmd->args[1]))
	{
		printf("exit: %s: numeric argument required\n", cmd->args[1]);
		exit(255);
	}
	else
		exit(ft_atoi(cmd->args[1]));
	return (0);
}
