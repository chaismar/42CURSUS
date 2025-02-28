/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:35:36 by lmarchai          #+#    #+#             */
/*   Updated: 2023/11/16 17:01:52 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_louis.h"

void	print_warning(const char *limiter)
{
	ft_dprintf(2, "aristoshell: warning: here-document");
	ft_dprintf(2, \
	"at line 1 delimited by end-of-file (wanted `%s')\n", limiter);
}

void	exp_err(void)
{
	ft_dprintf(2, "minishell: export: write error: ");
	ft_dprintf(2, "No space left on device\n");
}

char	*join_lign_env(t_envlist *list)
{
	size_t		i;
	size_t		j;
	char		*ret;

	ret = malloc(sizeof(char) * ft_strlen(list->key) \
		+ ft_strlen(list->val) + 2);
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(list->key))
	{
		ret[i] = list->key[i];
		i++;
	}
	ret[i] = '=';
	i++;
	while (j < ft_strlen(list->val))
	{
		ret[i + j] = list->val[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

int	ft_envlstsize(t_envlist *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (lst->flag == MASK_ENV)
			i++;
		lst = lst->next;
	}
	return (i);
}

int	strlen_list(t_cmd **cmd)
{
	int	i;

	i = 0;
	if (!cmd || !*cmd)
		return (-1);
	while (cmd[i])
		i++;
	return (i);
}
