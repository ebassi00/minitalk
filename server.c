/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:41:05 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/25 12:16:18 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"

void	process_sig(int sig, siginfo_t *info, void *context)
{
	static int	uchar = 0;
	static char	c = 0;

	(void)context;
	c |= (sig == SIGUSR1);
	if (++uchar == 8)
	{
		if (!c)
			kill(info->si_pid, SIGUSR1);
		else
			ft_putchar_fd(c, 1);
		uchar = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	pid_t				my_pid;
	struct sigaction	act;

	my_pid = getpid();
	act.sa_sigaction = &process_sig;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	ft_putstr_fd("my process id is: ", 1);
	ft_putstr_fd(ft_itoa(my_pid), 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
