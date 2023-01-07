/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:38:57 by jutrera-          #+#    #+#             */
/*   Updated: 2022/10/03 23:38:57 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_uitoa(unsigned long n)
{
	char			*nb;
	int				len;

	len = ulen_number(n, 10);
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (0);
	if (n == 0)
		nb[0] = '0';
	nb[len] = '\0';
	while (n > 0)
	{
		nb[--len] = n % 10 + '0';
		n /= 10;
	}
	return (nb);
}
