/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:42:53 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/17 18:16:41 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	whitespaces(char *str, int *index, int *sign)
{
	while ((str[*index] >= 9 && str[*index] <= 13) || str[*index] == 32)
		*index += 1;
	if (str[*index] == 43 || str[*index] == 45)
	{
		if (str[*index] == 45)
			*sign = -1;
		*index += 1;
	}
}

int	ft_atoi(char *str)
{
	int		index;
	int		sign;
	long	result;

	result = 0;
	index = 0;
	sign = 1;
	whitespaces(str, &index, &sign);
	while (str[index] >= '0' && str[index] <= '9' && str[index])
	{
		result = (result * 10) + (str[index] - '0');
		if (result * sign < -2147483648)
			return (0);
		else if (result * sign > 2147483647)
			return (-1);
		index++;
	}
	return (result * sign);
}

void	ft_signal_sending(char c, pid_t pid)
{
	int	swap;

	swap = 7;
	while (swap >= 0)
	{
		if ((c >> swap) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		swap--;
	}
}

int	main(int argc, char **argv)
{
	int		index;
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		index = 0;
		while (argv[2][index])
		{
			ft_signal_sending(argv[2][index], pid);
			index++;
		}
	}
}
