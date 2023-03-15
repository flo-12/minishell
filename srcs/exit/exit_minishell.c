/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:42:35 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/14 19:16:07 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(t_data *data, int exno)
{
	if (data)
	{
/* 		if (data->cmd && data->cmd->io_fds)
			close_fds(data->cmd, true); */
		free_data(data, true);
	}
	exit(exno);
}