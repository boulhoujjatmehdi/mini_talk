/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:24:55 by eboulhou          #+#    #+#             */
/*   Updated: 2022/12/02 10:21:46 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	ft_bzero(char *str, int len)
{
	while (len--)
	{
		str[len] = '0';
	}
}

static char	*ft_atobi(char c)
{
	char	*bin;
	int		i;

	i = 0;
	bin = malloc(8);
	ft_bzero(bin, 8);
	while (c >= 1)
	{
		bin[6 - i] = c % 2 + '0';
		c = c / 2;
		i++;
	}
	bin[7] = 0;
	return (bin);
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
		s = ft_atobi(str[i]);
		while (s[j] == '0' || s[j] == '1')
		{
			if (s[j] == '1')
			{
				kill(sig, SIGUSR2);
			}
			else if (s[j] == '0')
			{
				kill(sig, SIGUSR1);
			}
			usleep(150);
			j++;
		}
		free(s);
		i++;
	}
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
	while (str[i] <= '9' && str[i] >= '0' )
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
