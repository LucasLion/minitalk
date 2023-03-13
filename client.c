/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:48:18 by llion             #+#    #+#             */
/*   Updated: 2023/01/14 13:19:17 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	if (sign > 0)
		return (number);
	else
		return (-number);
}

void	convert_bits(char *str, int pid)
{
	int	i;
	int	b;

	i = 0;
	while (str[i])
	{
		b = 0;
		while (b < 8)
		{
			if ((str[i] >> b) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			b++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		convert_bits(argv[2], ft_atoi(argv[1]));
	else
	{
		ft_printf("Erreur: Nombre d'arguments incorrect\n");
		return (1);
	}
	return (0);
}
