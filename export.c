/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:58:02 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/19 23:20:00 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	parsing_export_command(char *command, t_export *export)
{
	int		count;

	count = 0;
	command = command + 6;
	while (command[count]  && command[count] != '=')
		count++;
	if (command[count] != '\0' && command[count - 1] != ' ')
		ft_export(command, export);
	else
	{
		ft_putstr_fd(&command[count + 1], 1);
		ft_putstr_fd(" not found\n", 1);
	}
}
void 	print_export(t_export *export)
{
	while (export->next)
	{
		ft_putstr_fd(export->variable, 1);
		ft_putchar_fd('\n', 1);
		export = export->next;
	}
	ft_putstr_fd(export->variable, 1);
	ft_putchar_fd('\n', 1);
	
}
void	ft_export(char *var, t_export *export)
{
	ft_lstadd_back(export, ft_lstnew(ft_strdup(var)));
}
