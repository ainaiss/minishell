/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 07:47:10 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/21 09:54:53 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_del_node(t_export *lst, char *content)
{
	t_export *tmp;
	
	while (lst->next)
	{
		tmp = lst->next;
		if (!ft_strcmp(content, tmp->variable))
		{
			lst->next = lst->next->next;
			free(tmp->variable);
			free(tmp);
			tmp->next = NULL;
			tmp = NULL;
			break;
		}
		lst = lst->next;
	}
}