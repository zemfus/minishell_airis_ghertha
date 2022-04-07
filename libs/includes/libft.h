/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:17:10 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:17:11 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 50
# endif

typedef struct s_node
{
	int				val;
	int				idx;
	int				is_sorted;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*bot;
	t_node			*cur;
	t_node			*top;
}					t_stack;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void				*ft_memset(void *ptr, int value, size_t num);
void				ft_bzero(void *ptr, size_t num);
void				*ft_memcpy(void *dst, const void *src, size_t num);
void				*ft_memccpy(void *dst, void *src, int val, size_t num);
void				*ft_memmove(void *dst, const void *src, size_t num);
void				*ft_memchr(void *ptr, int val, size_t num);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
size_t				ft_strlen(const	char *str);
size_t				ft_strncmp(const char *s1, const char *s2, size_t num);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char	*dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char \
*needle, size_t len);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalnum(int c);
int					ft_isnum(char c);
int					ft_strnum(char *str);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new_lst);
int					ft_lstsize(t_stack *t);
int					get_next_line(int fd, char **line);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *));
char				*ft_uitoa(unsigned int n);
char				*ft_utoa(unsigned long long n, char *base_set);
int					ft_strcmp(char *s1, char *s2);
int					ft_strnrcmp(char *s1, char *s2, int cnt);
long long			ft_atol(char *str);
int					ft_free_double(void	**ptr);
int					ft_free_single(void *ptr);
size_t				ft_double_strlen(const char **str);
int					ft_numlen(char *str);
int					ft_is_allnum(char **str);

#endif
