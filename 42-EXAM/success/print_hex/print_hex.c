/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:56:13 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 12:29:47 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void paste(char string)
{
    write(1, &string, 1);
}
void function_hex(unsigned int number)
{
    char *allocation ;
    int index;

    allocation = "0123456789abcdef";

    if (number < 16)
        paste(allocation[number % 16]);
    else
    {
        function_hex(number / 16);
        function_hex(number % 16);
    }
}
int iato(char *string)
{
    int index = 0;
    int total = 0;
    int minis = 1;

    while ((string[index] >= 9 && string[index] <= 13) || (string[index] == ' '))
        index++ ;
    if (string[index] && (string[index] == '-' || string[index] == '+'))
    {
        if (string[index] == '-')
            minis *= -1;
        index++;
    }
    while (string[index] && (string[index] >= '0' && string[index] <= '9'))
    {
        total = (total * 10) + (string[index] - '0');
        index++ ;
    }
    return (total * minis);
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        paste('\n');
        return (0);
    }
   function_hex(iato(argv[1]));
   paste ('\n');
}