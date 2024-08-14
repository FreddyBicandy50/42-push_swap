/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:46:45 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/13 15:53:04 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("ERROR\n");
	exit(-1);
}

char	**arg_case(char **argv)
{
	int		i;
	char	*temp;
	char	*new_temp;

	temp = (char *)malloc(1);
	if (!temp)
		ft_error();
	temp[0] = '\0';
	i = 1;
	while (argv[i])
	{
		new_temp = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!new_temp)
		{
			free_array(argv);
			ft_error();
		}
		temp = new_temp;
		i++;
	}
	argv = ft_split(temp, ' ');
	free(temp);
	return (argv);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*sa;
	t_stack_node	*sb;

	sa = NULL;
	sb = NULL;
	if (argc < 2)
		ft_error();
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = arg_case(argv);
	if (!argv)
		ft_error();
	sa = stack_store(argv);
	free_array(argv);
	if (sa == NULL)
	{
		free_stack(sa);
		ft_error();
	}
	sort(sa, sb);
	return (0);
}