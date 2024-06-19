/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:55:19 by igaguila          #+#    #+#             */
/*   Updated: 2024/06/19 17:47:06 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>


// int	ft_atoi(const char *str)
// {
// 	int				i;
// 	int				sign;
// 	unsigned int	num;

// 	i = 0;
// 	sign = 1;
// 	num = 0;
// 	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if ((str[i] == '-') || (str[i] == '+'))
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 		num = num * 10 + (str[i++] - '0');
// 	return ((int)(sign * num));
// }

// void binary_converter(char *str, int pid)
// {
//     int i;
//     int base;
//     char letter;

//     i = 0;
//     while (str[i])
//     {
//         letter = str[i];
//         base = 128;
//         while (base > 0)
//         {
//             if (letter >= base)
//             {
//                 kill(pid, SIGUSR1);
//                 letter -= base;
//             }
//             else
//                 kill(pid, SIGUSR2);
//             base /= 2;
//         }
//         i++;
//     }
// }


// int main(int argc, char **argv)
// {
//     int pid;
    
//     if (argc != 3)
//         return (0);
//     pid = ft_atoi(argv[1]);
//     binary_converter(argv[2], pid);
//     return (0);
// }

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

void	conv_bin(char *s, int pidserv)
{
	int		i;
	int		base;
	char	letra;

	i = 0;
	while (s[i])
	{
		base = 128;
		letra = s[i];
		while (base > 0)
		{
			if (letra >= base)
			{
				kill(pidserv, SIGUSR1);
				letra = letra - base;
			}
			else
				kill(pidserv, SIGUSR2);
			base = base / 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pidserv;

	if (argc != 3)
		return (-1);
	pidserv = ft_atoi(argv[1]);
	conv_bin(argv[2], pidserv);
	return (0);
}