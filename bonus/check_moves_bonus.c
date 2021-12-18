/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:46:48 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/18 01:46:52 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf.h"

int check_render(mlist *mapl)
{
    if ((mapl->r_size + 1) == 100000)
    {
        ft_puterr(ALLOCATION);
        good_end(mapl);
    }
    return (1);
}

void check_smove(mlist *mapl, int *c)
{
    if (mapl->render[*c] == 1)
    {
        if (mapl->r_size > (*c + 1) && mapl->render[*c + 1] == 2)
        {
            ft_printf("ss\n");
            *c += 1;
        }
        else
            ft_printf("sa\n");
    }
    else if (mapl->render[*c] == 2)
    {
        if (mapl->r_size > (*c + 1) && mapl->render[*c + 1] == 1)
        {
            ft_printf("ss\n");
            *c += 1;
        }
        else
            ft_printf("sb\n");
    }
}

void check_rmove(mlist *mapl, int *c)
{
    if (mapl->render[*c] == 3)
    {
        if (mapl->r_size > (*c + 1) && mapl->render[*c + 1] == 4)
        {
            ft_printf("rr\n");
            *c += 1;
        }
        else
            ft_printf("ra\n");
    }
    else if (mapl->render[*c] == 4)
    {
        if (mapl->r_size > (*c + 1) && mapl->render[*c + 1] == 3)
        {
            ft_printf("rr\n");
            *c += 1;
        }
        else
            ft_printf("rb\n");
    }
}

void check_rrmove(mlist *mapl, int *c)
{
    if (mapl->render[*c] == 5)
    {
        if (mapl->r_size > (*c + 1) && mapl->render[*c + 1] == 6)
        {
            ft_printf("rrr\n");
            *c += 1;
        }
        else
            ft_printf("rra\n");
    }
    else if (mapl->render[*c] == 6)
    {
        if (mapl->r_size > (*c + 1) && mapl->render[*c + 1] == 5)
        {
            ft_printf("rrr\n");
            *c += 1;
        }
        else
            ft_printf("rrb\n");
    }
}

void list_render(mlist *mapl)
{
    int c;

    if (!mapl->render)
        return ;
    c = 0;
    while (c < mapl->r_size)
    {
        if (mapl->render[c] == 1 || mapl->render[c] == 2)
            check_smove(mapl, &c);
        else if (mapl->render[c] == 3 || mapl->render[c] == 4)
            check_rmove(mapl, &c);
        else if (mapl->render[c] == 5 || mapl->render[c] == 6)
            check_rrmove(mapl, &c);
        else if (mapl->render[c] == 7)
            ft_printf("pa\n");
        else if (mapl->render[c] == 8)
            ft_printf("pb\n");
        c++;
    }
}