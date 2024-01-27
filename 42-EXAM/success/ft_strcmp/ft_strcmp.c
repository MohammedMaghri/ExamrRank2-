/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:49:52 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 11:55:00 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int    ft_strcmp(char *s1, char *s2)
{
    int index = 0;
    int increment = 0;

    while (s1[index])
    {
        if (s1[increment] != s2[index])
            return (s1[increment] - s2[index]);
        increment++ ;
        index++ ;
    }
    return (0);
}