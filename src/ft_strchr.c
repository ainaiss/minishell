/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:30:58 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/07 22:34:36 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	// if (*s == '\0' && c == '\0')
	// 	return ((char *)s);
	return (NULL);
}

int	ft_strchr_index(char *s, int c)
{
	int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			return (count);
		count++;
	}
	return (0);
}
