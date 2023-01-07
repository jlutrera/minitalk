/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:39:35 by ysoroko           #+#    #+#             */
/*   Updated: 2023/01/06 12:34:14 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	ft_receive_len(char **str, int signal)
{
	static int	len = 0;
	static int	bit = 0;
	const int	bits = __CHAR_BIT__ * sizeof(int);

	if (signal == SIGUSR2)
		len += ft_power(2, bit);
	if (++bit == bits)
	{
		*str = ft_calloc(len + 1, sizeof(char));
		if (!*str)
			exit (EXIT_FAILURE);
		bit = 0;
		len = 0;
		return (1);
	}
	return (0);
}

static int	ft_process(char **str, int c)
{
	static int	i = 0;

	(*str)[i] = c;
	i++;
	if (c == 0)
	{
		ft_printf("%sClient says:%s %s%s\n", KYEL, KGRN, *str, KNRM);
		free(*str);
		i = 0;
		return (0);
	}
	return (1);
}

static void	ft_receiving(int signal)
{
	static int	c = 0;
	static int	bit = 0;
	static int	received = 0;
	static char	*str = 0;
	const int	bits = __CHAR_BIT__ * sizeof(char);

	if (!received)
		received = ft_receive_len(&str, signal);
	else
	{
		if (signal == SIGUSR2)
			c += ft_power(2, bit);
		if (++bit == bits)
		{
			received = ft_process(&str, c);
			c = 0;
			bit = 0;
		}
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID = %s%i%s\n", KYEL, pid, KNRM);
	signal(SIGUSR1, ft_receiving);
	signal(SIGUSR2, ft_receiving);
	while (1)
		sleep(1);
}

// [SIGUSR1] defines the '0' bit && [SIGUSR2] defines the '1' bit