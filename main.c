/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/19 21:05:53 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
void	check_command(char *command, char **env)
{
	if (!ft_strcmp(command, "env"))
		env_command(env);
	else if (!ft_strcmp(command, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(command, "exit"))
			exit(0);
	else if (!ft_memcmp(command, "export", 6)){}
}

int main(int argc, char **argv, char **env)
{
	t_export	export;
	t_history 	history;
    char    	*str;
	char		*buf;

	argc--;
	buf = NULL;
	history.next = NULL;
	history.previous = NULL;
	(void)argc; (void)argv; (void)env;
	environment_init(env, &export);
	while (TRUE)
	{
		str = readline("\e[1;91mminishell_> \e[0m");
		check_command(str, env);
		history_init(&history, str);
		free(str);
	}
	return(0);
}