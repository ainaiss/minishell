/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:06:48 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/04 01:28:03 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_lstsize(t_cmd *lst)
{
	int		size;
	t_cmd	*new;

	new = lst;
	size = 0;
	while (new)
	{
		size++;
		new = new->next;
	}
	return (size);
}
