/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:55:31 by igaguila          #+#    #+#             */
/*   Updated: 2024/07/02 18:06:28 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	text_converter(char *c)
{
	int		i;
	int		base;
	char	letter;

	i = 0;
	while (i < 8)
	{
		base = 128;
		letter = 0;
		while (base > 0)
		{
			if (c[i] == '1')
				letter += base;
			base /= 2;
			i++;
		}
		write(1, &letter, 1);
	}
}

void	handle_signal(int signal)
{
	static int	i = 0;
	static char	c[8];

	if (signal == SIGUSR1)
		c[i] = '1';
	else if (signal == SIGUSR2)
		c[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		text_converter(c);
	}
}

int	main(void)
{
	getpid();
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		sleep(1);
	return (0);
}
