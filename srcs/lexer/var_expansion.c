/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:41:37 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/15 12:41:39 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"

#include "../../includes/minishell_flo.h"

/*
Checks if the char c is a valid character of a variable
Return: true, if c is valid; false, if c is not valid
*/
_Bool	char_is_var(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	else
		return (false);
}

/*
Checks if the variable starting at str[start] and ending
at str[end] is found in env
Return:
	- found: return true
		exception: variable in env doesn't have a value
			(env ends after =-sign)
			return false in that case
	- not found: return false
*/
_Bool	var_is_equal(char *str, char *env, int start, int end)
{
	int	i;

	i = 0;
	while (start < end && env[i] == str[start] && env[i])
	{
		i++;
		start++;
	}
	if (env[i] == '\0')
		return (false);
	if (env[i + 1] == '=' && start == end && env[i] == str[start])
		return (true);
	return (false);
}

/*
Replaces the variable from str[(start + 1):end] with the value
in env, which starts after the first equal-sign ('='). Also removes
the $-sign at str[start].
Returns the new string and frees the old str.
Also sets the new start, which is after the added variable value.
*/
char	*replace_var(char *str, int *start, int end, char *env)
{
	char	*tmp;

	if (*env)
	{
		while (*env != '=' && *env)
			env++;
		env++;
	}
	tmp = (char *)ft_calloc(sizeof(char), (*start + ft_strlen(env)
				+ ft_strlen(str + end + 1) + 1));
	if (!tmp)
	{
		free(str);
		return (NULL);
	}
	ft_strlcat(tmp, str, *start + 1);
	ft_strlcat(tmp, env, *start + ft_strlen(env) + 1);
	ft_strlcat(tmp, str + end + 1, *start + ft_strlen(env)
		+ ft_strlen(str + end + 1) + 1);
	free(str);
	*start += ft_strlen(env);
	return (tmp);
}

/*
Searches the variable in str in env and replaces it
by it's value in env. If variable is not found, the
var-name (inlcuding $-sign) is deleted in str.
VAR-NAME: vairable starts with a $-sign (excluded)
	and is seperated by a space, the end of the string
	or a double quote (if str starts with double quotes)
Return:
	- str with replaces variable
	- i (as pointer), which points at the next char
		after the replaced variable (especially 
		important if var is not found, because
		i_new <= i_old in that case)
Precondition: str[i]=='$' -> i marks the start of
	the variable
*/
char	*search_and_replace_var(char *str, int *i, char **env)
{
	int		j;
	int		i_env;

	j = *i + 1;
	while (char_is_var(str[j]))
		j++;
	if (!env)
		return (replace_var(str, i, j - 1, ""));
	while (*env)
	{
		if (var_is_equal(str, *env, *i + 1, j - 1))
		{
			return (replace_var(str, i, j - 1, *env));
		}
		env++;
	}
	return (replace_var(str, i, j - 1, ""));
}

/*
Parses through each string in usr_split and replaces
variables with its values.
	variable: $<VAR_NAME>
Variables are only allowed from env. If the variable
is not found, starting from the $-sign, var-name will
be deleted. If the string is empty afterwards, it is
freed and the pointer removed.
$-signs in singles quotes ('') are ignored.
Precondition: usr_split is not NULL
*/
void	var_expansion(char **usr_split, char **env)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	while (*usr_split)
	{
		i = 0;
		while ((*usr_split)[i] && **usr_split != '\'')
		{
			if ((*usr_split)[i] == '$' && char_is_var((*usr_split)[i + 1]))
			{
				tmp = search_and_replace_var(*usr_split, &i, env);
				if (!(*usr_split))
				{
					free_ptr(usr_split);
					return ;
				}
				*usr_split = tmp;
				tmp = NULL;
			}
			else
				i++;
		}
		usr_split++;
	}
}
