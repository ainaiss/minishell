/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dollar_signe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:16:06 by fel-boua          #+#    #+#             */
/*   Updated: 2022/01/05 08:50:50 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_var(char *var, t_export *export)
{
	while (export)
	{
		if (!ft_memcmp(export->variable, var, ft_strlen(var)))
			return (export->variable);
		export = export->next;
	}
	return (NULL);
}

char	*get_var_value(char *variable)
{
	int	index;

	index = 0;
	if (!variable)
		return (NULL);
	while (variable[index] && variable[index] != '=')
		index++;
	index++;
	return (ft_substr(variable, index, ft_strlen(variable) - index));
}

void	parse_dollar_signe(t_cmd *cmd, t_export *export)
{
	int		index;
	int		count;
	int		tmp;
	char	*var;
	char	*tmp_arg;

	index = 0;
	count = 0;
	while (cmd)
	{
		while (cmd->args[++index])
		{
			cmd->args[index] = remchar(cmd->args[index], DOUBLE_QUOTES);
			count = 0;
			while (cmd->args[index][count])
			{
				if (cmd->args[index][count] == DOLLAR_SIGNE)
				{
					tmp = count;
					while (cmd->args[index][count] &&
					cmd->args[index][count] != ' ')
						count++;
					var = get_var(ft_substr(cmd->args[index], tmp + 1,
								count - tmp - 1), export);
					if (!var)
					{
						cmd->args[index] = ft_substr(cmd->args[index], 0, tmp);
						break ;
					}
					tmp_arg = remchar(ft_strjoin(ft_substr
								(cmd->args[index], 0, tmp),
								get_var_value(var)), '\"');
					free(var);
					var = NULL;
					cmd->args[index] = ft_strjoin(tmp_arg, ft_substr
							(cmd->args[index], count,
								ft_strlen(cmd->args[index])));
					free(tmp_arg);
					tmp_arg = NULL;
				}
				count++;
			}
		}
		cmd = cmd->next;
	}
}
