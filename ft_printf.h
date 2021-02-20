/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:03:17 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/11 14:55:31 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_key
{
	char	*res;
	int	ljus;
	int	zero;
	int	perc_f;
	int	width;
	int	perc_q;
	int	neg;
	char	a;
	char	b;
	int	zerch;
	int	plus;
	int	space;
	int	hash;
	int	sh;
	int	ctr;

}				t_key;

void			ft_bzero(void *to, size_t count);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, const char *source);
char			*ft_strncpy(char *dest, const char *source, size_t len);
char			*ft_strcat(char *dest, const char *source);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(long int n, int base);
void			ft_putchar(char c, t_key *v);
void			ft_putstr(char const *s, t_key *v);
void			ft_putstrlm(char const *s, int lm, t_key *v);
void			ft_putnbr(int n);
int			ft_atoi(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
int			ft_tolower(int c);
char			*ft_printsp(char *s, va_list lst, t_key *v);
char			*ft_skipnum(char *s);
int			ft_printf(const char *s, ...);
void			ft_rjustify(t_key *v, int k, int p);
void			ft_ljustify(t_key *v, int k, int p);
void			ft_itisconv(char a, va_list lst, t_key *v);
int			ft_isconv(const char *b);
void			ft_printnum(t_key *v);
char			*ft_printdot(char *s, va_list a, t_key *v);
char			*ft_skipall(char *s);
void			ft_strprint(t_key *v);
void			ft_load(t_key *v);
char			*ft_percent(t_key *v, char *s, va_list lst);
char			*ft_skipstar(char *s);
int			ft_isflag(char *s);
void			ft_print_ptr(unsigned long long int addr, char a, t_key *v);
char			*ft_itoa_float(float n);
char			*ft_itoa_max(unsigned long long int n, int base);

#endif
