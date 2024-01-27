/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:01:11 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 15:12:09 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int count_alphabet(char string)
{
    char allphabet;
    int index = 0;

    if (string >= 'a' && string <= 'z')
        allphabet = 'a';
    else if (string >= 'A' && string <= 'Z')
        allphabet = 'A';
    else 
        return (0);
    while (allphabet != string)
    {
        index++ ;
        allphabet = allphabet + 1;
    }
    return  index ;
}
void paste(char string)
{
    write(1,&string,1);
}
void repeat_it(char *string)
{
    int index = 0;
    int total ;
    while (string[index])
    {
        total = count_alphabet(string[index]);
        while (total >= 0)
        {
            paste(string[index]);
            total-- ;
        }
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
    repeat_it(argv[1]);
    paste('\n');
}