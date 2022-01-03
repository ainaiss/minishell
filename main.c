/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2022/01/03 20:45:11 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	signal_quit(int sig)
{
	(void)sig;
	puts("here");
	exit(0);
}

// void	sigint_handler_D(int sig)
// {
// 	(void) sig;
// 	ft_putstr_fd("\n", 1);
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	rl_redisplay();
// }

void	sigint_handler(int sig)
{
	(void) sig;
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv, char **env)
{
	t_export	export;
	t_words		words;
	t_pipe		pipe_;
	t_cmd		*cmd;
	char		*command;
	int			*lampe;
	(void)argc;
	(void)argv;
	// int i= 1;
	// while (i);
	lampe = ft_calloc(2, 4);
	environment_init(env, &export);
	signals();
	while (TRUE)
	{
		cmd = NULL;
		command = readline("\e[1;91mminishell_> \e[0m");
		add_history(command);
		if (!command)
			exit(0);
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
