/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 07:47:10 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/25 09:03:51 by abarchil         ###   ########.fr       */
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

void	ft_clear_list(t_words *words)
{
	t_words *tmp;

	tmp = words->next;
	while (words)
	{
		tmp = words;
		words = words->next;
		free(tmp->words);
		tmp->words = NULL;
		tmp->next = NULL;
	}
}
