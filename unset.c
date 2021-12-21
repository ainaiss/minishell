/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 07:40:59 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/21 11:48:47 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_unset(char *command, t_export *export)
{
	int count;
	int	equal;
	count = 0;
	equal = 0;
	while (command[count] && command[count] != ' ')
		count++;
	command = &command[count + 1];
	while (command[equal] && command[equal] != '=')
		equal++;
	command = ft_substr(command, 0, equal);
	ft_del_node(export, command);
}