/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:12:48 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/28 11:29:34 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void paste_all(char *string)
{
    while (*string)
        write(1,string++ ,1);
}
void paste(char string)
{
    write(1, &string ,1);
}
void paste_number(int number)
{
    if (number < 0)
    {
        paste('-');
        paste_number(number *= -1);
    }
    else if (number < 10)
    {
        paste(number + '0');
    }
    else if (number >= 10)
    {
        paste_number(number / 10);
        paste_number(number % 10);
    }
}
int main()
{
    int number = 1;

    while (number <= 100)
    {
        if (number % 3 == 0 && number % 5 == 0)
            paste_all("fizzbuzz");
        else if (number % 3 == 0)
            paste_all("fizz");
        else if (number % 5 == 0)
            paste_all("buzz");
        else 
            paste_number(number);
        paste('\n');
        number++ ;
    }
}
