/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:06:37 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/18 20:59:53 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int main(int argc, char **argv, char **env)
{
    char    *str;
    argc--;
    if (argc == 0)
        return (0);
    str = readline("\e[1;91mminishell$ \e[0m");
    if (ft_memcmp(argv[1], "export", 6) == 0 && argc > 2)
        env = ft_export(argv[2], env);
    for (size_t i = 0; i < ft_strlen_2d(env); i++)
		printf("%s\n", env[i]);

    char *pwd = getenv("PWD");
    printf("%s\n", pwd);
    return(0);
}