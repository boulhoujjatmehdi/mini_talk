/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:00:24 by eboulhou          #+#    #+#             */
/*   Updated: 2023/01/03 19:05:25 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <unistd.h>
# include <signal.h>

typedef struct s_idx_arr
{
	int		str;
	int		last;
	int		i;
	int		j;
	int		c;
	int		bol;
	int		size;
	char	strr[5];
}t_idx;

#endif