/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:58:02 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/19 21:12:36 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*parsing_export_command(char *command, t_export *export)
{
	char	**splited_command;
	int		count;

	count = 0;
	command = command + 6;
	while (command[count]  && command[count] != '=')
		count++;
	if (command[count] == '\0')
		ft_export(command, export);
	
}

char    **ft_export(char *var, t_export *export)
{
	ft_lstadd_back(export, ft_lstnew(ft_strdup(var)));
}
