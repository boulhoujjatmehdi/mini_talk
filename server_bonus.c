/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:04:36 by eboulhou          #+#    #+#             */
/*   Updated: 2023/01/03 18:21:47 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

t_idx	g_;

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

int	fill_buff(void *vd)
{
	(void)vd;
	if (g_.i == 8)
	{		
		if (g_.c >> 6 == 3)
			g_.size = 2;
		if (g_.c >> 5 == 7)
			g_.size = 3;
		if (g_.c >> 4 == 15)
			g_.size = 4;
		g_.strr[g_.j] = g_.c;
		g_.strr[g_.j + 1] = 0;
		g_.i = 0;
		g_.j++;
		g_.c = 0;
		if (g_.j == g_.size)
		{
			write(1, g_.strr, g_.size);
			if (g_.strr[0] == 0)
				kill(g_.last, SIGUSR1);
			g_.size = 1;
			g_.j = 0;
		}
	}
	return (0);
}

void	signal_user(int sig, siginfo_t *info, void *vd)
{
	if (g_.last != info->si_pid)
	{
		g_.i = 0;
		g_.size = 1;
		g_.strr[0] = 0;
		g_.j = 0;
		g_.c = 0;
	}
	g_.last = info->si_pid;
	if (sig == SIGUSR2)
		g_.c |= 1;
	g_.i++;
	fill_buff(vd);
	g_.c <<= 1;
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	action.sa_sigaction = &signal_user;
	pid = getpid();
	ft_putnbr(pid);
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
