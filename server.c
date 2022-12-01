/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:04:36 by eboulhou          #+#    #+#             */
/*   Updated: 2022/11/30 14:40:08 by eboulhou         ###   ########.fr       */
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
	while (i < 7)
	{
		if (str[6 - i] == '1')
			nb += ft_power_of_2(i);
		i++;
	}
	return (nb);
}

void	signal_user(int sig)
{
	char		str[8];
	static int	i = 0;
	int			c;

	str[i] = sig % 10 + 48;
	if (i == 6)
	{
		str[7] = 0;
		c = ft_bitoa (str);
		write (1, &c, 1);
		i = -1;
	}
	i++;
}

int	main(void)
{
	int	pid;
	struct sigaction action;

	pid = getpid();
	ft_putnbr(pid);
	while (1)
	{
		action.sa_handler = &signal_user;
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
