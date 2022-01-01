/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 09:32:41 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/01 17:05:18 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	environment_init(char **env, t_export *export)
{
	int		count;

	count = 0;
	export->variable = ft_strdup(env[0]);
	export->print_exec = 1;
	while (env[++count])
		ft_lstadd_back(export, ft_lstnew(set_double_quotes(env[count])));
	while (export)
	{
		export->print_exec = 1;
		export = export->next;
	}
}