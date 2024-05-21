/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:55:19 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/21 13:22:37 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include <signal.h>
#include <unistd.h>


void binary_converter(char *str, int pid)
{
    int i;
    int base;
    char letter;

    i = 0;
    while(str[i])
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
        }
        i++;
    }
}


int main(int argc, char **argv)
{
    int pid;
    
    if (argc != 3)
        return (0);
    pid = ft_atoi(argv[1]);
    binary_converter(argv[2], pid);
    return (0);
}