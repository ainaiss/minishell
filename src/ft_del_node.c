/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 07:47:10 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/21 11:55:14 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_del_node(t_export *lst, char *content)
{
	t_export *tmp;
	while (lst->next)
	{
		tmp = lst->next;
		if (!ft_memcmp(content, tmp->variable, ft_strlen(content)))
		{
			lst->next = lst->next->next;
			free(tmp->variable);
			free(tmp);
			tmp->next = NULL;
			tmp = NULL;
			return ;
		}
		lst = lst->next;
	}
}