/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:04:36 by eboulhou          #+#    #+#             */
/*   Updated: 2022/12/08 19:44:26 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

struct s_idx_arr	g_sa;

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
	int			c;

	g_sa.str[g_sa.i] = sig % 10 + 48;
	if (g_sa.i == 6)
	{
		g_sa.str[7] = 0;
		c = ft_bitoa (g_sa.str);
		write (1, &c, 1);
		g_sa.i = -1;
	}
	g_sa.i++;
}

int	main(void)
{
	int					pid;

	pid = getpid();
	ft_putnbr(pid);
	signal (SIGUSR1, signal_user);
	signal (SIGUSR2, signal_user);
	while (1)
	{	
		pause();
	}
	return (0);
}
