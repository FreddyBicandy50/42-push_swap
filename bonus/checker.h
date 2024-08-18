/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:54:30 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/18 23:19:00 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include "../push_swap.h"
#include "./get_next_line/get_next_line.h"

void ft_perror(bool isOne, t_stack_node *sa);
void checker(t_stack_node *sa, t_stack_node *sb);

#endif