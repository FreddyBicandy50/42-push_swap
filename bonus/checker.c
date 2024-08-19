/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:04:06 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/19 10:56:00 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_perror(bool isOne, t_stack_node *sa)
{
	if (isOne)
		free_stack(sa);
	else
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
		ft_perror(false, NULL);
	temp[0] = '\0';
	i = 1;
	while (argv[i])
	{
		new_temp = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!new_temp)
		{
			free_array(argv);
			ft_perror(false, NULL);
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
		ft_perror(false, NULL);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = arg_case(argv);
	if (!argv)
		ft_perror(false, NULL);
	sa = stack_store(argv);
	free_array(argv);
	if (sa == NULL)
	{
		free_stack(sa);
		ft_perror(false, NULL);
	}
	if (stack_size(sa) == 1)
		ft_perror(true, sa);
	checker(sa, sb);
	return (0);
}
