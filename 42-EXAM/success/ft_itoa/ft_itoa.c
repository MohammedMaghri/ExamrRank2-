/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:35:44 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 22:45:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int count(int number)
{
    int index = 0;
    if (number < 0)
        {
            number *= -1;
            index++ ;
        }
    while (number != 0)
    {
        number /= 10 ;
        index++ ;
    }
    return (index);
}
char	*ft_itoa(int nbr)
{
    int index = 0;
    char *allocation;
    int total = count(nbr);
    int flag = 0;

    allocation = malloc(sizeof(char) * count(nbr) + 1);
    allocation[total] = '\0';
    total-- ;
    if (nbr == 0)
    {
        allocation[0] = '0';
        return (allocation);
    }
    if (nbr < 0)
        {
            flag = 1;
            allocation[0] = '-';
            nbr *= -1 ;
        }
    while (total >= flag)
    {
        allocation[total] = ((nbr %10) + '0');
        nbr /= 10 ;
        total--;
    }
    return (allocation);
}