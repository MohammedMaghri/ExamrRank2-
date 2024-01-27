/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:29:18 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 11:47:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void paste(char string)
{
    write(1, &string, 1);
}
void bring_first(char *string)
{
    int index = 0;
    int increment = 0;

    while (string[index] && string[index] == ' ')
    {
        increment++ ;
        index++;
    }
    while (string[index] && string[index] != ' ')
        index++ ;
    while (increment < index)
    {
        paste(string[increment]);
        increment++ ;
    }
}
int main(int argc, char **argv)
{
    if (argc != 2)
        {
            paste('\n');
            return (0);
        }
    bring_first(argv[1]);
    paste('\n');
}
