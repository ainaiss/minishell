/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:58:02 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/18 19:19:05 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char    **ft_export(char *var, char **env)
{
    char    **new_env;
    int     count;
    int     len;

    len = ft_strlen_2d(env);
    count = -1;
    new_env = (char **)malloc(sizeof(char *) * len + 2);
    if (!new_env)
    return (NULL);
    while (env[++count])
        new_env[count] = env[count];
    new_env[count] = var;
    count++;
    new_env[count] = NULL;
    // free(var);
    // free(env);
    return (new_env);
}
