

void	*expand_exit_code(char **args)
{
	char	*str;
	
	while (*args)
		if (*args contains "$?")
			str = *args replaced with exit code (malloced)
			free(*args)
			*args = str
		args++
}
