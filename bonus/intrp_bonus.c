/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intrp_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 03:59:08 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/18 04:05:52 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

void	check_intrp1(t_mlist *mapl, char **box, int c, int i)
{
	int	chk;

	chk = 0;
	if (box[c][i] == 'p')
	{
		if (box[c][i + 1] != 'a' && box[c][i + 1] != 'b')
			chk = 1;
	}
	else if (box[c][i] == 's')
	{
		if (box[c][i + 1] != 'a' && box[c][i + 1] != 'b'
				&& box[c][i + 1] != 's')
			chk = 1;
	}
	if (chk == 1)
		checker_err(mapl, box);
}

void	moves_intrp1(t_mlist *mapl, char **box, int c, int i)
{
	if (box[c][i] == 'p')
	{
		if (box[c][i + 1] == 'a')
			p_move(mapl, 'a');
		else if (box[c][i + 1] == 'b')
			p_move(mapl, 'b');
	}
	else if (box[c][i] == 's')
	{
		if (box[c][i + 1] == 's')
		{
			s_move(mapl, 'a');
			s_move(mapl, 'b');
		}
		else if (box[c][i + 1] == 'a')
			s_move(mapl, 'a');
		else if (box[c][i + 1] == 'b')
			s_move(mapl, 'b');
	}
}

void	check_intrp2(t_mlist *mapl, char **box, int c, int i)
{
	int	chk;

	chk = 0;
	if (box[c][i] == 'r' && str_count(box[c]) == 2)
	{
		if (box[c][i + 1] != 'a' && box[c][i + 1] != 'b'
				&& box[c][i + 1] != 'r')
			chk = 1;
	}
	else if (box[c][i] == 'r' && str_count(box[c]) == 3)
	{
		if (box[c][i + 1] != 'r' || (box[c][i + 2] != 'a'
					&& box[c][i + 2] != 'b' && box[c][i + 2] != 'r'))
			chk = 1;
	}
	if (chk == 1)
		checker_err(mapl, box);
}

void	moves_intrp2(t_mlist *mapl, char **box, int c, int i)
{
	if (str_count(box[c]) == 2)
	{
		if (box[c][i + 1] == 'r')
		{
			r_move(mapl, 'a');
			r_move(mapl, 'b');
		}
		else if (box[c][i + 1] == 'a')
			r_move(mapl, 'a');
		else if (box[c][i + 1] == 'b')
			r_move(mapl, 'b');
	}
	else if (str_count(box[c]) == 3)
	{
		if (box[c][i + 2] == 'r')
		{
			rr_move(mapl, 'a');
			rr_move(mapl, 'b');
		}
		else if (box[c][i + 2] == 'a')
			rr_move(mapl, 'a');
		else if (box[c][i + 2] == 'b')
			rr_move(mapl, 'b');
	}
}

int	checker_check(t_mlist *mapl, char **box)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	mapl->b_size = 0;
	mapl->r_size = 0;
	while (box[c] != NULL)
	{
		check_intrp1(mapl, box, c, i);
		check_intrp2(mapl, box, c, i);
		if (box[c][i] == 'p' || box[c][i] == 's')
			moves_intrp1(mapl, box, c, i);
		else if (box[c][i] == 'r')
			moves_intrp2(mapl, box, c, i);
		c++;
	}
	if (need_sort(mapl, 'a') || mapl->b_size > 0)
		return (0);
	else
		return (1);
}
