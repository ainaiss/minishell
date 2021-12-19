/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:21:28 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/19 12:44:16 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	env_command(char **env)
{
	int	count;

	count = 0;
	while (env[count])
	{
		ft_putstr_fd(env[count], 1);
		ft_putchar_fd('\n', 1);
		count++;
	}
}