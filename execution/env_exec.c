/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:59:42 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/05 08:40:27 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env(t_export *export)
{
	while (export)
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
	return (0);
}
