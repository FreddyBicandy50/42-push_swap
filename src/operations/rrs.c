/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:18:04 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/19 11:03:15 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack_node	*rrs(t_stack_node *stack, char c)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!stack || !stack->next)
		return (stack);
	last = stack;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = stack;
	stack->prev = last;
	if (c != ' ')
		ft_printf("rr%c\n", c);
	return (last);
}

void	rrr(t_stack_node **sa, t_stack_node **sb, char c)
{
	if (*sa)
		*sa = rrs(*sa, ' ');
	if (*sb)
		*sb = rrs(*sb, ' ');
	if (c != 32)
		ft_printf("rrr\n");
}
