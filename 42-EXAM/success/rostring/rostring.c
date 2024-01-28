/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:07:25 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/28 14:03:18 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int count_word(char *string)
{
    int index = 0;
    int flag = 0;

    while (string[index])
    {
        if (string[index] == ' ')
            index++ ;
        else
        {
            flag++ ;
            while (string[index] && string[index] != ' ')
                index++ ;
        }
    }
    return (flag);
}

int lecount(char *string)
{
    int index = 0;

    while (string[index])
    {
        index++ ;
    }
    return (index);
}

char *make_this_copy(char *string)
{
    int index = 0;
    char *allocation ;
    allocation = malloc(sizeof(char) * (lecount(string) + 1));
    if (!allocation)
        return (NULL);
    while (string[index])
    {
        allocation[index] = string[index];
        index++ ;
    }
    allocation[index] = '\0';
    return (allocation);
}

char *copy_till_null(char *string, int check_point)
{
    int index = 0;
    int increment = 0;
    char *allocation ;
    allocation = malloc(sizeof(char) * lecount(string) + 1);
    if (!allocation)
        return (NULL);
    while (string[index] == ' ' || string[index] == '\t')
        index++ ;
    while (string[index] && index < check_point)
    {
        allocation[increment] = string[index];
        index++ ;
        increment++ ;
    }
    allocation[increment] = '\0';
    return (allocation);
}

char    **make_copy(char *string)
{
    int index = 0;
    char **allocation;
    int flag = 0;
    int increment = 0;

    allocation = malloc(sizeof(char **) * 10000);
    while (string[index])
    {
        if (string[index] != ' ' && string[index + 1] == ' ' || string[index + 1] == '\0')
        {
            index++ ;
            flag = index ;
            allocation[increment] = copy_till_null(string, flag);
            string = make_this_copy(&string[index]);
            index = 0;
            flag = 0;
            increment++ ;
        }
        index++ ;
    }
    allocation[increment] = NULL ;
    return (allocation);
}

int len_array(char **array)
{
    int index = 0;
    while (array[index])
    {
        index++ ;
    }
    return index ;
}

char *make_all_in(char **string)
{
    int index = 0;
    int increment = 1;
    int total = 0 ;
    char *allocation ;
    allocation = malloc(sizeof(char) * 1000);
    while (string[increment])
    {
        while (string[increment][index])
        {
            allocation[total] = string[increment][index];
            total++ ;
            index++ ;
        }
        index = 0;
        allocation[total] = ' ';
        total++ ;
        increment++ ;
    }
    allocation[total] = '\0';
    return (allocation);
}
void putstr(char *string)
{
    while (*string)
        write(1,string++,1);
}
void paste(char string)
{
    write(1,&string,1);
}
void free_all(char **array)
{
    int index = 0;
    while (array[index])
    {
        free(array[index]);
        index++ ;
    }
    free(array);
}
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        paste('\n');
        return (0);
    }
    char **res = make_copy(argv[1]);
    if (count_word(argv[1]) == 1)
        {
            putstr(res[0]);
            paste('\n');
            free_all(res);
            return (0);
        }
    char *turn = make_all_in(res);
    putstr(turn);
    free(turn);
    putstr(res[0]);
    free_all(res);
    paste('\n');
}