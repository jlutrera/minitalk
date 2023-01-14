/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:09:03 by jutrera-          #+#    #+#             */
/*   Updated: 2023/01/06 17:09:03 by jutrera-         ###   ########.fr       */
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
	while (++i <  __CHAR_BIT__ * sizeof(int))
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(WAIT_TIME);
	}
}

void	sig_usr(int sig)
{
	static int	i = 0;

	if (sig == SIGUSR1)
		i++;
	else if (sig == SIGUSR2)
	{
		ft_printf("%sServer says: ", KYEL);
		ft_printf("%sMessage received !%s (%i bits)\n", KGRN, KNRM, i);
		i = 0;
		exit(EXIT_SUCCESS);
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
	signal(SIGUSR1, &sig_usr);
	signal(SIGUSR2, &sig_usr);
	ft_send_len(len, pid);
	while (str[++i])
		ft_send_char(str[i], pid);
	ft_send_char(str[i], pid);
	while (1)
		pause();
}
