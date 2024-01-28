/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:31:26 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/28 16:32:21 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t index = 0;
    while (s[index])
    {
        if (s[index] == *reject)
            return (index);
        index++ ;
    }
    return index ;
}