#include "ft_printf.h"

void	ft_putstr(const char *str, t_key *v)
{
	int i;

	i = -1;
	if (str)
	{
		while (str[++i])
			ft_putchar(str[i], v);
	}
}

void	ft_putstrlm(const char *str, int lm, t_key *v)
{
	int i;

	i = -1;
	if (str && lm > 0)
	{
		while (str[++i] && lm-- > 0)
			ft_putchar(str[i], v);
	}
}

char	*ft_skipf(char *s)
{
	while(s && ft_isflag(s))
		s++;
	return (s);
}

char	*ft_skipstar(char *s)
{
	if (s && *s == '*')
		s++;
	return (s);
}
char	*ft_skipall(char *s)
{
	if (s)
	{
		while(s && (ft_isdigit(*s) || ft_isflag(s)))
			s++;
		if (s && ft_isconv(s))
			return (s);
		else 
			return (NULL);
	}
	return (NULL);
}