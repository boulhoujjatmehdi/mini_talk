/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:04:36 by eboulhou          #+#    #+#             */
/*   Updated: 2023/01/02 18:57:16 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

struct s_idx_arr	g_sa;

void	ft_putnbr(int c)
{
	int	put;

	if (c > 9)
	{
		ft_putnbr(c / 10);
	}
	put = c % 10 + 48;
	write (1, &put, 1);
}

void	signal_user(int sig, siginfo_t *info, void *vd)
{
	(void)vd;
	if (g_sa.last != info->si_pid)
	{
		g_sa.i = 0;
		g_sa.str = 0;
	}
	g_sa.str |= sig % 10;
	if (g_sa.i == 7)
	{
		write (1, &g_sa.str, 1);
		g_sa.i = -1;
		g_sa.str = 0;
	}
	g_sa.str <<= 1;
	g_sa.i++;
	g_sa.last = info->si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	action.sa_sigaction = &signal_user;
	action.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
