/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:43:44 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/17 17:43:48 by dchonvil         ###   ########.fr       */
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

void checker_err(mlist *mapl, char **box)
{
    ft_putstr_fd("Error\n", 2);
    free_tab(box);
    good_end(mapl);
}

void check_intrp1(mlist *mapl, char **box, int c, int i)
{
    int chk;

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

void moves_intrp1(mlist *mapl, char **box, int c, int i)
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

void check_intrp2(mlist *mapl, char **box, int c, int i)
{
    int chk;

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

void moves_intrp2(mlist *mapl, char **box, int c, int i)
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

int checker_check(mlist *mapl, char **box)
{
    int c;
    int i;

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

void list_init(mlist *mapl)
{
    int c;
    int i;
    char **box;

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
    free_tab(box);
    free(mapl->lst_b);
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
    list_init(&mapl);
    free(mapl.lst_a);
    return (0);
}
