/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:24:55 by eboulhou          #+#    #+#             */
/*   Updated: 2022/12/02 10:04:21 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int			g_counter;

static char	*ft_atobi(unsigned char c)
{
	char	*bin;
	int		i;
	int		len;

	bin = malloc(9);
	len = 8;
	while (len--)
	{
		bin[len] = '0';
	}
	i = 0;
	while (c >= 1)
	{
		bin[7 - i] = c % 2 + '0';
		c = c / 2;
		i++;
	}
	bin[8] = 0;
	return (bin);
}

void	hand(int sig)
{
	g_counter++;
	sig = 0;
}

static void	send_sig(int sig, char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i])
	{
		j = 0;
		s = ft_atobi((unsigned char)str[i]);
		while (s[j] == '0' || s[j] == '1')
		{
			usleep(60);
			kill(sig, s[j] - 18);
			usleep(60);
			signal(SIGUSR1, hand);
			j++;
		}
		free(s);
		i++;
	}
	if (i == g_counter)
		write(1, "delivered with sucess.\n", 24);
}

static int	ft_atoi(char *str)
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
	return (1);
}