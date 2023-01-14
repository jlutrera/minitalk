/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:33:40 by ysoroko           #+#    #+#             */
/*   Updated: 2023/01/14 15:55:21 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_send_char(unsigned char c, int pid)
{
	int			i;

	i = -1;
	while (++i < __CHAR_BIT__ * sizeof(char))
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(WAIT_TIME);
	}
}

static void	ft_send_len(int len, int pid)
{
	int			i;

	i = -1;
	while (++i < __CHAR_BIT__ * sizeof(int))
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(WAIT_TIME);
	}
}

void	errors(int e)
{
	ft_printf("%sERROR !%s.  ", KYEL, KNRM);
	if (e == 1)
		ft_printf("Type: ./client [server PID] [string to send]\n");
	else if (e == 2)
		ft_printf("Bad PID number\n");
	else
		ft_printf("Bad server PID\n");
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		len;
	int		i;

	if (argc != 3)
		errors(1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		errors(2);
	if (kill(pid, 0) < 0)
		errors(3);
	str = argv[2];
	len = ft_strlen(str);
	i = -1;
	ft_send_len(len, pid);
	while (str[++i])
		ft_send_char(str[i], pid);
	ft_send_char(str[i], pid);
	return (0);
}
