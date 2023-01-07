/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:55:50 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 18:55:50 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	trush(char c, t_flags flags)
{
	if (c == '0' && (flags.sharp || flags.type == 'p'))
		return (1);
	return (0);
}

int	zeros(t_flags flags, char c, int len)
{
	int	zeros;
	int	i;

	if (flags.zero && (flags.prec == -1))
		flags.zero = true;
	else
		flags.zero = false;
	if (flags.prec < len)
		flags.prec = len;
	if (flags.width < len)
		flags.width = len;
	if (flags.zero)
	{
		zeros = flags.width - len - (c != 0) - trush(c, flags);
		zeros *= (zeros >= 0);
	}	
	else
		zeros = flags.prec - len;
	i = 0;
	while (zeros--)
		i += ft_putchar('0');
	return (i);
}

int	spaces(t_flags flags, char c, int len)
{
	int	spaces;
	int	i;

	if (flags.zero && (flags.prec == -1))
		flags.zero = true;
	else
		flags.zero = false;
	if (flags.prec < len)
		flags.prec = len;
	if (flags.width < len)
		flags.width = len;
	if (flags.zero)
		spaces = 0;
	else
	{
		spaces = flags.width - flags.prec - (c != 0) - trush(c, flags);
		spaces *= (spaces >= 0);
	}
	i = 0;
	while (spaces--)
		i += ft_putchar(' ');
	return (i);
}

int	prefix_0x(char *s, t_flags flags)
{
	if ((flags.type == 'x' || flags.type == 'X')
		&& flags.sharp && *s != '\0' && *s != '0')
		return (ft_putchar(flags.type));
	if (flags.type == 'p')
		return (ft_putchar('x'));
	return (0);
}

int	putdigit(char *s, t_flags flags, char c, int len)
{
	int	i;

	i = 0;
	if (flags.minus)
	{
		if (c)
			i += ft_putchar(c);
		i += prefix_0x(s, flags);
		i += zeros(flags, c, len);
		i += ft_putstr(s);
		i += spaces(flags, c, len);
	}
	else
	{		
		i += spaces(flags, c, len);
		if (c)
			i += ft_putchar(c);
		i += prefix_0x(s, flags);
		i += zeros(flags, c, len);
		i += ft_putstr(s);
	}
	return (i);
}
