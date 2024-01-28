/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:31:27 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/28 11:36:12 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
    int number = 0;
    int minis = 1;
    int index = 0;

    while ((str[index] >= 9 && str[index] <= 13) || (str[index] == ' '))
        index++ ;
    if ((str[index] == '-') || (str[index] == '+'))
        {
            if (str[index] == '-')
            {
                minis *= -1;
            }
            index++ ;
        }
    while (str[index] >= '0' && str[index] <= '9')
    {
        number = (number * 10) + str[index] - '0';
        index++ ;
    }
    return (number * minis);
}