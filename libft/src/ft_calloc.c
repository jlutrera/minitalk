/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:11:43 by jutrera-          #+#    #+#             */
/*   Updated: 2022/09/27 18:34:37 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && SIZE_MAX / size < count)
		return (0);
	p = malloc (count * size);
	if (!p)
		return (0);
	ft_memset(p, 0, size * count);
	return (p);
}
