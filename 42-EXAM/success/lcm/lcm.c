/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:28:50 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 22:34:38 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int n ; 
    if (a == 0 || b == 0)
        return (0);
    if (a > b)
        n = a;
    else 
        n = b;
    while (1)
    {
        if (n % a == 0 && n % b == 0)
            return (n);
        n++ ;
    }
}