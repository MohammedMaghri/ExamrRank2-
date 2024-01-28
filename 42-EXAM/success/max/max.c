/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:08:20 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 22:23:09 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    int index = 0 ;
    int number = 0;
    int flag = 0;
    int increment = 0;

    if (len == 0)
        return (0);
    number = tab[index];
    while (index <= len)
    {
        while (increment <= len)
        {
            if (number > tab[increment])
                flag++ ;
            increment++ ;
        }
        if (flag == (len))
            return (number);
        increment = 0;
        flag = 0;
        index++ ;
        number = tab[index];
    }
    return (0);
}