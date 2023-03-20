/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:41:03 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/25 12:21:47 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	action(int sig)
{
	(void)sig;
	write(1, "Data has been successfully received\n", 36);
}

void	final_word(int pid)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (0 >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

void	convert_bits(char *str, int pid)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 8;
		while (bit--)
		{
			if (str[i] >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
		}
		i++;
	}
	final_word(pid);
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_putstr_fd("Invalid number of arguments\n", 1);
		return (0);
	}
	ft_putstr_fd("my process id is: ", 1);
	ft_putstr_fd(ft_itoa(pid), 1);
	ft_putstr_fd("\n", 1);
	if (argc != 3 || !ft_strlen(argv[2]))
		return (0);
	signal(SIGUSR1, action);
	convert_bits(argv[2], pid);
	return (0);
}
