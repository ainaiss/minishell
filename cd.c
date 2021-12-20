/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:16:59 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/20 07:35:15 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_cd(char *command)
{
	char	**splited_command;

	splited_command = ft_split(command, ' ');
	if (!ft_strcmp(&command[1], "-"))
		chdir(getenv("OLDPWD"));
}
