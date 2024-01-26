/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:53:39 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/26 17:13:43 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void paste(char string)
{
    write(1, &string,1);
}

int lecount(char *string)
{
    int index = 0;
    while (string[index])
    {
        index++ ;
    }
    return index ;
}
int count_big_case(char *string)
{
    int index = 0 ;
    int flag = 0;
    while (string[index])
    {
        if (string[index] >= 'A' && string[index] <= 'Z')
            flag++ ;
        index++ ;
    }    
    return (flag);
}
char *string_made(char *string)
{
    int index = 0;
    char *allocation;
    int increment = 0 ;
    allocation = malloc(sizeof(char) * lecount(string) + count_big_case(string) + 1);
    while (string[index])
    {
        allocation[increment] = string[index];
        increment++ ;
        if (string[index + 1] >= 'A' && string[index + 1] <= 'Z')
        {
            allocation[increment] = '_';
            increment++ ;
        }
        index++ ;
    }
    allocation[increment] = '\0';
    return allocation;
}
void make_it(char *string)
{
    int index = 0;
    char *res = string_made(string);
    while (res[index])
    {
        if (res[index] >= 'A' && res[index] <= 'Z')
            res[index] += 32 ;
        paste(res[index]);
        index++ ;
    }
    free(res);
}
int main(int argc, char **argv)
{
    if (argc != 2)
        {
            paste('\n');
            return (0);
        }
    make_it(argv[1]);
    paste('\n');
}