/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:36:43 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/30 14:59:02 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_2d(char **av)
{
	int		index;

	index = -1;
	while (av[++index])
	{
		free(av[index]);
		av[index] = NULL;
	}
	free(av);
	av = NULL;
}