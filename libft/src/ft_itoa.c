/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:55:26 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 18:55:26 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_itoa(long n)
{
	char			*nb;
	int				len;
	unsigned long	num;

	len = len_number(n, 10);
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (0);
	if (n == 0)
		nb[0] = '0';
	if (n < 0)
	{
		nb[0] = '-';
		num = -n;
	}
	else
		num = n;
	nb[len] = '\0';
	while (num > 0)
	{
		nb[--len] = num % 10 + '0';
		num /= 10;
	}
	return (nb);
}
