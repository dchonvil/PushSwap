/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:41:55 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/18 03:16:00 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "pushswap.h"
#include "ft_printf.h"

int	digit_check(char **av, t_mlist *mapl)
{
	int	i;

	i = 0;
	while (av[mapl->a_size])
	{
		while (av[mapl->a_size][i])
		{
			if ((!ft_isdigit(av[mapl->a_size][i]) && av[mapl->a_size][i] != '-')
					|| (av[mapl->a_size][i] == '-'
						&& !ft_isdigit(av[mapl->a_size][i + 1])))
			{
				ft_puterr(IS_NOT_NUM);
				return (0);
			}
			i++;
		}
		i = 0;
		mapl->a_size += 1;
	}
	return (1);
}

int	val_check(char **av, long long int *box)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (av[c])
	{
		if (ft_strlen(av[c]) > 11 || (long long int)ft_atoi(av[c]) > 2147483647
			|| (long long int)ft_atoi(av[c]) < -2147483647)
		{
			ft_puterr(IS_NOT_INT);
			return (0);
		}
		box[i] = (long long int)ft_atoi(av[c]);
		c++;
		i++;
	}
	return (1);
}

int	duplic_check(long long int *box, int size)
{
	int	c;
	int	i;

	c = 0;
	i = size - 1;
	while (c < size)
	{
		while (i > c)
		{
			if (box[c] == box[i])
			{
				ft_puterr(IS_DUPLICATE);
				return (0);
			}
			i--;
		}
		i = size - 1;
		c++;
	}
	return (1);
}

int	treat_sarg(t_mlist *mapl, char **tab)
{
	if (!digit_check(tab, mapl))
	{
		free_tab(tab);
		return (0);
	}
	mapl->lst_a = malloc(sizeof(long long int) * mapl->a_size);
	if (!mapl->lst_a)
	{
		ft_puterr(ALLOCATION);
		free_tab(tab);
		return (0);
	}
	if (!val_check(tab, mapl->lst_a))
	{
		free(mapl->lst_a);
		free_tab(tab);
		return (0);
	}
	if (!duplic_check(mapl->lst_a, mapl->a_size))
	{
		free(mapl->lst_a);
		free_tab(tab);
		return (0);
	}
	return (1);
}

int	check_sarg(char *av, t_mlist *mapl)
{
	char	**tab;

	tab = ft_split(av, ' ');
	if (!tab)
	{
		ft_puterr(SPLIT);
		return (0);
	}
	if (!treat_sarg(mapl, tab))
		return (0);
	free_tab(tab);
	return (1);
}
