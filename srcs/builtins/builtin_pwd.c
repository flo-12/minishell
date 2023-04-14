/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:34:09 by fbecht            #+#    #+#             */
/*   Updated: 2023/04/14 17:34:12 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include "../../includes/minishell_flo.h"

int	builtin_pwd(t_data *data)
{
	printf("%s\n", data->working_dir);
	return (EXIT_SUCCESS);
}
