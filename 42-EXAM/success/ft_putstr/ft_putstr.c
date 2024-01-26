/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:58 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/26 16:52:26 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void paste(char string)
{
    write(1, &string,1);
}

void string_to_low(char *string)
{
    int index = 0;

    while (string[index])
    {
        if (string[index + 1] >= 'A' && string[index + 1] <= 'Z')
        {
            paste('-');
            index++ ;
            string[index] += 32;
        }
        paste(string[index]);
    }
}
int main()
{
    char *string = "ThisIsMe";

    string_to_low(string);
}
