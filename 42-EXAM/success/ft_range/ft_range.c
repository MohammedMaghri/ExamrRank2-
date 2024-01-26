/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:21:31 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/26 21:42:32 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int count_how_many(int start , int end)
{
    int index = 0;
    if (start < end)
    {
        while (start <= end)
        {
            index++ ;
            start++ ;
        }
    }
    else if (start >= end)
    {
        while (start >= end)
        {
            index++ ;
            start-- ;
        }
    }
    return (index);
}
int     *ft_range(int start, int end)
{
    int index = 0;
    int *allocation;
    allocation = malloc(sizeof(int) * count_how_many(start, end));
    if (start <=  end)
    {
        while (start <= end)
        {
            allocation[index] = start ;
            index++ ;
            start++ ;
        }
    }
    else if (start >= end)
    {
        while (start >= end)
        {
            allocation[index] = start ;
            index++ ;
            start-- ;
        }
    }
    return (allocation);
}