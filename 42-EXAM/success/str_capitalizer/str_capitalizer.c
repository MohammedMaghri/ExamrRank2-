/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:37:38 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/28 12:05:24 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void paste(char string)
{
    write(1, &string,1);
}
int main(int argc, char **argv)
{
    int index = 0;
    int incre = 1;

    if (argc == 1)
    {
        paste('\n');
        return (0);
    }
    while (argv[incre])
    {
        while (argv[incre][index])
        {
            if (argv[incre][index] >= 'A' && argv[incre][index] <= 'Z')
                argv[incre][index] += 32;
            index++ ;
        }
        index = 0;
        incre++ ;
    }
    incre = 1 ;
    while (argv[incre])
    {
        while (argv[incre][index])
        {
            if (argv[incre][index] >= 'a' && argv[incre][index] <= 'z')
            {
                if (argv[incre][index - 1] == ' ' || argv[incre][index - 1] == '\t' || argv[incre][index - 1] == '\0')
                    argv[incre][index] -= 32 ;
            }
            paste(argv[incre][index]);
            index++ ;
        }
        index = 0;
        incre++ ;
        paste('\n');
    }
}