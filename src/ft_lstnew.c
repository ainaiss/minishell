/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 13:17:29 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/19 17:01:39 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_export	*ft_lstnew(void *content)
{
	t_export	*new;

	new = (t_export *)malloc(sizeof(t_export));
	if (!new)
		return (NULL);
	new->variable = content;
	new->next = NULL;
	return (new);
}
