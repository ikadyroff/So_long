/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:10:56 by wlouveni          #+#    #+#             */
/*   Updated: 2022/04/15 22:04:28 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(void)
{
	ft_putstr_fd("\033[31mError:\e[0m\n", 2);
	ft_putstr_fd("Invalid argument!\n", 2);
	exit(1);
}

void	error_rctngl(void)
{
	ft_putstr_fd("\033[31mError:\e[0m\n", 2);
	ft_putstr_fd("Map is not rectangle!\n", 2);
	exit(1);
}

void	prmtr_error(char **arr, int y)
{
	int	i;

	ft_putstr_fd("\033[31mError:\e[0m\n", 2);
	ft_putstr_fd("Walls are not closed or are not written of '1'!\n", 2);
	i = 0;
	while (i < y)
	{
		free(arr[i]);
		i++;
	}
	exit(1);
}

void	symbols_error(char **arr, int y)
{
	int	i;

	ft_putstr_fd("\033[31mError:\e[0m\n", 2);
	ft_putstr_fd("Wrong symbols in map!\n", 2);
	i = 0;
	while (i < y)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	exit(1);
}

void	is_ber(char **argv)
{
	int	i;

	if (open(argv[1], O_RDONLY) == -1 || !argv[1])
	{
		ft_putstr_fd("\033[31mError:\e[0m\n", 2);
		ft_putstr_fd("Can't open file!\n", 2);
		exit(1);
	}
	i = 0;
	while (argv[1][i] != '.')
		i++;
	if (argv[1][i + 1] != 'b' || argv[1][i + 2] != 'e' ||
		argv[1][i + 3] != 'r' || argv[1][i + 4] != '\0')
	{
		ft_putstr_fd("\033[31mError:\e[0m\n", 2);
		ft_putstr_fd("Map exstention is not '.ber'\n", 2);
		exit(1);
	}	
}
