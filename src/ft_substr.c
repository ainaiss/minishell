/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:27:46 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/21 08:49:05 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_substr(char const *s, int start, size_t len)
{
	char			*str;
	char			*res_tab;
	int				i;

	i = 0;
	str = (char *)s;
	if (start >= ft_strlen(str))
		return (ft_calloc(1, 1));
	res_tab = (char *)malloc(len + 1);
	if (!res_tab)
		return (NULL);
	while (str[start] && len > 0)
	{
		res_tab[i] = str[start];
		start++;
		i++;
		len--;
	}
	res_tab[i] = '\0';
	return (res_tab);
}
