/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:47:47 by llion             #+#    #+#             */
/*   Updated: 2023/01/14 13:15:22 by llion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "ftprintf/ft_printf.h"

void	decode(int signal);
int		ft_atoi(const char *str);
void	convert_bits(char *str, int pid);

#endif
