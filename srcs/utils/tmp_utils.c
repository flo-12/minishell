
void	replace_exit_code(char **arg, int i, char *exit_code)
{
	char	*tmp;

	tmp = (char *)ft_calloc(sizeof(char),
			ft_strlen(*arg) - 1 + ft_strlen(exit_code));
	if (!tmp)
		return ;
	ft_strlcat(tmp, *arg, i + 1);
	ft_strlcat(tmp, exit_code, ft_strlen(tmp)
		+ ft_strlen(exit_code) + 1);
	ft_strlcat(tmp, (*arg) + i + 2, ft_strlen(tmp)
		+ ft_strlen((*arg) + i + 2) + 1);
	free(*arg);
	*arg = tmp;
}

void	expand_exit_code(char **args)
{
	int		i;
	char	*exit_code;

	if (!args)
		return ;
	exit_code = ft_itoa((unsigned char)last_exit_code);
	if (!exit_code)
		return ;
	while (*args)
	{
		i = -1;
		while ((*args)[++i])
		{
			if ((*args)[i] == '$' && (*args)[i + 1] == '?')
				replace_exit_code(&(*args), i, exit_code);
		}
		args++;
	}
	free(exit_code);
}