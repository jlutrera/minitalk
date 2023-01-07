/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:09:09 by jutrera-          #+#    #+#             */
/*   Updated: 2023/01/06 17:09:09 by jutrera-         ###   ########.fr       */
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

static int	ft_process(char **str, int *c, int *bit)
{
	static int	i = 0;

	(*str)[i] = *c;
	i++;
	*bit = 0;
	if (*c == 0)
	{
		ft_printf("%sClient says:%s %s%s\n", KYEL, KGRN, *str, KNRM);
		free(*str);
		i = 0;
		return (0);
	}
	*c = 0;
	return (1);
}

static void	ft_receiving(int signal, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	bit = 0;
	static int	received = 0;
	static char	*str = 0;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
	{
		ft_printf("%sERROR !%s. Can't send to client\n ", KYEL, KNRM);
		exit (EXIT_FAILURE);
	}
	if (!received)
		received = ft_receive_len(&str, signal);
	else
	{
		kill(info->si_pid, SIGUSR1);
		if (signal == SIGUSR2)
			c += ft_power(2, bit);
		if (++bit == __CHAR_BIT__ * sizeof(char))
		{
			received = ft_process(&str, &c, &bit);
			if (received == 0)
				kill(info->si_pid, SIGUSR2);
		}
	}
}

void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	susr;

	susr.sa_sigaction = handler;
	susr.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&susr.sa_mask);
	if (sig == SIGUSR1)
		sigaction(SIGUSR1, &susr, 0);
	else if (sig == SIGUSR2)
		sigaction(SIGUSR2, &susr, 0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID = %s%i%s\n", KYEL, pid, KNRM);
	init_sig(SIGUSR1, &ft_receiving);
	init_sig(SIGUSR2, &ft_receiving);
	while (1)
		sleep(1);
}

// [SIGUSR1] defines the '0' bit
// [SIGUSR2] defines the '1' bit