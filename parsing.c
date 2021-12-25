/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 06:07:57 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/25 17:06:04 by abarchil         ###   ########.fr       */
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
		ft_lstadd_back_words(cmds, ft_lstnew_words(ft_strtrim(ft_substr(command, last_index, count - last_index), " ")));
		count++;
	}
}

// void	parse_commands(t_words *words, t_cmd *cmd)
// {
// 	int		count;

// 	count = 0;
// 	while(words->words[count] != ' ' && words->words[count] > 0)
// 		count++;
// 	cmd = ft_lstnew(ft_substr(words->words, 0, count - 1);

// }

void	put_parse(t_cmd *words)
{
	int		count;

	count = -1;
	while (words)
	{
		puts("==================command==================");
		puts(words->command);
		puts("==================Argemunt==================");
		while (words->args[++count])
			puts(words->args[count]);
		words = words->next;
	}
		puts("==================END==================");
}
