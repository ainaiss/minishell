/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 06:07:57 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/25 08:51:35 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
t_words	*ft_lstnew_cmds(void *content)
{
	t_words	*new;

	new = (t_words *)malloc(sizeof(t_words));
	if (!new)
		return (NULL);
	new->words = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_cmds(t_words *lst, t_words *new)
{
	t_words	*tmp;

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

void	parsing_word(char *command, t_words *cmds)
{
	int		count;
	int		last_index;

	count = 0;
	last_index = count;
	if (!command || command[0] == '\n')
		return;
	while(command[count] && command[count] != PIPE)
		count++;
	last_index = count;
	while (command[count - 1] == ' ')
		count--;
	cmds->words = ft_strtrim(ft_strndup(command, count), " ");
	if (!ft_strchr(command, PIPE))
		return ;
	count = last_index + 2;
	while (command[count])
	{
		last_index = count;
		while (command[count] && command[count] != PIPE)
			count++;
		ft_lstadd_back_cmds(cmds, ft_lstnew_cmds(ft_strtrim(ft_substr(command, last_index, count - last_index), " ")));
		count++;
	}
}

void	put_parse(t_words *words)
{
	while (words)
	{
		puts(words->words);
		words = words->next;
	}
}
