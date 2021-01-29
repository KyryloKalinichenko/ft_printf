#include "ft_printf.h"

void	ft_load(t_key *v)
{
	if (v)
	{
		v->fl = 0;
		v->fl2 = 0;
		v->diff = 0;
		v->diff2 = 1;
		v->neg = 0;
		v->fl3 = 0;
		v->res = NULL;
	}
}

char	*ft_skipnum(char *s)
{
	int i;

	i = -1;
	if (s)
	{
		while (ft_isdigit(s[++i]))
			;
		return (&s[i]);
	}
	return (NULL);
}

int	ft_printsp(char *s, va_list lst)
{
	char *str;
	int i;
	
	i = 1;
	if (s && ft_isdigit(*s))
	{
		if (!(str = ft_substr(s, 0, (int)(ft_skipnum(s) - s))))
			return (0);
		i = ft_atoi(str);
		free(str);
		return (i);
	}
	else if (*s == '*')
		i = va_arg(lst, int);
	return (i);
}