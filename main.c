/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2022/01/02 19:51:14 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_export	export;
	t_words		words;
	t_pipe		pipe_;
	t_cmd		*cmd;
	char		*command;
	int			*lampe;
	//int i = -1;
	// while(i);
	(void)argc;
	(void)argv;
	lampe = ft_calloc(2, 4);
	environment_init(env, &export);
	while (TRUE)
	{
		cmd = NULL;
		command = readline("\e[1;91mminishell_> \e[0m");
		add_history(command);
		if (!command[0])
			continue;
		command = lexing(command, &lampe);
		if (check_lexing_syntax(command) == -1)
			continue;
		parsing_word(command, &words);
		cmd = parsing(&words, cmd);
		//parse_dollar_signe(cmd, &export);
		ft_child_process(env, &pipe_, cmd);
		//check_command(cmd, &export);
		//ft_execution(env, &pipe_, cmd);
		ft_clear_list(&words);
		ft_clear_list_cmd(cmd);
		free(command);
	}
	return (0);
}
