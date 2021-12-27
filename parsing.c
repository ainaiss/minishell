/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 06:07:57 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/27 20:22:02 by abarchil         ###   ########.fr       */
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

t_cmd	*parse_commands(t_words *words, t_cmd *cmd)
{
	int	i;

	i = -1;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return NULL;
	cmd->args =  ft_split(words->words, SPACE);
	if (cmd->args[0][0] > 0)
		cmd->command = cmd->args[0];
	else
		cmd->command = cmd->args[2];
	while (cmd->args[++i])
	{
		if (cmd->args[i][0] == REDIRECTION_IN)
			cmd->red_pipe = 2;
		else if (cmd->args[i][0] == REDIRECTION_OUT)
			cmd->red_pipe = 3;
		else if (cmd->args[i][0] == REDIRECTION_OUT_APPEND)
			cmd->red_pipe = 4;
		else if (cmd->args[i][0] == HER_DOC)
			cmd->red_pipe = 5;
		else if (cmd->next)
			cmd->red_pipe = 1;
	}
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

// void	ft_check_file(t_cmd *cmd, t_files *file)
// {
// }