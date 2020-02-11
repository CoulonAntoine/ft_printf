/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:35:53 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/08 18:01:22 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define BIT_0 (1 << 0)
# define BIT_1 (1 << 1) 
# define BIT_2 (1 << 2) 
# define BIT_3 (1 << 3) 
# define BIT_4 (1 << 4) 
# define BIT_5 (1 << 5) 
# define BIT_6 (1 << 6) 
# define BIT_7 (1 << 7)

typedef signed char		t_int8;
typedef unsigned char	t_uint8;
typedef signed short	t_int16;
typedef unsigned short	t_uint16;
typedef signed int		t_int32;
typedef unsigned int	t_uint32;
typedef signed long		t_int64;
typedef unsigned long	t_uint64;

typedef enum	e_bool
{
	FALSE = 0,
	TRUE = !FALSE
}				t_bool;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
** ************ ASCII ******************************************************* **
*/

int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
t_bool			ft_isset(char c, char *set);

/*
** ************ MEMORY ****************************************************** **
*/

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);

/*
** ************ STRING ****************************************************** **
*/

size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strcat(char *dest, const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *h, const char *n, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strndup(char const *str, int len);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
size_t			ft_strinc(char c, char const *str);

/*
** ************ FILES ******************************************************* **
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** ************ LINKED LISTS ************************************************ **
*/

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));

#endif
