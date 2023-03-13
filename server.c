/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:48:18 by llion             #+#    #+#             */
/*   Updated: 2023/01/14 13:19:16 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decode(int signal)
{
	static int	bit = 0;	
	static char	c = 0;

	if (signal == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("PID: %d\n", pid);
		signal(SIGUSR1, decode);
		signal(SIGUSR2, decode);
		while (1)
			pause();
	}
	else
	{
		ft_printf("Erreur: Nomber d'arguments incorrect\n");
		return (1);
	}
	return (0);
}
