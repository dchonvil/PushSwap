/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sobiga.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 08:23:55 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/17 08:23:59 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

void restore_a(mlist *mapl, long long int chk)
{
    int c;
    int i;
    int j;

    i = 0;
    j = 0;
    c = (mapl->a_size - mapl->b_size) / 2;
    while (i < (mapl->a_size - mapl->b_size))
    {
        if (mapl->lst_a[i] == chk)
            j = i;
        i++;
    }
    if (mapl->lst_a[0] != chk)
    {
        if (j <= c)
            r_move(mapl, 'a');
        else
            rr_move(mapl, 'a');
    }
}

void check_depil(mlist *mapl, long long int chk, int m, int j)
{
    int c;
    int i;
    long long int n;

    i = 0;
    c = mapl->b_size / 2;
    n = mapl->lst_b[0];
    while (i < mapl->b_size)
    {
        if (mapl->lst_b[i] > n)
        {
            j = i;
            n = mapl->lst_b[i];
        }
        i++;
    }
    while (mapl->lst_b[0] != n)
    {
        if (j <= c)
            r_move(mapl, 'b');
        else
            rr_move(mapl, 'b');
        if (mapl->lst_a[0] != chk && m < mapl->a_size)
            restore_a(mapl, chk);
    }
}

void depil_treat(mlist *mapl, long long int chk, int m)
{
    while (mapl->b_size > 0)
    {
        check_depil(mapl, chk, m, 0);
        if (m < mapl->a_size)
        {
            while (mapl->lst_a[0] != chk)
                restore_a(mapl, chk);
            chk = mapl->lst_b[0];
        }
        p_move(mapl, 'a');
    }
}

void treat_sobiga(mlist *mapl)
{
    int c;
    int i;
    int j;
    int s;

    c = 0;
    i = 0;
    s = mapl->a_size - 1;
    while ((s >> c) != 0)
        ++c;
    while (i < c)
    {
        j = 0;
        while (j < mapl->a_size)
        {
            if (((mapl->lst_a[0] >> i) & 1) == 1)
                r_move(mapl, 'a');
            else
                p_move(mapl, 'b');
            ++j;
        }
        while (mapl->b_size > 0)
            p_move(mapl, 'a');
        ++i;
    }
}

void method_sobiga(mlist *mapl)
{
    mapl->lst_c = malloc(sizeof(long long int) * mapl->a_size);
    if (!mapl->lst_c)
    {
        ft_puterr(ALLOCATION);
        good_end(mapl);
    }
    ft_lintcpy(mapl->lst_c, mapl->lst_a, mapl->a_size);
    ft_sort_linttab(mapl->lst_c, mapl->a_size);
    simp_lst(mapl);
    treat_sobiga(mapl);
    free(mapl->lst_c);
}
