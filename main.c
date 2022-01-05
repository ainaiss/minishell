/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2022/01/05 05:33:05 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_export	export;
	t_words		*words;
	//t_pipe		pipe_;
	t_cmd		*cmd;
	char		*command;
	int			*lampe;

	// int i = 1;
	// while (i);
	(void)argc;
	(void)argv;
	lampe = ft_calloc(2, 4);
	environment_init(env, &export);
	signals();
	while (TRUE)
	{
		cmd = NULL;
		words = NULL;
		command = readline("\e[1;91mminishell_> \e[0m");
		add_history(command);
		if (!command)
			ft_exit(cmd);
		if (!command[0])
			continue;
		command = lexing(command, &lampe);
		if (check_lexing_syntax(command) == -1)
			continue;
		parsing_word(command, words);
		cmd = parsing(words, cmd);
		//parse_dollar_signe(cmd, &export);
		// while (cmd)
		// {
		// 	puts(cmd->command);
		// 	cmd = cmd->next;
		// }
		// exit(0);
		//ft_child_process(&pipe_, cmd, &export);
		//check_command(cmd, &export);
		ft_clear_list(words);
		free(command);
	}
	return (0);
}
