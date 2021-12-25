/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 06:07:57 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/25 22:07:05 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	parsing_word(char *command, t_words *cmds)
{
	int		count;
	int		last_index;

	count = 0;
	last_index = count;
	if (!command || command[0] == '\n')
		return ;
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
		ft_lstadd_back_words(cmds, ft_lstnew_words(ft_strtrim(ft_substr(command, last_index, count - last_index), " ")));
		count++;
	}
}

void	parse_commands(t_words *words, t_cmd *cmd)
{
	int		index;
	cmd = NULL;
	index = 0;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	while(words->words[index] && words->words[index] != ' ')
		index++;
	cmd->command = ft_substr(words->words, 0, index);
	puts(cmd->command);
}

void	put_words(t_words *words)
{
	while (words->next)
	{
		puts(words->words);
		words = words->next;
	}
	puts(words->words);
}

void	put_parse(t_cmd *words)
{
	int count = -1;
	while (words->next)
	{
		puts("==================command==================");
		puts(words->command);
		puts("==================Argemunt==================");
		if (ft_strlen_2d(words->args))
		{
			while (words->args[++count])
				puts(words->args[count]);
		}
		words = words->next;
	}
	puts("==================END==================");
}
