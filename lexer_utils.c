
#include "minishell.h"

int	get_type(char *line)
{
	if (*line == '<' && *(line + 1) == '<')
		return (HERE);
	if (*line == '>' && *(line + 1) == '>')
		return (REDI);
	if (*line == '<')
		return (REDI);
	if (*line == '>')
		return (REDI);
	if (*line == '|')
		return (PIPE);
	if (*line == '\"')
		return (DOUBLE_QUOTES);
	if (*line == '\'')
		return (SINGLE_QUOTES);
	return (WORD);
}

char	*str_one_join(char *s1, char c)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = 0;
	free(s1);
	return (str);
}

char	*re_str(char *str)
{
	free(str);
	str = malloc(1);
	str[0] = 0;
	return (str);
}

void	set_variable(t_tree *tree, int space, int pipe, int quote)
{
	tree->space = space;
	tree->pipe = pipe;
	tree->double_quote = quote;
	tree->single_quote = quote;
}