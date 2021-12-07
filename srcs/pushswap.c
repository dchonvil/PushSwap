/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 05:36:56 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/29 05:37:06 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "pushswap.h"
#include "ft_printf.h"

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


void depil_treat(mlist *mapl)
{
    int c;
    int i;
    int j;
    long long int n;

    i = 0;
    c = mapl->b_size / 2;
    while (mapl->b_size > 0)
    {
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
        i = 0;
        while (mapl->lst_b[0] != n)
        {
            if (j <= c)
                r_move(mapl, 'b');
            else
                rr_move(mapl, 'b');
        }
        p_move(mapl, 'a');
    }
}

void method_optib(mlist *mapl)
{
    if (mapl->b_size > 1)
    {
        if (mapl->lst_b[0] < mapl->lst_b[mapl->b_size - 1])
            r_move(mapl, 'b');
        else if (mapl->lst_b[0] < mapl->lst_b[1])
            s_move(mapl, 'b');
    }
}

void method_biga(mlist *mapl)
{
    int s;
    while (need_sort(mapl, 'a'))
    {
        s = mapl->a_size - mapl->b_size - 1;
        if (mapl->lst_a[0] > mapl->lst_a[s] && mapl->lst_a[0] < mapl->lst_a[1])
            rr_move(mapl, 'a');
        else if (mapl->lst_a[0] < mapl->lst_a[s] && mapl->lst_a[0] > mapl->lst_a[1])
            s_move(mapl, 'a');
        else if (mapl->lst_a[0] > mapl->lst_a[s] && mapl->lst_a[0] > mapl->lst_a[1])
        {
            if (mapl->lst_a[1] < mapl->lst_a[s])
                s_move(mapl, 'a');
            else
                rr_move(mapl, 'a');
        }
        p_move(mapl, 'b');
        //method_optib(mapl);

        if (s == 1)
        {
            if (mapl->lst_a[0] > mapl->lst_a[1])
                s_move(mapl, 'a');
        }
        else if (s == 2)
            method_a3(mapl);

        if (mapl->b_size == 3)
            method_b3(mapl);
        else if (mapl->b_size > 3)
            method_optib(mapl);

    }
    depil_treat(mapl);
}


/*
int max_num(mlist *mapl)
{
    int i;
    long long int n;

    i = 0;
    n = mapl->lst_a[0];
    while (i < (mapl->a_size - mapl->b_size))
    {
        if (mapl->lst_a[i] > n)
            n = mapl->lst_a[i];
        i++;
    }
    return (n);
}

void method_biga(mlist *mapl)
{
    int c;
    int i;
    int n;
    int max_bits = 0;

    c = 0;
    i = 0;
    while (need_sort(mapl, 'a'))
    {
        ++c;
        while (i < (mapl->a_size - mapl->b_size))
        {
            ++i;
            //n = max_num(mapl);
            n = mapl->lst_a[0];
            if ((n >> c) & 1)
                r_move(mapl, 'a');
            else
                p_move(mapl, 'b');
        }
        while (mapl->b_size > 0)
            p_move(mapl, 'a');
    }

    int size = a.size();
    int max_num = size - 1; // the biggest number in a is stack_size - 1
    int max_bits = 0; // how many bits for max_num
    while ((max_num >> max_bits) != 0) ++max_bits;
    for (int i = 0 ; i < max_bits ; ++i) // repeat for max_bits times
    {
        for(int j = 0 ; j < size ; ++j)
        {
            int num = a.top(); // top number of A
            if ((num >> i)&1 == 1) ra();
                // if the (i + 1)-th bit is 1, leave in stack a
            else pb();
            // otherwise push to stack b
        }
        // put into boxes done
        while (!b.empty()) pa(); // while stack b is not empty, do pa

        // connect numbers done
    }
}
*/


void check_smove(mlist *mapl, int *c)
{
    if (mapl->render[*c] == 1)
    {
        if (mapl->r_size > 1 && mapl->render[*c + 1] == 2)
        {
            ft_printf("ss\n");
            *c += 1;
        }
        else
            ft_printf("sa\n");
    }
    else if (mapl->render[*c] == 2)
    {
        if (mapl->r_size > 1 && mapl->render[*c + 1] == 1)
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
        if (mapl->r_size > 1 && mapl->render[*c + 1] == 4)
        {
            ft_printf("rr\n");
            *c += 1;
        }
        else
            ft_printf("ra\n");
    }
    else if (mapl->render[*c] == 4)
    {
        if (mapl->r_size > 1 && mapl->render[*c + 1] == 3)
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
        if (mapl->r_size > 1 && mapl->render[*c + 1] == 6)
        {
            ft_printf("rrr\n");
            *c += 1;
        }
        else
            ft_printf("rra\n");
    }
    else if (mapl->render[*c] == 6)
    {
        if (mapl->r_size > 1 && mapl->render[*c + 1] == 5)
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

void list_treat(mlist *mapl)
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
    mapl->render = malloc(sizeof(int) * 511501);
    mapl->lst_b = malloc(sizeof(long long int) *  mapl->a_size);
    if (!mapl->lst_b || !mapl->render)
        return ;
    mapl->r_size = 0;
    if (mapl->a_size == 3)
        method_a3(mapl);
    else if (mapl->a_size > 3)
        method_biga(mapl);
    free(mapl->lst_b);
    list_render(mapl);
    free(mapl->render);
}

int main (int ac, char **av)
{
    mlist mapl;

    if (ac < 2)
        return (1);
    mapl.a_size = 0;
    if (!check_sarg(av[1], &mapl))
        return (1);
    list_treat(&mapl);


    /*
    int i = 0;
    if (mapl.lst_a)
    {
        while (i < mapl.a_size)
        {
            ft_printf("%d\n", mapl.lst_a[i]);
            i++;
        }
    }
     */



    free(mapl.lst_a);
    return (0);
}
