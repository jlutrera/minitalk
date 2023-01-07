/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:55:32 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 18:55:32 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	char_in_str(char c, char const *s)
{
	int	n;

	n = 0;
	while (s[n] != c && s[n] != '\0')
		n++;
	if (s[n] == '\0')
		return (-1);
	return (n);
}

int	len_number(long n, int len_base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= len_base;
		i++;
	}
	return (i);
}

int	ulen_number(unsigned long n, int len_base)
{
	int	i;

	i = 1;
	while (n > (unsigned long)len_base - 1)
	{
		n /= len_base;
		i++;
	}
	return (i);
}
