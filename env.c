/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:21:28 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/20 19:45:32 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	env_command(t_export *export)
{
	while (export->next)
	{
		if (export->print_exec == 1)
		{
			ft_putstr_fd(export->variable, 1);
			ft_putchar_fd('\n', 1);
			export = export->next;
		}
		else
			export = export->next;
	}
	if (export->print_exec == 1)
	{	
		ft_putstr_fd(export->variable, 1);
		ft_putchar_fd('\n', 1);
	}
	else
		return ;
}
