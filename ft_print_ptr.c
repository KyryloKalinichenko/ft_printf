#include "ft_printf.h"

static void     ft_p(t_key *v, long int addr)
{
    char *tmp;

    v->res = "0x";
	if (!(v->res = ft_strjoin(v->res, tmp = ft_itoa(addr, 16))))
        return ;
	free(tmp);
	if (ft_strcmp(v->res, "0x0") == 0)
		{
			free (v->res);
			if (!(v->res = ft_strdup("(nil)")))
                return ;
		}
}

static void    ft_reg(char a, char *s)
{
    int i;

    i = 0;
    while (s[i])
	{
		if (a == 'X' && ft_isalpha(s[i]))
			s[i] = ft_toupper(s[i]);
		else if (a == 'x' && ft_isalpha(s[i]))
			s[i] = ft_tolower(s[i]);
		i++;
    }
}

void    ft_print_ptr(long int addr, char a, t_key *v)
{
	char *s;
	const long int MAX = 4294967296;

	if (addr < 0)
		addr += MAX;
	if (a == 'p')
        ft_p(v, addr);
	else if (a == 'u')
        {
		    if (!(v->res = ft_itoa((long int)addr, 10)))
                return ;
        }
	else if (a == 'X' || a == 'x')
	{
		if ((s = ft_itoa((long int)addr, 16)))
            ft_reg(a, s);
		v->res = s;
	}
}