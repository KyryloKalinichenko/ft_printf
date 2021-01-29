#include "ft_printf.h"

int	ft_printdot(char *s, va_list a, t_key *v)
{
	int i;
	
	i = -1;
	if (s)
	{
		if (ft_isdigit(*s))
		{
			i = ft_atoi(ft_substr(s, 0, ft_skipnum(s) - s));
			v->fl3 = 1;
			return (i);
		}
		else if(*s == '*')
		{
			v->fl3 = 1;
			return ((int)(va_arg(a, unsigned int)));
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
	if (v->fl)
			{
				if (v->fl3 == 1 && p >= 0)
					ft_putstrlm(v->res, p);
				else 
					ft_putstr(v->res);
				while (w-- > 0)
					ft_putchar(' ');
			}
		else if (!v->fl)
			{
				while (w-- > 0)
					ft_putchar(' ');
				if (v->fl3 == 1 && p >= 0)
					ft_putstrlm(v->res, p);
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
		len = ft_strlen(v->res);
		p = v->diff2;
		w = v->diff;
		if (v->fl3 == 1 && p > 0)
		{
			if (p <= len)
				w -= p;
			else if (len < p)
				w -= len;
		}
		else if (v->fl3 == 0 || p < 0)
				w -= len;
		ft_printres(v, p, w);
	}
}