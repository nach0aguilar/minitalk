/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:55:19 by igaguila          #+#    #+#             */
/*   Updated: 2024/06/27 21:45:27 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return ((int)(sign * num));
}

void	binary_converter(char *str, int pid)
{
	int		i;
	int		base;
	char	letter;

	i = 0;
	while (str[i])
	{
		base = 128;
		letter = str[i];
		while (base > 0)
		{
			if (letter >= base)
			{
				kill(pid, SIGUSR1);
				letter -= base;
			}
			else
				kill(pid, SIGUSR2);
			base /= 2;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pidserv;

	if (argc != 3)
		return (0);
	pidserv = ft_atoi(argv[1]);
	binary_converter(argv[2], pidserv);
	return (0);
}