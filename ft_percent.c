#include "ft_printf.h"

static char	*ft_flag(char *s, t_key *v)
{
	if (*s == '-')
	{
		v->fl = 1;
		s++;
	}
	if (*s == '0' && v->fl == 0)
	{
		v->fl2 = 1;
		s++;
	}
	return (s);
}

static void	ft_width(t_key *v, va_list lst, char *s)
{
	if (0 > (v->diff = ft_printsp((char*)s, lst)))
		{
			v->fl = 1;
			v->fl2 = 0;
			v->diff *= -1;
		}
}

char	*ft_percent(t_key *v, char *s, va_list lst)
{
	s = ft_flag(s, v);
	if (ft_isdigit(*s) || *s == '*')
		ft_width(v, lst, s);
	if (*(s = ft_skipnum((char*)s)) == '.'		
		|| *(s = ft_skipstar((char*)s)) == '.')
	{
		v->diff2 = ft_printdot((char*)++s, lst, v);
		if (v->diff2 > 0)
			v->fl2 = 0;
	}
	if (ft_isconv(s = ft_skipnum((char*)s)) || ft_isconv((char*)++s))
		ft_itisconv(*ft_skipall((char*)s), lst, v);
	else if (ft_isconv((char*)s))
		ft_itisconv(*s, lst, v);
	if (*ft_skipall((char*)s) == 's')
		ft_strprint(v);
	else
		ft_star(v);
	return(s = ft_skipall((char*)s));
}
