/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 06:07:57 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/27 19:06:03 by abarchil         ###   ########.fr       */
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

int		count_word(char *s)
{
	int		count;
	int 	words;

	count  = 0;
	words = 0;
	while (s[count])
	{
		if (s[count] && s[count] != SPACE)
		{
			words++;
			while (s[count] && s[count] != SPACE)
				count++;
		}
		while (s[count] && s[count] == SPACE)
			count++;
	}
	return (words);
}

t_cmd	*parse_commands(t_words *words, t_cmd *cmd)
{
	int		count;
	int		args_count;
	int		tmp;

	tmp = 0;
	count = 0;
	args_count = 0;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return NULL;
	cmd->args = (char **)malloc(sizeof(char *) * count_word(words->words) + 1);
	while (args_count < count_word(words->words))
	{
		while (words->words[count] && words->words[count] != SPACE)
			count++;
		while (words->words[count] && words->words[count] == SPACE)
			count++;
		cmd->args[args_count] = remchar(ft_substr(words->words, tmp, count - tmp), SPACE);
		puts(cmd->args[args_count]);
		args_count++;
		tmp = count;
	}
	cmd->args[args_count] = NULL;
	return (cmd);
}

void	parsing(t_words *words, t_cmd *cmd)
{
	while (words->next)
	{
		ft_lstadd_back_cmd(cmd, parse_commands(words, cmd));
		words = words->next;
	}
	ft_lstadd_back_cmd(cmd, parse_commands(words, cmd));
}

// void	ft_check_file(t_cmd *cmd, t_files *files)
// {
	
// }
// void	put_parse(t_cmd *cmd)
// {
// 	// int i = -1;
// 	puts("======= command =======");
// 	puts(cmd->command);
// 	puts("======= argument =======");
// 	if (cmd->args)
// 		puts(cmd->args[0]);
// 	// {
// 	// 	while (cmd->args[++i])
// 	// 		puts(cmd->args[i]);
// 	// }
// }