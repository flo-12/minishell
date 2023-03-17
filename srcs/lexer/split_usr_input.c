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

/*
Add a new str to the ptr of str (src_ptr) and return the
new ptr of str (dst_str). dst_str has NULL at the end.
The new str are the first length chars of src and it has
to be NULL-terminated.
Free src_ptr and return NULL in case of error.
*/
char	**add_str(char **src_ptr, char *src, int length)
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
	dst_ptr[size_ptr] = (char *)ft_calloc(sizeof(char), length + 1);
	if (!dst_ptr[size_ptr])
	{
		free_ptr(dst_ptr);
		return (NULL);
	}
	ft_strlcpy(dst_ptr[size_ptr], src, length + 1);
	return (dst_ptr);
}

/*
Checks if char cmp is equal to the char del (=> true)
or if it's not equal (=> false)
	* del=quotes (single or double): compare cmp and del
	* del=space: compare to space and single/double quotes
*/
_Bool	del_found(char cmp, char del)
{
	if ((del == '\"' || del == '\''))
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

/*
Finds and returns the index where the dst-string ends.
End of dst-string refers to the type of delimiter found
in *str, differentiating the following types:
	1) space: find the next space and the consecutive 
			spaces. Excpetion if signle or double quote
			is found. In that case index is the last char
			before the quote.
	2) single quote: find the next signle quote (surpress
			space and double quotes)
	3) double quote: find the next double quote (surpress
			space and single quotes)
Exception: end of str is reached without finding the del
	-> for space: returned index points at the last char
		of the string.
	-> for quotes: return -2 to indicate error
Precondition:
	* the str starts with the del (for quotes) or a char
		(for space)
Return: index pointing at last char of the dst-string
*/
int	find_dstsize(char *str)
{
	int		i;
	char	del;

	del = ' ';
	if (*str == '\'')
		del = '\'';
	else if (*str == '\"')
		del = '\"';
	i = 0;
	while (str[++i])
	{
		if (del_found(*(str + i), del))
		{
			if (del == ' ' && str[i] == ' ')
				return (i + get_nbr_spaces(str + i + 1));	// check that!!!!
			else if (del == ' ')
				return (i - 1);
			else
				return (i);
		}
	}
	if (del != ' ')
		return (-2);
	else
		return (i - 1);
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
Return: pointer to the split strings
Errors: memory allocation fails or quotes are not closed
	-> function returns NULL in this case
Precondition:
	* the usr_input-str doesn't start with a space
*/
char	**split_usr_input(char *usr_input)
{
	int		quote;
	char	**usr_split;
	int		dstsize;
	int		spaces;

	spaces = 0;
	usr_split = NULL;
	quote = 0;
	while (*usr_input)
	{
		dstsize = find_dstsize(usr_input) + 1;
printf("usr_input=%s, dstsize=%d\n", usr_input, dstsize);
		if ((*usr_input == '\'' || *usr_input == '\"')
			&& dstsize == -1)
		{
			free_ptr(usr_split);
			return (NULL);
		}
		usr_split = add_str(usr_split, usr_input, dstsize);
		if (!usr_split)
			return (NULL);
		usr_input += dstsize;
	}
	return (usr_split);
}
