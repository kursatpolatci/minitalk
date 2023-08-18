/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:30:31 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/17 18:16:48 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

void	whitespaces(char *str, int *index, int *sign);
int		ft_atoi(char *str);
void	ft_signal_sending(char c, pid_t pid);

void	ft_signal_handler(int signal);
#endif