/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:30:50 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 16:57:22 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int count_all(int number)
{
    int index = 0;

    if (number < 0)
    {
        number *= -1;
        index++ ;
    }
    while (number != 0)
    {
        number = number / 10 ;
        index++ ;
    }
    return index;
}
char	*ft_itoa(int nbr)
{
    int index = 0;
    int flag = 0;
    char *allocation ;
    int total = count_all(nbr);
    allocation = malloc(sizeof(char) + count_all(nbr) + 1);
    if (nbr == 0)
    {
        allocation[total] = '0';
        return (allocation);
    }
    if (nbr < 0)
    {
        nbr *= -1;
        allocation[0] = '-';
        flag = 1;
    }
    allocation[total] = '\0';
    total-- ;
    while (total >= flag)
    {
        allocation[total] = (nbr % 10) + '0';
        nbr /= 10 ;
        total-- ;
    }
    return allocation ;
}
