/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwon <mkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:16:59 by mkwon             #+#    #+#             */
/*   Updated: 2023/01/13 16:17:00 by mkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_exit_code;

int	input_exit(t_tree *tree)
{
	t_token	*token;

	token = tree->root->left_child->token;
	if (ft_strncmp(token->str, "exit", 5) == 0)
	{
		if (token->next != NULL)
		{
			if (token->next->str[0] != '-' && \
			(token->next->str[0] < '0' || token->next->str[0] > '9'))
			{
				write(1, "exit\n", 5);
				printf("meowshell: exit: %s: numeric argument required\n", \
				token->next->str);
				g_exit_code = 255;
				exit (255);
			}
			else
				g_exit_code = ft_atoi(token->next->str);
		}
		return (1);
	}
	return (0);
}

void	prt_exit(void)
{
	write(2, "exit\n", 5);
	exit(g_exit_code);
}
