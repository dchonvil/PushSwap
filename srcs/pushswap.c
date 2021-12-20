/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 05:36:56 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/18 03:50:10 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"
#include "ft_printf.h"

void	treat_smalla(t_mlist *mapl)
{
	int				c;
	int				i;
	long long int	chk;

	c = 0;
	chk = mapl->lst_a[0];
	while (c < (mapl->a_size - mapl->b_size))
	{
		if (mapl->lst_a[c] < chk)
		{
			i = c;
			chk = mapl->lst_a[c];
		}
		c++;
	}
	while (mapl->lst_a[0] != chk)
	{
		if (i <= ((mapl->a_size - mapl->b_size) / 2))
			r_move(mapl, 'a');
		else
			rr_move(mapl, 'a');
	}
	p_move(mapl, 'b');
}

void	method_smalla(t_mlist *mapl)
{
	while (mapl->b_size < (mapl->a_size / 2))
		treat_smalla(mapl);
	if ((mapl->a_size - mapl->b_size) == 2)
	{
		if (mapl->lst_a[0] > mapl->lst_a[1])
			r_move(mapl, 'a');
	}
	else if ((mapl->a_size - mapl->b_size) == 3)
		method_a3(mapl);
	while (mapl->b_size > 0)
		p_move(mapl, 'a');
}

void	list_treat(t_mlist *mapl)
{
	mapl->r_size = 0;
	if (mapl->a_size == 3)
		method_a3(mapl);
	else if (mapl->a_size > 3 && mapl->a_size < 6)
		method_smalla(mapl);
	else if (mapl->a_size > 5 && mapl->a_size < 100)
		method_sobiga(mapl);
	else if (mapl->a_size > 99 && mapl->a_size < 150)
		method_biga(mapl);
	else if (mapl->a_size >= 150)
		method_sobiga(mapl);
}

void	list_init(t_mlist *mapl)
{
	mapl->b_size = 0;
	if (!need_sort(mapl, 'a'))
		return ;
	if (mapl->a_size == 2)
	{
		if (mapl->lst_a[0] > mapl->lst_a[1])
			ft_printf("sa\n");
		return ;
	}
	mapl->lst_b = malloc(sizeof(long long int) * mapl->a_size);
	mapl->render = malloc(sizeof(int) * 50000);
	if (!mapl->lst_b || !mapl->render)
	{
		ft_puterr(ALLOCATION);
		good_end(mapl);
	}
	list_treat(mapl);
	free(mapl->lst_b);
	list_render(mapl);
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
