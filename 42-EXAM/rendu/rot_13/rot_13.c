/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:08:59 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 17:44:12 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void paste(char string)
{
    write(1, &string, 1);
}

int main(int argc, char **string)
{
    if (argc != 2)
        {
            paste ('\n');
            return (0);
        }
    int index = 0;
    while (string[1][index])
    {
        if ((string[1][index] >= 'a' && string[1][index] <= 'm') || (string[1][index] >= 'A' && string[1][index] <= 'M'))
            string[1][index] += 13;
        else if ((string[1][index] >= 'n' && string[1][index] <= 'z') || (string[1][index] >= 'N' && string[1][index] <= 'Z'))
            string[1][index] -= 13 ;
        else if ((string[1][index] == 'z') || (string[1][index] == 'Z'))
            string[1][index] -= 25;
        paste(string[1][index]);
        index++ ;
    }
    paste('\n');
}