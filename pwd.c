/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:44:41 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/20 07:27:14 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_pwd(void)
{
	char	*buf;

	buf = NULL;
	ft_putstr_fd(getcwd(buf, sizeof(buf)), 1);
	ft_putchar_fd('\n', 1);
	free(buf);
}
