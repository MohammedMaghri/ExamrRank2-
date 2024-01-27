/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:15:50 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 15:55:37 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void paste(char string)
{
    write(1,&string,1);
}

int no_copy(char *string, int max_pos,char character)
{
    int index = 0 ;
    int flag = 0;
    while (index < max_pos)
    {
        if(string[index] == character)
            return (1);
        index++ ;
    }
    return (0);
}
void check_doble(char *string, char *other)
{
    int index = 0;
    char flag = 0;
    int increment = 0;


    while (string[index])
    {
        if (no_copy(string, index, string[index]) == 0)
            paste(string[index]);
        index++ ;
    }
    index = 0;
    while (other[index])
    {
        if (no_copy(string, increment, other[index]) == 0 && no_copy(other, index, other[index]) == 0)
            paste(other[increment]);
        increment++ ;
        index++ ;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
        {
            paste('\n');
            return (0);
        }
    check_doble(argv[1], argv[2]);
    paste('\n');
}