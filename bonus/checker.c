/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:56:46 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/17 15:03:19 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "./get_next_line/get_next_line.h"

int main(int argc, char *argv[])
{
    t_stack_node *a;
    t_stack_node *b;
    // char **numbers;
    char *line;
    int fd;

    (void)*a;
    (void)*b;
    (void)*argv;
    a = NULL;
    b = NULL;
    if (argc != 3)
        exit(1);
    // numbers = ft_split(argv[1], ' ');
    // init_stack(a);
    fd = open(argv[1], O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
