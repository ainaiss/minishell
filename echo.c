/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:03:33 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/21 14:55:14 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_echo(char *command, t_export *export)
{
	(void)export;
	int		count;
	char	*string;
	char	*single_quotes;

	count = 0;
	string = ft_strtrim(command, "echo");
	single_quotes = ft_strchr(string, '\'');
	if (single_quotes && !ft_strchr(single_quotes + 1, '\''))
	{
		ft_putstr_fd("quotes error\n", 1);
		return ;
	}
	else if (single_quotes && ft_strchr(single_quotes + 1, '\''))
		ft_putstr_fd(string, 1);
	else
		printf("%s\n", string);
}