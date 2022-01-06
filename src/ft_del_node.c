/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:17:51 by fel-boua          #+#    #+#             */
/*   Updated: 2022/01/06 07:40:56 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_del_node(t_export *lst, char *content)
{
	t_export	*tmp;

	while (lst->next)
	{
		tmp = lst->next;
		if (!ft_memcmp(content, tmp->variable, ft_strlen(content)))
		{
			lst->next = lst->next->next;
			free(tmp->variable);
			tmp->variable = NULL;
			free(tmp);
			tmp->next = NULL;
			tmp = NULL;
			return ;
		}
		lst = lst->next;
	}
}

void	ft_del_node_cmd(t_cmd *lst)
{
	t_cmd	*tmp;

	tmp = lst->next;
	if (!tmp->command)
	{
		lst->next = lst->next->next;
		free(tmp->command);
		free(tmp);
		tmp->next = NULL;
		tmp = NULL;
		return ;
	}
	lst = lst->next;
}

void	ft_clear_list(t_words *words)
{
	t_words		*tmp;

	if (!words)
		return ;
	if (words->next)
		tmp = words->next;
	else
		tmp = words;
	while (words)
	{
		tmp = words;
		words = words->next;
		free(tmp->words);
		tmp->words = NULL;
		tmp->next = NULL;
	}
}

void	ft_clear_list_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		index;

	index = -1;
	if (!cmd)
		return ;
	if (cmd->command)
	{
		while (cmd)
		{
			index++;
			tmp = cmd;
			cmd = cmd->next;
			free(tmp->command);
			tmp->command = NULL;
		}
	}
}
