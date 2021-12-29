/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/29 02:08:34 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	check_command(char *command, char **env, t_export *export)
{
	(void)env;
	command = ft_strtrim(command, " 	");
	if (!ft_strcmp(command, "env"))
		env_command(export);
	else if (!ft_strcmp(command, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(command, "exit"))
		exit(0);
	else if (!ft_memcmp(command, "export", 6))
	{
		if (!ft_strcmp(command, "export"))
			print_export(export);
		else
			parsing_export_command(command, export);
	}
	else if (!ft_memcmp(command, "cd", 2))
		ft_cd(command);
	else if (!ft_memcmp(command, "unset", 5))
		ft_unset(command, export);
	else if (!ft_memcmp(command, "echo", 4))
		ft_echo(command, export);
	// else
	// 	printf("minishell : command not found\n");
}

int	main(int argc, char **argv, char **env)
{
	t_export	export;
	t_words		words;
	t_cmd		*cmd;
	char		*command;
	int			*lampe;

	//int i = -1;
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
		check_lexing_syntax(command);
		parsing_word(command, &words);
		cmd = parsing(&words, cmd);
		parse_dollar_signe(cmd, &export);
		// while (cmd)
		// {
		// 	puts(cmd->command);	
		// 	while (cmd->args[++i])
		// 		puts(cmd->args[i]);
		// 	if (!cmd->next)
		// 		break;
		// 	cmd = cmd->next;
		// }
		ft_clear_list(&words);
		ft_clear_list_cmd(cmd);
		free(command);
	}
	return (0);
}
