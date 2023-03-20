/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:05:06 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/20 18:06:32 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_pipe(t_command **cmd, t_token **token_lst)
{
	t_command	*last_cmd;

	last_cmd = cmd_lst_get_end(*cmd);
	last_cmd->pipe_output = true;
	cmd_lst_add_end(&last_cmd, cmd_lst_new(false));
	*token_lst = (*token_lst)->next;
}