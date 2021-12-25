/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:36:07 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/25 10:49:53 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lstadd_back(t_export *lst, t_export *new)
{
	t_export	*tmp;

	tmp = lst;
	if (lst)
	{
		if (lst == NULL)
			lst = new;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
			tmp = NULL;
		}
	}
}

void	ft_lstadd_back_cmd(t_cmd *lst, t_cmd *new)
{
	t_cmd	*tmp;

	tmp = lst;
	if (lst)
	{
		if (lst == NULL)
			lst = new;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
			tmp = NULL;
		}
	}
}

void	ft_lstadd_back_words(t_words *lst, t_words *new)
{
	t_words	*tmp;

	tmp = lst;
	if (lst)
	{
		if (lst == NULL)
			lst = new;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
			tmp = NULL;
		}
	}
}
