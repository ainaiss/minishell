/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:03:33 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/22 13:32:22 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_echo(char *command, t_export *export)
{
	int		count;
	int		arg_count;
	char	*string;
	char	**splited_arg;
	
	count = 0;
	arg_count = -1;
	(void)export;
	while (command[count] && command[count] != ' ')
		count++;
	while (command[count] && command[count] == ' ')
		count++;
	string = &command[count];
	splited_arg = ft_split(string, ' ');
	while (splited_arg[++arg_count + 1])
		printf("%s ", splited_arg[arg_count]);
	if (string[0] == '-' && string[1] == 'n')
		printf("%s", splited_arg[arg_count]);
	else
		printf("%s\n", splited_arg[arg_count]);
}