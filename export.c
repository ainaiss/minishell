/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:58:02 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/20 01:01:40 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	parsing_export_command(char *command, t_export *export)
{
	int		count;
	char	*equal;

	count = 0;
	command = command + 6;
	equal = ft_strchr(command, '=');
	if (!equal)
	{
		ft_putstr_fd(command, 1);
		ft_putstr_fd(" not found\n", 1);
	}
	else
	{
		
		if (ft_strlen(equal) > 1)
			ft_export(command, export, YES);
		else
			ft_export(command, export, NO);
	}
}

void 	print_export(t_export *export)
{
	while (export->next)
	{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(export->variable, 1);
			ft_putchar_fd('\n', 1);
			export = export->next;
	}
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(export->variable, 1);
	ft_putchar_fd('\n', 1);
	return ;
}
void	ft_export(char *var, t_export *export, int exec_print)
{
	t_export	*new;

	new = ft_lstnew(ft_strdup(var));
	if (exec_print == 1)
		new->print_exec = 1;
	else
		new->print_exec = 0;
	ft_lstadd_back(export, new);
}
