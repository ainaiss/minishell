/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 06:07:57 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/23 23:10:05 by abarchil         ###   ########.fr       */
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
	while(command[count] && command[count] != DELIMITER)
		count++;
	if (command[count - 1] > 0)
		cmds->words = ft_strndup(command, count);
	while (command[count] && command[count] == DELIMITER)
		count++;
	last_index = count;
	while (command[count])
	{
		while (command[count] && command[count] != DELIMITER)
			count++;
		if (command[count - 1] > 0)
			ft_lstadd_back_cmds(cmds, ft_lstnew_cmds(ft_substr(command, last_index, count - last_index)));
		while (command[count] && command[count] == DELIMITER)
			count++;
		last_index = count;
		count++;
	}
}

void	put_parse(t_words *words)
{
	while (words->next)
	{
		puts(words->words);
		words = words->next;
	}
	puts(words->words);
}