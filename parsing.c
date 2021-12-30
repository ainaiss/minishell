/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 06:07:57 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/30 16:26:07 by abarchil         ###   ########.fr       */
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
	cmd->next = NULL;
	cmd->files  = NULL;
	cmd->args =  ft_split(words->words, SPACE);
	if (cmd->args[0][0] > 0)
		cmd->command = ft_strdup(cmd->args[0]);
	else if (cmd->args[0][0] < 0 && ft_strlen(words->words) > 1)
		cmd->command = ft_strdup(cmd->args[2]);
	while (cmd->args[++i])
	{
		if (cmd->args[i][0] == REDIRECTION_IN || cmd->args[i][0] == REDIRECTION_OUT || cmd->args[i][0] == REDIRECTION_OUT_APPEND)
		{
				i++;
			ft_lstadd_back_file(&cmd->files, ft_lstnew_files(cmd->args[i]));
			if (cmd->args[i][0] == REDIRECTION_IN)
				cmd->files->type = 2;
			else if (cmd->args[i][0] == REDIRECTION_OUT)
				cmd->files->type = 3;
		}
	}
	cmd->args = delete_array(cmd->args);
	return (cmd);
}

t_cmd	*parsing(t_words *words, t_cmd *cmd)
{
	while (words)
	{
		ft_lstadd_back_cmd(&cmd, parse_commands(words, cmd));
		words = words->next;
	}
	return (cmd);
}

char	**delete_array(char **av)
{
	int		index;
	int		tmp_av_index;
	char	**tmp_av;
	
	index = 0;
	tmp_av_index = 0;
	tmp_av = (char **)malloc(sizeof(char *) * ft_strlen_2d(av) - 1);
	if (!tmp_av)
		return (NULL);
	while (av[index])
	{
		if (av[index][0] < 0 && av[index + 2])
			index += 2;
		else if (av[index][0] < 0 && !av[index + 2])
			break ;
		else
		{
			tmp_av[tmp_av_index] = ft_strdup(av[index]);
			tmp_av_index++;
			index++;
		}
	}
	tmp_av[tmp_av_index] = NULL;
//	ft_free_2d(av);
	return (tmp_av);
}