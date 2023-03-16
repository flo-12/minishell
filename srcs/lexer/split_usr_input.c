/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_usr_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:40:11 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/15 12:40:14 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"

#include "../../includes/minishell_flo.h"

int	nbr_quotes(char *str, char quote)
{
	int	n;

	n = 0;
	while (*str)
	{
		if (*str == quote)
			n++;
		str++;
	}
	return (n);
}

char	**add_str(char **src_ptr, char *src, int size)
{
	int		size_ptr;
	char	**dst_ptr;

	size_ptr = get_size_ptr(src_ptr);
	dst_ptr = (char **)ft_calloc(sizeof(char *), size_ptr + 2);
	if (!dst_ptr)
	{
		free_ptr(src_ptr);
		return (NULL);
	}
	cpy_ptrs(dst_ptr, src_ptr);
	free(src_ptr);
	dst_ptr[size_ptr] = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst_ptr[size_ptr])
	{
		free_ptr(dst_ptr);
		return (NULL);
	}
	ft_strlcpy(dst_ptr[size_ptr], src, size + 1);
	return (dst_ptr);
}

_bool	del_found(char cmp, char del)
{
	if (del == '\"' || del == '\'')
	{
		if (del == cmp)
			return (true);
	}
	else
	{
		if (cmp == ' ' || cmp == '\"' || cmp == '\'')
			return (true);
	}
	return (false);
}

int	find_dstsize(char *str, int *quote)
{
	int		i;
	char	del;

	del = ' ';
	if (*str == '\'')
	{
		del = '\'';
		*quote = 1;
	}
	else if (*str == '\"')
	{
		del = '\"';
		*quote = 2;
	}
	i = 1;
	while (str[i])
	{
		if (del_found(*(str + i), del))
			return (i + get_i_del_spaces(str + i));
		i++;
	}
	if (*quote)
		return (-1);
	else
		return (i);
}

/*
Gets the user input from the prompt as input and splits
it as followed in several strings:
	1) if single quotes ('')
		-> string at start and end of quotes
	2) if double quotes ("")
		-> string at start and end of quotes
	3) if spaces (exception spaces between quotes)
		-> space as seperator of single strings
The function returns the pointer to the strings.
Errors: memory allocation fails or quotes are not closed
	-> function returns NULL in this case
*/
char	**split_usr_input(char *usr_input)
{
	int		quote;
	char	**usr_split;
	int		dstsize;
	int		spaces;

	if (nbr_quotes(usr_input, '\'') % 2 != 0
		|| nbr_quotes(usr_input, '\"') % 2 != 0)
		return (NULL);
	spaces = 0;
	usr_split = NULL;
	quote = 0;
	while (*usr_input)
	{
		dstsize = find_dstsize(usr_input, &quote);
printf("dstsize=%d\n", dstsize);
		if (quote && dstsize < 0)
		{
			free_ptr(usr_split);
			return (NULL);
		}
		else if (quote)
			quote = 0;
		usr_split = add_str(usr_split, usr_input, dstsize);
		if (!usr_split)
			return (NULL);
		usr_input += dstsize;
	}
	return (usr_split);
}
