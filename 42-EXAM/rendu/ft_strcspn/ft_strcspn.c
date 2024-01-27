/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:05:49 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 18:07:23 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t index  = 0;

    while (s[index])
    {
        if (s[index] == *reject)
            break;
        index++ ;
    }
    return  index ;
}