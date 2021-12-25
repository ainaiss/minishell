/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:54:00 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/25 13:46:57 by abarchil         ###   ########.fr       */
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
		else if (command[count] == '\"')
			command[count] = DOUBLE_QUOTES;
		else if (command[count] == '\'')
			command[count] = SINGLE_QUOTES;
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

	size = ft_strlen(command) - 1;
	while (command[size] == ' ')
		size--;
	if (command[size] < 0 && command[size] != ' ' && command[size] != DOUBLE_QUOTES && command[size] != SINGLE_QUOTES)
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
	else if (check_quotes(command) == 0)
		return ;
	while (command[count])
	{
		while (command[count] && command[count] != ' ')
			count++;
		checker = count - 1;
		while (command[count] && command[count] == ' ')
			count++;
		if (command[checker] < 0 && command[checker] > -8 && (command[count] < 0 && command[count] > -8))
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
	single_q = ft_strchr(command, SINGLE_QUOTES);
	double_q = ft_strchr(command, DOUBLE_QUOTES);
	if (single_q)
	{
		if (!ft_strchr(single_q + 1, SINGLE_QUOTES))
		{
			printf("quotes error\n");
			return (0);
		}
	}
	else if (double_q)
	{
		if (!ft_strchr(double_q + 1, DOUBLE_QUOTES))
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
		else if (command[count] == DOUBLE_QUOTES)
			puts ("here_double_quotes");
		else if (command[count] == SINGLE_QUOTES)
			puts("here_single_quotes");
	}
}
