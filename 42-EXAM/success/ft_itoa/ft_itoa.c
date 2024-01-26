/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:44:15 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/26 22:02:19 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int count_number(int number)
{
    int index = 0 ;
    if (number < 0)
        index++ ;
    while (number != 0)
    {
        number /= 10;
        index++ ;
    }
    return index ;
}

char	*ft_itoa(int nbr)
{
    int res_number = count_number(nbr);
    if (nbr == 0)
        res_number = 1;
    char *allocation = malloc(sizeof(char) * (res_number + 1));
    if (nbr < 0)
    {
        nbr *= -1;
        allocation[0] = '-';   
    }
    allocation[res_number] = '\0';
    res_number--;
    if (nbr == 0)
    {
        allocation[res_number] = '0';
        return (allocation);
    }
    while (nbr != 0 && res_number >= 0)
    {
        allocation[res_number] = (nbr % 10) + '0';
        nbr /= 10 ;
        res_number--;
    }
    return (allocation);
}