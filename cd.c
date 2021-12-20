/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:16:59 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/20 02:56:59 by abarchil         ###   ########.fr       */
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