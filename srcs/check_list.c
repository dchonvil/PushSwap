/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:32:56 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/17 09:33:11 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

void good_end(mlist *mapl)
{
    if (mapl->lst_a)
        free(mapl->lst_a);
    if (mapl->lst_b)
        free(mapl->lst_b);
    if (mapl->lst_c)
        free(mapl->lst_c);
    if (mapl->render)
        free(mapl->render);
    exit(1);
}

void method_a3(mlist *mapl)
{
    if (mapl->lst_a[1] < mapl->lst_a[0] && mapl->lst_a[1] > mapl->lst_a[2])
    {
        s_move(mapl, 'a');
        rr_move(mapl, 'a');
    }
    else if (mapl->lst_a[2] < mapl->lst_a[1] && mapl->lst_a[2] > mapl->lst_a[0])
    {
        s_move(mapl, 'a');
        r_move(mapl, 'a');
    }
    else if (mapl->lst_a[0] < mapl->lst_a[1] && mapl->lst_a[0] > mapl->lst_a[2])
        rr_move(mapl, 'a');
    else if (mapl->lst_a[2] > mapl->lst_a[1] && mapl->lst_a[2] < mapl->lst_a[0])
        r_move(mapl, 'a');
    else if (mapl->lst_a[0] > mapl->lst_a[1] && mapl->lst_a[0] < mapl->lst_a[2])
        s_move(mapl, 'a');
}

void method_b3(mlist *mapl)
{
    if (mapl->lst_b[2] > mapl->lst_b[1] && mapl->lst_b[2] < mapl->lst_b[0])
    {
        rr_move(mapl, 'b');
        s_move(mapl, 'b');
    }
    else if (mapl->lst_b[1] > mapl->lst_b[0] && mapl->lst_b[1] < mapl->lst_b[2])
    {
        s_move(mapl, 'b');
        rr_move(mapl, 'b');
    }
    else if (mapl->lst_b[0] > mapl->lst_b[1] && mapl->lst_b[0] < mapl->lst_b[2])
        rr_move(mapl, 'b');
    else if (mapl->lst_b[2] < mapl->lst_b[1] && mapl->lst_b[2] > mapl->lst_b[0])
        r_move(mapl, 'b');
    else if (mapl->lst_b[0] < mapl->lst_b[1] && mapl->lst_b[0] > mapl->lst_b[2])
        s_move(mapl, 'b');
}

int need_sort(mlist *mapl, char name)
{
    int size;

    if (name == 'a')
        size = mapl->a_size - mapl->b_size;
    else
        size = mapl->b_size;
    while (size > 1)
    {
        --size;
        if (name == 'a')
        {
            if (mapl->lst_a[size] < mapl->lst_a[size - 1])
                return (1);
        }
        else if (name == 'b')
        {
            if (mapl->lst_b[size] > mapl->lst_b[size - 1])
                return (1);
        }
    }
    return (0);
}

void s_move(mlist *mapl, char name)
{
    long long int tmp;

    if (name == 'a')
    {
        tmp = mapl->lst_a[0];
        mapl->lst_a[0] = mapl->lst_a[1];
        mapl->lst_a[1] = tmp;
        mapl->render[mapl->r_size] = 1;
    }
    else
    {
        tmp = mapl->lst_b[0];
        mapl->lst_b[0] = mapl->lst_b[1];
        mapl->lst_b[1] = tmp;
        mapl->render[mapl->r_size] = 2;
    }
    if (check_render(mapl))
        mapl->r_size += 1;
}
