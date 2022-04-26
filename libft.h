/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:47:05 by ogonzale          #+#    #+#             */
/*   Updated: 2022/04/26 17:57:21 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
** Part 1 - Libc functions
*/

int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *str, const char *to_find, size_t n);
char		*ft_strdup(const char *str);

void		*ft_memset(void *s, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		*ft_calloc(size_t number, size_t size);
int			ft_atoi(const char *nptr);

/*
** Part 2 - Additional functions
*/ 

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);

/*
** Extra functions
*/

int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_isspace(int c);

long double	ft_pow(long double n, unsigned int pow);
#endif
