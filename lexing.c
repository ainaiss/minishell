/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:54:00 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/23 05:27:17 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
char	*lexing(char *command)
{
	int	count;

	count = 0;
	while (command[count])
	{
		if (command[count] == '|')
			command[count] = PIPE;
		else if (command[count] == '>' && command[count + 1] == '>')
		{
			command[count] = REDIRECTION_OUT_APPEND;
			command[count + 1] = REDIRECTION_OUT_APPEND;
			count += 2;
		}
		else if (command[count] == '<' && command[count + 1] == '<')
		{
			command[count] = HER_DOC;
			command[count + 1] = HER_DOC;
			count += 2;
		}
		else if (command[count] == '>')
			command[count] = REDIRECTION_OUT;
		else if (command[count] == '<')
			command[count] = REDIRECTION_IN;
		else if (command[count] == '$')
			command[count] = DOLLAR_SIGNE;
		else if (command[count] == ' ')
			command[count] =  DELIMITER;
		count++;
	}
	return (command);
}

int	lexing_first_char(char character)
{
	if (character == PIPE)
	{
		printf("syntax error near unexpected token `|'\n");
		return (0);
	}
	else if (character < 0)
	{
		printf("syntax error near unexpected token `newline'\n");
		return (0);
	}
	return (1);
}

int		lexing_last_char(char *command)
{
	int	size;

	size = ft_strlen(command);
	if (command[size] < 0 || command[size - 1 ] < 0)
	{
		printf("parse error near \'\\n\'\n");
		return (0);
	}
	return (1);
}

void	check_lexing_syntax(char *command)
{
	int		count;
	int		checker;
	
	count = 0;
	checker = 0;
	if (!lexing_first_char(command[0]))
		return ;
	else if (!lexing_last_char(command))
		return ;
	else if (!check_quotes(command))
		return ;
	while (command[count])
	{
		while (command[count] && command[count] != DELIMITER)
			count++;
		checker = count - 1;
		while (command[count] && command[count] == DELIMITER)
			count++;
		if (command[checker] < 0 && command[count] < 0)
		{
			printf("syntax error near unexpected token\n");
			return ;
		}
		count++;
	}
}

int		check_quotes(char *command)
{
	int		count;
	char	*single_q;
	char	*double_q;
	
	count = 0;
	single_q = ft_strchr(command, '\'');
	double_q = ft_strchr(command, '\"');
	if (single_q)
	{
		if (!ft_strchr(single_q + 1, '\''))
		{
			printf("quotes error\n");
			return (0);
		}
	}
	else if (double_q)
	{
		if (!ft_strchr(double_q + 1, '\"'))
		{
			printf("quotes error\n");
			return (0);
		}
	}
	return (1);
}

void	put_lexing(char *command)
{
	int	count;

	count = -1;
	while (command[++count])
	{
		if (command[count] == PIPE)
			puts("her_pipe");
		else if (command[count] == REDIRECTION_OUT)
			puts("her_red_out");
		else if (command[count] == REDIRECTION_IN)
			puts("her_red_in");
		else if (command[count] == REDIRECTION_OUT_APPEND && command[count + 1] == REDIRECTION_OUT_APPEND)
			puts("her_red_out_app");
		else if (command[count] == HER_DOC && command[count + 1] == HER_DOC)
			puts("her_her_doc");
		else if (command[count] == DOLLAR_SIGNE)
			puts("her_dollar_signe");
		else if (command[count] == DELIMITER)
			puts("her_delimiter");
	}
}