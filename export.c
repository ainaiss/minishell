/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:58:02 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/21 07:39:12 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
char	*set_double_quotes(char *command)
{
	int		count;
	char	*new_command;
	
	count = 0;
	new_command = ft_strdup("");
	while (command[count] && command[count] != '=')
		count++;
	if (!command[count])
		return (command);
	count++;
	new_command = ft_memmove(new_command, command, count);
	new_command = ft_strjoin(new_command, "\"");
	new_command = ft_strjoin(new_command, &command[count]);
	new_command = ft_strjoin(new_command, "\"");
	//free(command);
	return (new_command);
}
void	parsing_export_command(char *command, t_export *export)
{
	char	*equal;
	char	*quotes;
	char	*single_quotes;
	command = command + 6;
	equal = ft_strchr(command, '=');
	quotes = ft_strchr(command, 34);
	single_quotes = ft_strchr(command, '\'');
	if (quotes)
	{
		if (!ft_strchr(quotes + 1, 34))
		{
			ft_putstr_fd("dquot error\n", 1);
			return ;
		}
		command = remchar(command, 34);
	}
	else if (single_quotes)
	{
		if (!ft_strchr(single_quotes + 1, '\''))
		{
			ft_putstr_fd("dquot error\n", 1);
			return ;
		}
		command = remchar(command, '\'');
	}
	if (equal)
		ft_export(set_double_quotes(command), export, YES);
	else
		ft_export(command, export, NO);
}

void	print_export(t_export *export)
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
