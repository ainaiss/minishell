/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 09:32:41 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/20 20:27:58 by fel-boua         ###   ########.fr       */
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
	while (export->next)
	{
		export->print_exec = 1;
		export = export->next;
	}
	export->print_exec = 1;
}