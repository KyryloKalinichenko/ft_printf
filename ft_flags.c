#include "ft_printf.h"
#include <stdio.h>

int	ft_printdot(char *s, va_list a, t_key *v)
{
	int i;
	char *tmp;
	
	i = -1;
	if (s)
	{
		if (ft_isdigit(*s))
		{
			if (!(tmp = ft_substr(s, 0, ft_skipnum(s) - s)))
				return (0);
			i = ft_atoi(tmp);
			v->fl3 = 1;
			free(tmp);
			return (i);
		}
		else if(*s == '*')
		{
			v->fl3 = 1;
			return ((int)(va_arg(a, int)));
		}
		else if (ft_isconv(s))
		{
			v->fl3 = 1;
			return (0);
		}
	}
	return (i);
}

static void		ft_printres(t_key *v, int p, int w)
{
	//printf("///%i///", w);
	if (v->fl)
			{
				if (v->fl3 == 1 && p >= 0 && v->res)
					ft_putstrlm(v->res, p);
				else if (!v->res && (!v->fl3 ||
									 (p >= 6 || p < 0)))
					ft_putstr("(null)");
				else 
					ft_putstr(v->res);
				while (w-- > 0)
					ft_putchar(' ');
			}
	else if (!v->fl)
			{
				while (w-- > 0)
					ft_putchar(' ');
				if (v->fl3 == 1 && p >= 0 && v->res)
					ft_putstrlm(v->res, p);
				else if (!v->res && (!v->fl3 ||
								 (p >= 6 || p < 0)))
					ft_putstr("(null)");
				else
					ft_putstr(v->res);
			}
}

void	ft_strprint(t_key *v)
{
	int w;
	int p;
	int len;

	if (v)
	{
		if (v->res)
			len = ft_strlen(v->res);
		else
			len = 6;
		p = v->diff2;
		w = v->diff;
		if (v->fl3 == 1 && p > 0)
		{
			if (p <= len && v->res)
				w -= p;
			else if (len < p)
				w -= len;
		}
		else if (v->fl3 == 0 || p < 0)
				w -= len;
		ft_printres(v, p, w);
	}
	//else if (v && !(v->res))
	//	ft_putstr("(null)");
}