/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:05:58 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 16:27:46 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void paste(char string)
{
    write(1,&string,1);
}
int this_conv(char *string)
{
    int index = 0;
    int total = 0;
    int minis = 1;

    while (string[index] && string[index] >= 9 && string[index] <= 13)
        index++ ;
    while (string[index] == '-' || string[index] == '+') 
        {
            if (string[index] == '-')
                minis *= -1;
            index++ ;
        }
    while (string[index] >= '0' && string[index] <= '9')
    {
        total = (total * 10) + (string[index] - '0');
        index++ ;
    }
    return (total * minis);
}

void put_number(int number)
{
    if (number < 10)
        paste(number + '0');
    else if (number >= 10)
    {
        put_number(number / 10);
        put_number(number % 10);
    }
}
void putstr(char *string)
{
    while (*string)
        write(1,string++,1);
}
void table(int number)
{
    int index = 1;
    while (index <= 9)
    {
        put_number(index);
        paste(' ');
        paste('x');
        paste(' ');
        put_number(number);
        paste(' ');
        paste('=');
        paste(' ');
        put_number(index * number);
        paste('\n');
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
    table(this_conv(argv[1]));
}