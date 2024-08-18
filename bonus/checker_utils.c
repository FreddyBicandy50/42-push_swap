/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:13:22 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/19 00:44:51 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void do_multi(t_stack_node **sa, t_stack_node **sb, char *operation)
{
	if (ft_strcmp(operation, "pa\n") == 0)
		ps(sb, sa, 32);
	else if (ft_strcmp(operation, "pb\n") == 0)
		ps(sa, sb, 32);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(sa, sb, 32);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(sa, sb, 32);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(sa, sb, 32);
}

void result(t_stack_node *sa, int count)
{
	if (!sorted(sa))
		ft_printf("KO\n");
	if (stack_size(sa) == 3 && count > 3)
		ft_printf("KO\n");
	else if (stack_size(sa) == 5 && count > 8)
		ft_printf("here KO\n");
	else if (stack_size(sa) == 100 && count > 1500)
		ft_printf("KO\n");
	else if (stack_size(sa) == 500 && count >= 11500)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_stack(sa);
	return;
}

void checker(t_stack_node *sa, t_stack_node *sb)
{
	char *line;
	int 	fd;
	int count;

	count = 0;
	fd = open("out", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if (ft_strcmp(line, "pa\n") == 0 || ft_strcmp(line, "pb\n") == 0 || ft_strcmp(line, "rr\n") == 0 || ft_strcmp(line, "rrr\n") == 0 || ft_strcmp(line, "ss\n") == 0)
			do_multi(&sa, &sb, line);
		else if (ft_strcmp(line, "ra\n") == 0)
			sa = rs(sa, 32);
		else if (ft_strcmp(line, "rra\n") == 0)
			sa = rrs(sa, 32);
		else if (ft_strcmp(line, "sa\n") == 0)
			sa = sw(sa, 32);
		else if (ft_strcmp(line, "rb\n") == 0)
			sb = rs(sb, 32);
		else if (ft_strcmp(line, "rrb\n") == 0)
			sb = rrs(sb, 32);
		else if (ft_strcmp(line, "sb\n") == 0)
			sb = sw(sb, 32);
		free(line);
		count++;
	}
	result(sa, count);
}
