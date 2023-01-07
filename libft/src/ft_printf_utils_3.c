/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:56:00 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 18:56:00 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	read_width(char *s, va_list ap, int n)
{
	int	i;
	int	w;

	if (n == -1)
	{
		n = 0;
		while (char_in_str(s[n], "cspdiuxX%\0") == -1)
			n++;
	}
	i = 0;
	while (char_in_str(s[i], "#+-0 ") != -1 && i < n)
		i++;
	if (s[i] == '*' && i < n)
		return (va_arg(ap, int));
	if (char_in_str(s[i], "cspdiuxX%\0") == -1)
	{
		w = 0;
		while (i < n)
			w = w * 10 + (s[i++] - '0');
		return (w);
	}
	return (-1);
}

int	read_precision(char *s, va_list ap, int n)
{
	int	i;
	int	w;

	if (n == -1)
		return (-1);
	i = ++n;
	if (s[i] == '*')
		return (va_arg(ap, int));
	w = 0;
	while (char_in_str(s[i], "cspdiuxX%\0") == -1)
		w = w * 10 + (s[i++] - '0');
	return (w);
}

bool	read_zero(char *s)
{
	int	i;

	i = 0;
	while (char_in_str(s[i], "+-# \0") != -1)
		i++;
	return (s[i] == '0');
}

t_flags	read_flags(char *s, va_list ap)
{
	int		i;
	t_flags	f;

	i = 0;
	while (s[i] != '\0')
		i++;
	f.type = s[--i];
	f.dot = char_in_str('.', s);
	f.sharp = (char_in_str('#', s) != -1);
	f.add = (char_in_str('+', s) != -1);
	f.minus = (char_in_str('-', s) != -1);
	f.space = (char_in_str(' ', s) != -1);
	f.zero = read_zero(s);
	f.prec = read_precision(s, ap, f.dot);
	f.width = read_width(s, ap, f.dot);
	return (f);
}
