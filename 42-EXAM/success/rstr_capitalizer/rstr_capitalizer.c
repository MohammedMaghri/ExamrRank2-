/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:15:53 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/26 12:48:52 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void paste(char string)
{
    write(1, &string,1);
}
int check_alphabet(char string)
{
    if (string >= 'a' && string <= 'z' || string >= 'A' && string <= 'Z')
        return (1);
    return (0);
}
void make_it_bigger(char string)
{
    if (string >= 'a' && string <= 'z')
    {
        string -= 32 ;
        paste(string);
    }
    else if (string >= 'A' && string <= 'Z')
    {
        string += 32;
        paste(string);
    }
}
int main(int ac , char **string)
{
    if (ac == 1)
        {
            paste('\n');
            return (0);
        }
    int index = 0;
    int increment = 1;
    while (string[increment] != NULL)
    {
        while (string[increment][index])
        {
            if (string[increment][index] >= 'A' && string[increment][index] <= 'Z')
                string[increment][index] += 32 ;
            if ((check_alphabet(string[increment][index]) == 1) && (string[increment][index + 1] == ' ' || \
            string[increment][index + 1] == '\t' || string[increment][index + 1] == '\0'))
            {
                if (string[increment][index] >= 'a' && string[increment][index] <= 'z')
                    string[increment][index] -= 32 ;
            }
            paste(string[increment][index]);
            index++ ;
        }
        index = 0;
        increment++ ;
        paste('\n');
    }
}