/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:10:01 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/26 21:20:11 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int is_power_of_2(unsigned int n)
{
    if (n == 1)
        return 0;
    if (n == 0)
        return 0;
    if (n % 2 == 0)
        return 1;
        
    return 0;
}