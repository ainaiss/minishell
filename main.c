/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2022/01/01 07:02:13 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_export	export;
	t_words		words;
	//t_pipe		pipe_;
	t_cmd		*cmd;
	char		*command;
	int			*lampe;

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
		// int i = -1;
		// while (cmd->args[++i])
		// 	puts(cmd->args[i]);
		parse_dollar_signe(cmd, &export);
		if (!ft_strcmp(cmd->command, "echo") || !ft_strcmp(cmd->command, "ECHO"))
			ft_echo(cmd);
		else if (!ft_strcmp(cmd->command, "pwd") || !ft_strcmp(cmd->command, "PWD"))
			ft_pwd(cmd);
		else if (!ft_strcmp(cmd->command, "exit") || !ft_strcmp(cmd->command, "EXIT"))
			exit(0);
		// if (ft_lstsize(cmd) == 1)
		// {
		// 	command = ft_check_excute(cmd, env);
		// 	pipe_.pid = fork();
		// 	if (pipe_.pid == -1)
		// 	{
		// 		perror("fork");
		// 		exit(EXIT_FAILURE);
		// 	}
		// 	if (pipe_.pid == 0)
		// 	{
		// 		execve(command, cmd->args, env);
		// 	}
		// 	else
		// 	waitpid(-1, NULL, 0);
		// }
		// else if(ft_lstsize(cmd) > 1)
		// {
		// 	while (cmd)
		// 	{
		// 		command = ft_check_excute(cmd, env);
		// 		ft_child_process(env, &pipe_, cmd, command);
		// 		free(command);
		// 		cmd = cmd->next;
		// 	}
		// }
		//ft_execution(env, &pipe_, cmd);
		ft_clear_list(&words);
		ft_clear_list_cmd(cmd);
		free(command);
	}
	return (0);
}
