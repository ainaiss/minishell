/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 09:32:41 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/20 00:22:38 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
void	ft_lstadd_back_2(t_history *lst, t_history *new)
{
	t_history	*tmp;

	tmp = lst;
	if (lst)
	{
		if (lst == NULL)
			lst = new;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
			tmp = NULL;
		}
	}
}

void	environment_init(char **env, t_export *export)
{
	int		count;

	count = 0;
	export->variable = ft_strdup(env[0]);
	export->print_exec = 1;
	while (env[++count])
	{
		ft_lstadd_back(export, ft_lstnew(ft_strdup(env[count])));
	}
	while (export->next)
	{
		export->print_exec = 1;
		export = export->next;
	}
	export->print_exec = 1;
}

void	history_init(t_history *history, char *command)
{
	t_history	*new;
	

	new = NULL;
	new = (t_history *)malloc(sizeof(t_history));
	if (!history)
		return ;
	ft_lstadd_back_2(history, new);
	new->command = ft_strdup(command);
	new->next = NULL;
	new->previous = history;
}
