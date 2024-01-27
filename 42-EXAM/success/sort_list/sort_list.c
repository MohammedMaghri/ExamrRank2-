/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:31:41 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/27 14:19:30 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void swap_list(t_list *list, t_list *list_b)
{
    int temp;

    temp = list->data ;
    list->data = list_b->data;
    list_b->data = temp ;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int flag = 1;
    t_list *Node = lst;

    while (flag == 1)
    {
        flag = 0;
        while (Node != 0 && Node->next != 0)
        {
            if (cmp(Node->data, Node->next->data) == 0)
            {
                swap_list(Node ,Node->next);
                flag = 1;
            }
            Node = Node->next;
        }
       Node = lst ;
    }
    return (lst);
}