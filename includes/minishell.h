/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:54:20 by fel-boua          #+#    #+#             */
/*   Updated: 2021/12/18 19:15:02 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"
# define GREEN "\e[0;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
/* export command */
char    **ft_export(char *var, char **env);

#endif