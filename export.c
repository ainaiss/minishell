/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:58:02 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/20 19:52:54 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"


// char	*export_single_quotes(char *command)
// {
// 	char	*single_quotes;
	
// 	single_quotes = ft_strchr(command, '\'');
// 	if (!single_quotes)
// 		return (NULL);
// 	else if (single_quotes && ft_strchr(single_quotes + 1, '\''))
// 		return (remchar(command, '\''));
// 	else if (single_quotes && !ft_strchr(single_quotes + 1, '\''))
// 		return (NULL)
// }

void	parsing_export_command(char *command, t_export *export)
{
	char	*equal;
	char	*quotes;
	//char	*without_quotes;
	command = command + 6;
	equal = ft_strchr(command, '=');
	quotes = ft_strchr(command, 34);
	if (!equal)
		ft_export(command, export, NO);

	// if (quotes && !ft_strchr(quotes + 1, 34))
	// 	ft_putstr_fd("dquot error\n", 1);
	// if(quotes && ft_strchr(quotes + 1, 34))
	// {
	// 	without_quotes = remchar(command, 32);
		
	// 	ft_export(without_quotes, export, NO);
	// }
	else
	{
		if (command[ft_strchr_index(command, '=') - 1] == ' ' && ft_strlen(equal) > 1)
			ft_putstr_fd("minishell : bad assigment\n", 1);
		if (ft_strlen(equal) > 1)
			ft_export(command, export, YES);
		else
			ft_export(command, export, YES);
	}
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
