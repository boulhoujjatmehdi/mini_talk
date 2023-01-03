/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:24:55 by eboulhou          #+#    #+#             */
/*   Updated: 2023/01/03 18:24:47 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int			g_counter;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	response(int sig)
{
	(void)sig;
	write(1, "delivered with sucess.\n", 24);
}

void	send_sig(int sig, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (i <= ft_strlen(str))
	{
		j = 7;
		while (j >= 0)
		{
			usleep(60);
			if (str[i] & (1 << j))
				kill(sig, SIGUSR2);
			else
				kill(sig, SIGUSR1);
			usleep(100);
			j--;
			signal(SIGUSR1, &response);
		}
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 11)))
			i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb);
}

int	main(int ac, char *argv[])
{
	if (ac == 3)
	{
		send_sig(ft_atoi (argv[1]), argv[2]);
	}
	return (0);
}
