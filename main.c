/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/23 23:11:41 by abarchil         ###   ########.fr       */
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
}

int	main(int argc, char **argv, char **env)
{
	t_export	export;
	char		*command;
	t_words		words;
	
	words.next = NULL;
	argc--;
	(void)argv;
	environment_init(env, &export);
	while (TRUE)
	{
		command = readline("\e[1;91mminishell_> \e[0m");
		add_history(command);
		command = lexing(command);
		//put_lexing(command);
		check_lexing_syntax(command);
		parsing_word(command, &words);
		put_parse(&words);
		while (words.next)
		{
			free(words.words);
			words = *words.next;
		}
		free(words.words);
		check_command(command, env, &export);
		free(command);
	}
	return (0);
}
