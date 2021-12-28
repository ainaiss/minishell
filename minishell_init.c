/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 09:32:41 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/29 00:10:57 by abarchil         ###   ########.fr       */
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
		ft_lstadd_back(export, ft_lstnew(ft_strdup(env[count])));
	while (export)
	{
		export->print_exec = 1;
		export = export->next;
	}
}