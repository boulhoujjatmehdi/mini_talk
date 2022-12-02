/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:04:36 by eboulhou          #+#    #+#             */
/*   Updated: 2022/12/01 13:43:45 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	ft_power_of_2(int pow)
{
	int	ret;

	ret = 1;
	while (pow--)
		ret *= 2;
	return (ret);
}

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

int	ft_bitoa(char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (i < 8)
	{
		if (str[7 - i] == '1')
			nb += ft_power_of_2(i);
		i++;
	}
	return (nb);
}

void	signal_user(int sig, siginfo_t *info, void *vd)
{
	char		str[9];
	static int	i = 0;
	int			c;

	vd = NULL;
	str[i] = sig % 10 + 48;
	if (i == 7)
	{
		str[8] = 0;
		c = ft_bitoa (str);
		write (1, &c, 1);
		i = -1;
		kill(info->si_pid, SIGUSR1);
	}
	i++;
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
