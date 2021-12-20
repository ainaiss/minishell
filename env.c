/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:21:28 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/20 00:54:35 by abarchil         ###   ########.fr       */
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