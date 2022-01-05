/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:17:45 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/05 03:35:28 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	replace_pwd(t_export *export)
{
	char		*var;
	t_export	*tmp;

	tmp = export;
	var = ft_search_in_list(export, "PWD");
	while (tmp)
	{
		if (!ft_memcmp(tmp->variable, "OLDPWD", 6))
			break ;
		tmp = tmp->next;
	}
	if (tmp->variable)
	{
		free(tmp->variable);
		tmp->variable = NULL;
		tmp->variable = ft_strjoin("OLDPWD", ft_substr(var, 3, ft_strlen(var) - 3));
	}
}

char 	*ft_search_in_list(t_export *export , char *name)
{
	t_export	*temp;

	temp = export;
	if (temp == NULL)
		return (NULL);
	while (temp && ft_memcmp(temp->variable, name, ft_strlen(name)))
		temp = temp->next;
	return (temp->variable);
}

void	ft_replace_directory(t_export *export)
{
	char	*buff;
	char	*new_dir;

	buff = NULL;
	new_dir = getcwd(buff, sizeof(buff));
	while (export)
	{
		if (!ft_memcmp(export->variable, "PWD", 3))
			break ;
		export = export->next;
	}
	free(export->variable);
	export->variable = ft_strjoin("PWD=", new_dir);
	free(new_dir);
}

int		ft_cd(t_cmd *cmd, t_export *export)
{
	char	*dir;
	char	*tmp;

	if (!cmd->args[1] || (cmd->args[1][0] == '~' &&  ft_strlen(cmd->args[1]) == 1))
	{
		tmp = ft_search_in_list(export, "HOME");
		if (!tmp)
			ft_putstr_fd("HOME not found\n", 2);
		dir = remchar(&tmp[5], '\"');
	}
	else if (cmd->args[1][0] == '-')
	{
		tmp = ft_search_in_list(export , "OLDPWD");
		if (!tmp)
			ft_putstr_fd("OLDPWD not found\n", 2);
		dir = &tmp[7];
	}
	else
		dir = cmd->args[1];
	if (chdir(dir) == -1)
		perror("cd");
	replace_pwd(export);
	ft_replace_directory(export);
	return (0);
}