/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:46:10 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/20 15:03:46 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int     count_c(char *s, char c)
{
    int     count;
    int     i;
    
    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] == c)
            count++;
        i++;
    }
    return (count);
}

char    *remchar(char *s, char c)
{
    int     count;
    int     res_count;
    char    *res;

    count = 0;
    res_count = 0;
    res = (char *)malloc(sizeof(char) * (ft_strlen(s) - count_c(s, c) + 1));
    if (!res)
        return (NULL);
    while (s[count])
    {
        while (s[count] == c)
            count++;
        res[res_count++] = s[count++];
    }
    res[res_count] = '\0';
    return (res);
}