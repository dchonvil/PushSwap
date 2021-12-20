/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:43:44 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/18 04:29:17 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "pushswap.h"
#include "ft_printf.h"
#include "get_next_line.h"

int	str_count(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

void	checker_err(t_mlist *mapl, char **box)
{
	ft_putstr_fd("Error\n", 2);
	free_tab(box);
	good_end(mapl);
}

void	starter_check(t_mlist *mapl, char **box)
{
	int		c;
	int		i;

	c = 0;
	i = 1;
	while (i)
	{
		i = get_next_line(0, box, c);
		c++;
	}
	box[c] = NULL;
	if (!checker_check(mapl, box))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

void	list_init(t_mlist *mapl)
{
	char	**box;

	box = malloc(sizeof(char *) * 200000);
	mapl->render = malloc(sizeof(int) * 200000);
	mapl->lst_b = malloc(sizeof(long long int) * mapl->a_size);
	if (!mapl->lst_b || !box || !mapl->render)
	{
		ft_puterr(ALLOCATION);
		if (box)
			free_tab(box);
		good_end(mapl);
	}
	starter_check(mapl, box);
	free_tab(box);
	free(mapl->lst_b);
	free(mapl->render);
}

int	main(int ac, char **av)
{
	t_mlist	mapl;

	if (ac < 2)
		return (1);
	mapl.a_size = 0;
	if (!check_sarg(av[1], &mapl))
		return (1);
	list_init(&mapl);
	free(mapl.lst_a);
	return (0);
}
