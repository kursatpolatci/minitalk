/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:44:04 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/17 18:15:33 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

void	ft_signal_handler(int signal)
{
	static char	c;
	static int	count;

	if (signal == SIGUSR1)
	{
		c <<= 1;
		c |= 1;
	}
	else if (signal == SIGUSR2)
	{
		c <<= 1;
		c |= 0;
	}
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	while (42)
	{
		signal(SIGUSR1, ft_signal_handler);
		signal(SIGUSR2, ft_signal_handler);
		pause();
	}
}
