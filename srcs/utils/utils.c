/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:57:11 by fbecht            #+#    #+#             */
/*   Updated: 2023/05/03 19:46:39 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//#include "../../includes/minishell_flo.h"

/*
get the number of strings in a ptr to strings
*/
int	get_size_ptr(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (i);
	while (ptr[i])
		i++;
	return (i);
}

/*
copy each str-ptr of a ptr to an other ptr
*/
void	cpy_ptrs(char **dst, char **src)
{
	if (!src)
		return ;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
}

/*
Free each string of a pointer, pointing to several strings
At the end, free the pointer
*/
void	free_ptr(char **ptr)
{
	char	**tmp;

	tmp = ptr;
	if (!ptr)
		return ;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(tmp);
}

/*
* checks for white-space characters
* Return 1 if true and 0 if false
* 	imitates behaviour of isspace (ctype.h)
*/
int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

void	remove_token_spaces(t_token **token)
{
	t_token	*tmp;
	t_token	*del;

	tmp = *token;
	while (tmp->next->type != END)
	{
		if (tmp->type == SPACES && tmp->next->type == SPACES)
		{
			del = tmp->next;
			tmp->next = del->next;
			del->next->prev = tmp;
			token_lstdelone(del);
			tmp = *token;
		}
		else
			tmp = tmp->next;
	}
}
