/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biga.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 07:58:27 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/17 07:58:34 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

void treat_lsta(mlist *mapl, int p)
{
    int c;
    long long int chk;

    chk = mapl->lst_a[p];
    c = (mapl->a_size - mapl->b_size) / 2;
    while (mapl->lst_a[0] != chk)
    {
        if (p <= c)
            r_move(mapl, 'a');
        else
            rr_move(mapl, 'a');
    }
    p_move(mapl, 'b');
}

void back_lsta(mlist *mapl, int *j, int m, int n)
{
    int c;
    int i;
    int p;
    int s;

    s = 1;
    c = mapl->a_size - mapl->b_size;
    while (c > 0 && s)
    {
        --c;
        i = m;
        while (i < n && i >= 0)
        {
            if (mapl->lst_a[c] == mapl->lst_c[i])
            {
                p = c;
                s = 0;
            }
            i++;
        }
    }
    if ((*j - 1) <= (mapl->a_size - p))
        treat_lsta(mapl, *j);
    else
        treat_lsta(mapl, p);
}

int front_lsta(mlist *mapl, int *j, int m, int n)
{
    int c;
    int i;
    int s;

    c = 0;
    s = 1;
    while (c < (mapl->a_size - mapl->b_size) && s)
    {
        i = m;
        while (i < n && i >= 0)
        {
            if (mapl->lst_a[c] == mapl->lst_c[i])
            {
                *j = c;
                s = 0;
            }
            i++;
        }
        c++;
    }
    if (*j == -1)
        return (0);
    back_lsta(mapl, j, m, n);
    return (1);
}

void treat_biga(mlist *mapl, int *c)
{
    int i;
    int j;
    long long int chk;

    *c = mapl->a_size;
    j = *c - (*c / 6);
    chk = mapl->lst_a[0];
    while (*c > 0)
    {
        i = -1;
        if (j < 0)
            j = 0;
        if (!front_lsta(mapl, &i, j, *c))
        {
            depil_treat(mapl, chk, *c);
            chk = mapl->lst_a[0];
            *c -= (mapl->a_size / 6);
            j -= (mapl->a_size / 6);
        }
    }
}

void method_biga(mlist *mapl)
{
    int c;
    long long int chk;

    mapl->lst_c = malloc(sizeof(long long int) * mapl->a_size);
    if (!mapl->lst_c)
    {
        ft_puterr(ALLOCATION);
        good_end(mapl);
    }
    c = 0;
    ft_lintcpy(mapl->lst_c, mapl->lst_a, mapl->a_size);
    ft_sort_linttab(mapl->lst_c, mapl->a_size);
    simp_lst(mapl);
    ft_lintcpy(mapl->lst_c, mapl->lst_a, mapl->a_size);
    ft_sort_linttab(mapl->lst_c, mapl->a_size);
    treat_biga(mapl, &c);
    chk = mapl->lst_a[0];
    depil_treat(mapl, chk, c);
    free(mapl->lst_c);
}