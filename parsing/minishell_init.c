/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:16:18 by fel-boua          #+#    #+#             */
/*   Updated: 2022/01/06 07:15:10 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	environment_init(char **env, t_export *export)
{
	int		count;

	count = 0;
	export->variable = ft_strdup(env[0]);
	export->print_exec = 1;
	while (env[++count])
		ft_lstadd_back(export, ft_lstnew(env[count]));
	while (export)
	{
		export->print_exec = 1;
		export = export->next;
	}
}
