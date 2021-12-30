/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:23:01 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/30 20:23:29 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(void)
{
	char	*buf;

	buf = NULL;
	ft_putstr_fd(getcwd(buf, sizeof(buf)), 1);
	ft_putchar_fd('\n', 1);
	free(buf);
}
