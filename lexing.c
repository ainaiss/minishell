/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:54:00 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/30 17:23:55 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
char	*lexing(char *command, int **lampe)
{
	int	count;

	count = 0;
	while (command[count])
	{
		if (command[count] == '|' && !lampe[0][1] && !lampe[0][2])
			command[count] = PIPE;
		else if (command[count] == '>' && command[count + 1] == '>' && !lampe[0][1] && !lampe[0][2])
		{
			command[count] = REDIRECTION_OUT_APPEND;
			command[count + 1] = REDIRECTION_OUT_APPEND;
			count++;
		}
		else if (command[count] == '<' && command[count + 1] == '<' && !lampe[0][1] && !lampe[0][2])
		{
			command[count] = HER_DOC;
			command[count + 1] = HER_DOC;
			count++;
		}
		else if (command[count] == '>' && !lampe[0][1] && !lampe[0][2])
			command[count] = REDIRECTION_OUT;
		else if (command[count] == '<' && !lampe[0][1] && !lampe[0][2])
			command[count] = REDIRECTION_IN;
		else if ((command[count] == '$' && !lampe[0][1]) || (command[count] == '$' && !lampe[0][1] && !lampe[0][2]))
			command[count] = DOLLAR_SIGNE;
		else if (command[count] == ' ' && !lampe[0][1] && !lampe[0][2])
			command[count] = SPACE;
		else if ((command[count] == '\\' && !lampe[0][1]) || (command[count] == '\\' && !lampe[0][1] && !lampe[0][2]))
			command[count] = BACK_SLASH;
		else if (command[count] == '\"')
		{
			if (lampe[0][2] == 1)
				lampe[0][2] = 0;
			else
				lampe[0][2] = 1;
			command[count] = DOUBLE_QUOTES;
		}
		else if (command[count] == '\'')
		{
			if (lampe[0][1] == 1)
				lampe[0][1] = 0;
			else
				lampe[0][1] = 1;
			command[count] = SINGLE_QUOTES;
		}
		count++;
	}
	return (command);
}

int	lexing_first_char(char *command)
{
	if (command[0] == PIPE)
	{
		printf("syntax error near unexpected token `|'\n");
		return (0);
	}
	else if (command[0] < 0 && ft_strlen(command) == 1)
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
	while (command[size] == SPACE)
		size--;
	if (command[size] < 0 && command[size] != SPACE && command[size] != DOUBLE_QUOTES && command[size] != SINGLE_QUOTES)
	{
		printf("parse error near \'\\n\'\n");
		return (0);
	}
	return (1);
}

int		check_lexing_syntax(char *command)
{
	int		count;
	int		checker;
	
	count = 0;
	checker = 0;
	if (!lexing_first_char(command))
		return (-1);
	else if (check_quotes(command) == 0)
		return (-1);
	else if (checke_near_token(command) == -1)
		return (-1);
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
			return (-1);
		}
		count++;
	}
	if (!lexing_last_char(command))
		return (-1);
	return (0);
}

int		checke_near_token(char *command)
{
	int		index;

	index = 0;
	while (command[index])
	{
		if ((command[index] < 0 && command[index] != DOLLAR_SIGNE && command[index] != SPACE) && (command[index + 1] > 0 ))
		{
			printf("syntax error Space not found\n");
			return (-1);
		}
		index++;	
	}
	return (0);
}

int		check_quotes(char *command)
{
	int		count;
	int		quotes_num;
	
	count = 0;
	quotes_num = 0;
	while (command[count])
	{
		if (command[count] == DOUBLE_QUOTES || command[count] == SINGLE_QUOTES)
			quotes_num++;
		count++;
	}
	if ((quotes_num % 2 ) == 1)
	{
		printf("quotes error!\n");
		return (0);
	}
	return (1);
}