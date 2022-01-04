/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 02:53:04 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/04 03:37:41 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**lst_to_array(t_export *export)
{
	int		len;
	int		index;
	char	**arr;

	index = 0;
	len = ft_lstsize_export(export);
	arr = (char **)malloc(sizeof(char *) *len + 1);
	if (!arr)
		return (NULL);
	while (export)
	{
		arr[index] = ft_strdup(export->variable);
		export = export->next;
		index++;
	}
	arr[index] = NULL;
	return (arr);
}