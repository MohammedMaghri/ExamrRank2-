/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:26:48 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/26 11:44:55 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void paste(char string)
{
    write(1, &string, 1);
}
int count_alphabet(int alphabet)
{
    int index ;
    int flag ;

    if (alphabet >= 'a' && alphabet <= 'z')
        flag = 'a';
    else if (alphabet >= 'A' && alphabet <= 'Z')
        flag = 'A';
    else 
        return 0;
    index = 1;
    while (flag != alphabet)
    {
        flag = flag + 1;
        index++ ;
    }
    return index;
}
int check_if(char string)
{
    if (string >= 'a' && string <= 'z' || string >= 'A' && string <= 'Z')
        return (0);
    return (1);
}
void print_number_of_time(char *string)
{
    int index;
    int flag;

    flag = 0;
    index = 0;

    while (string[index])
    {
        flag = count_alphabet(string[index]);
        if ((check_if(string[index]) == 0))
        {
            while (flag != 0)
            {
                paste(string[index]);
                flag-- ;
            }
        }
        else
            paste(string[index]);
        index++ ;
    }
}
int main(int argc, char **argv)
{
    if (argc != 2)
        {
            paste('\n');
            return (0);
        }
    print_number_of_time(argv[1]);
    paste('\n');
}