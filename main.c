/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2022/01/08 01:52:59 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

static void	minishell(int *lampe, t_export *export)
{
	t_words		*words;
	t_pipe		pipe_;
	t_cmd		*cmd;
	char		*command;

	cmd = NULL;
	words = NULL;
	command = readline("\e[1;91mminishell_> \e[0m");
	add_history(command);
	if (!command)
		ft_exit(cmd);
	if (!command[0])
		return ;
	command = lexing(command, &lampe);
	if (check_lexing_syntax(command) == -1)
		return ;
	words = parsing_word(command, words);
	cmd = parsing(words, cmd);
	parse_dollar_signe(cmd, export);
	ft_execution(&pipe_, cmd, export);
	ft_clear_list(words);
	free(command);
}

int	main(int argc, char **argv, char **env)
{
	t_export	export;
	int			*lampe;

	(void)argc;
	(void)argv;
	g_tools.exit_status = 0;
	lampe = ft_calloc(2, 4);
	if (argc > 1)
	{
		ft_putstr_fd("Too many argument", 2);
		return (0);
	}
	environment_init(env, &export);
	signals();
	while (TRUE)
		minishell(lampe, &export);
	return (0);
}
