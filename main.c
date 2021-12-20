/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/20 20:27:38 by fel-boua         ###   ########.fr       */
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
}

int	main(int argc, char **argv, char **env)
{
	t_export	export;
	char		*str;
	char		*buf;

	argc--;
	buf = NULL;
	(void)argc;
	(void)argv;
	(void)env;
	environment_init(env, &export);
	while (TRUE)
	{
		str = readline("\e[1;91mminishell_> \e[0m");
		add_history(str);
		check_command(str, env, &export);
		free(str);
	}
	return (0);
}
