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


typedef struct		s_key
{
	char			*res;
	int			fl;
	int			fl2;
	int			fl3;
	int			diff;
	int			diff2;
	int			neg;
	char		a;
	int			zerch;
	int			plus;
	int			space;
	int			hash;
	int			sh;

}					t_key;

void				*ft_memset(void *dest, int val, size_t len);
void				ft_bzero(void *to, size_t count);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *source, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *source);
char				*ft_strncpy(char *dest, const char *source, size_t len);
char				*ft_strcat(char *dest, const char *source);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *htk, const char *ndl, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s, char const *set);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long int n, int base);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putstrlm(char const *s, int lm);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(const char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_calloc(size_t nmemb, size_t size);
char				**ft_split(char const *s, char c);
int					ft_tolower(int c);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstclear(t_list **lst, void (*del)(void*));

void				ft_lstdelone(t_list *alst, void (*del)(void *));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));
int				ft_lstsize(t_list *lst);
int				ft_printsp(char *s, va_list lst);
char    			*ft_skipnum(char *s);
int				ft_printf(const char *s, ...);
void				ft_rjustify(t_key *v, int k, int p);
void				ft_ljustify(t_key *v, int k, int p);
void				ft_itisconv(char a, va_list lst, t_key *v);
int				ft_isconv(const char *b);
void				ft_star(t_key *v);
int				ft_printdot(char *s, va_list a, t_key *v);
char				*ft_skipall(char *s);
void				ft_strprint(t_key *v);
void				ft_load(t_key *v);
char				*ft_percent(t_key *v, char *s, va_list lst);
char				*ft_skipstar(char *s);
void				ft_putstr(const char *str);
int					ft_isflag(char *s);
void				ft_print_ptr(long int addr, char a, t_key *v);
#endif
