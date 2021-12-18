/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:47:07 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/18 01:47:09 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

void treat_rmove(mlist *mapl, int size, char name)
{
    long long int *tmp;

    tmp = malloc(sizeof(long long int) * size);
    if (!tmp)
    {
        ft_puterr(ALLOCATION);
        good_end(mapl);
    }
    if (name == 'a')
        ft_lintcpy(tmp, mapl->lst_a, size);
    else
        ft_lintcpy(tmp, mapl->lst_b, size);
    while (size > 1)
    {
        --size;
        if (name == 'a')
            mapl->lst_a[size - 1] = tmp[size];
        else
            mapl->lst_b[size - 1] = tmp[size];
    }
    free(tmp);
}

void r_move(mlist *mapl, char name)
{
    long long int tmp;

    if (name == 'a')
    {
        tmp = mapl->lst_a[0];
        treat_rmove(mapl, mapl->a_size - mapl->b_size, name);
    }
    else
    {
        tmp = mapl->lst_b[0];
        treat_rmove(mapl, mapl->b_size, name);
    }
    if (name == 'a')
    {
        mapl->lst_a[(mapl->a_size - mapl->b_size) - 1] = tmp;
        mapl->render[mapl->r_size] = 3;
    }
    else if (name == 'b')
    {
        mapl->lst_b[mapl->b_size - 1] = tmp;
        mapl->render[mapl->r_size] = 4;
    }
    if (check_render(mapl))
        mapl->r_size += 1;
}

void treat_rrmove(mlist *mapl, int size, char name)
{
    int c;
    long long int *tmp;

    tmp = malloc(sizeof(long long int) * size);
    if (!tmp)
    {
        ft_puterr(ALLOCATION);
        good_end(mapl);
    }
    c = 0;
    if (name == 'a')
        ft_lintcpy(tmp, mapl->lst_a, size);
    else
        ft_lintcpy(tmp, mapl->lst_b, size);
    while (c < (size - 1))
    {
        if (name == 'a')
            mapl->lst_a[c + 1] = tmp[c];
        else
            mapl->lst_b[c + 1] = tmp[c];
        c++;
    }
    free(tmp);
}

void rr_move(mlist *mapl, char name)
{
    long long int tmp;

    if (name == 'a')
    {
        tmp = mapl->lst_a[(mapl->a_size - mapl->b_size) - 1];
        treat_rrmove(mapl, mapl->a_size - mapl->b_size, name);
    }
    else
    {
        tmp = mapl->lst_b[mapl->b_size - 1];
        treat_rrmove(mapl, mapl->b_size, name);
    }
    if (name == 'a')
    {
        mapl->lst_a[0] = tmp;
        mapl->render[mapl->r_size] = 5;
    }
    else if (name == 'b')
    {
        mapl->lst_b[0] = tmp;
        mapl->render[mapl->r_size] = 6;
    }
    if (check_render(mapl))
        mapl->r_size += 1;
}

void p_move(mlist *mapl, char name)
{
    int size;
    long long int tmp;

    size = mapl->a_size - mapl->b_size;
    if (name == 'a')
    {
        tmp = mapl->lst_b[0];
        treat_rmove(mapl, mapl->b_size, 'b');
        treat_rrmove(mapl, size + 1, 'a');
        mapl->lst_a[0] = tmp;
        mapl->b_size -= 1;
        mapl->render[mapl->r_size] = 7;
    }
    else
    {
        mapl->b_size += 1;
        tmp = mapl->lst_a[0];
        treat_rmove(mapl, size, 'a');
        treat_rrmove(mapl, mapl->b_size, 'b');
        mapl->lst_b[0] = tmp;
        mapl->render[mapl->r_size] = 8;
    }
    if (check_render(mapl))
        mapl->r_size += 1;
}