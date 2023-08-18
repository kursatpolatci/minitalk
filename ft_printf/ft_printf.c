/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:28:56 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/24 16:24:00 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (!ft_specifier (*(str + 1)))
			{
				str++;
				continue ;
			}
			count += ft_control (*(str + 1), ap);
			str++;
		}
		else
			count += write (1, str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}
