/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:10:52 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/19 11:01:44 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ps(t_stack_node **src, t_stack_node **dest, char c)
{
	t_stack_node	*temp;

	if (!src || !(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->next = *dest;
	if (*dest)
		(*dest)->prev = temp;
	*dest = temp;
	temp->prev = NULL;
	if (c != 32)
		ft_printf("p%c\n", c);
}
