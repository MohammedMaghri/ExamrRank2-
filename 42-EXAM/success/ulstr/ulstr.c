/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:01:32 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 22:05:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void paste(char string)
{
    write(1,&string,1);
}
int main(int argc, char **argv)
{
    int index = 0;
    if (argc != 2)
    {
        paste('\n');
        return (0);
    }
    while (argv[1][index])
    {
        if (argv[1][index] >= 'a' && argv[1][index] <= 'z')
            argv[1][index] -= 32;
        else if (argv[1][index] >= 'A' && argv[1][index] <= 'Z')
            argv[1][index] += 32;
        paste(argv[1][index]);
        index++ ;
    }
    paste('\n');
}