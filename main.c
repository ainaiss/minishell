/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2022/01/06 09:19:52 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_export	export;
	t_words		*words;
	t_pipe		pipe_;
	t_cmd		*cmd;
	char		*command;
	int			*lampe;

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
			continue ;
		command = lexing(command, &lampe);
		if (check_lexing_syntax(command) == -1)
			continue ;
		words = parsing_word(command, words);
		cmd = parsing(words, cmd);
		if (ft_strchr(command, DOLLAR_SIGNE))
			parse_dollar_signe(cmd, &export);
		ft_execution(&pipe_, cmd, &export);
		ft_clear_list(words);
		free(command);
	}
	return (0);
}
