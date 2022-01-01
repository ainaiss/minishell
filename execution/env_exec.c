/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:59:42 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/01 18:01:20 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
void	ft_env(t_export *export)
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
}