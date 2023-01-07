/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:32:25 by ysoroko           #+#    #+#             */
/*   Updated: 2023/01/03 20:49:50 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>

typedef struct s_flags{
	int		dot;
	bool	sharp;
	bool	add;
	bool	minus;
	bool	space;
	bool	zero;
	int		width;
	int		prec;
	char	type;
}	t_flags;

//ft_printf_utils_1.c
int		char_in_str(char c, char const *s);
int		len_number(long n, int len_base);
int		ulen_number(unsigned long n, int len_base);

//ft_printf_utils_2.c
int		putdigit(char *s, t_flags flags, char c, int len);

//ft_printf_utils_3.c
t_flags	read_flags(char *s, va_list ap);

// functions
char	*ft_itoa(long n);
int		ft_atoi(const char *str);
void	*ft_memset(void *str, int c, size_t n);
int		ft_printf(char const *format, ...);
int		ft_putstr(char *s);
int		ft_putstr_bonus(char *s, t_flags flags);
int		ft_putchar(char c);
int		ft_putchar_bonus(char c, t_flags flags);
int		ft_putdigit(long n, t_flags flags);
int		ft_puthex(unsigned int nb, t_flags flags);
int		ft_putpointer(void *pointer, t_flags flags);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_power(int nb, int power);
int		ft_putunsigned(unsigned long n, t_flags flags);
char	*ft_uitoa(unsigned long n);
#endif