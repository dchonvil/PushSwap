/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 00:42:59 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/01 00:43:01 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "pushswap.h"
#include "ft_printf.h"

int digit_check(char **av, mlist *mapl)
{
    int i;

    i = 0;
    while (av[mapl->a_size])
    {
        while (av[mapl->a_size][i])
        {
            if ((!ft_isdigit(av[mapl->a_size][i]) && av[mapl->a_size][i] != '-')
                || (av[mapl->a_size][i] == '-'
                    && !ft_isdigit(av[mapl->a_size][i + 1])))
            {
                ft_putstr_fd("Error\n", 2);
                ft_printf("%s\n", IS_NOT_NUM);
                return (0);
            }
            i++;
        }
        i = 0;
        mapl->a_size += 1;
    }
    return (1);
}

int val_check(char **av, long long int *box)
{
    int c;
    int i;

    c = 0;
    i = 0;
    while (av[c])
    {
        if (ft_strlen(av[c]) > 11 || (long long int)ft_atoi(av[c]) > 2147483647
            || (long long int)ft_atoi(av[c]) < -2147483647)
        {
            ft_putstr_fd("Error\n", 2);
            ft_printf("%s\n", IS_NOT_INT);
            return (0);
        }
        box[i] = (long long int)ft_atoi(av[c]);
        c++;
        i++;
    }
    return (1);
}

int duplic_check(long long int *box, int size)
{
    int c;
    int i;

    c = 0;
    i = size - 1;
    while (c < size)
    {
        while (i > c)
        {
            if (box[c] == box[i])
            {
                ft_putstr_fd("Error\n", 2);
                ft_printf("%s\n", IS_DUPLICATE);
                return (0);
            }
            i--;
        }
        i = size - 1;
        c++;
    }
    return (1);
}

int check_sarg(char *av, mlist *mapl)
{
    char **tab;

    tab = ft_split(av, ' ');
    if (!tab)
        return (0);
    if (!digit_check(tab, mapl))
    {
        free_tab((void **)tab);
        return (0);
    }
    mapl->lst_a = malloc(sizeof(long long int) * mapl->a_size);
    if (!mapl->lst_a)
    {
        free_tab((void **)tab);
        return (0);
    }
    if (!val_check(tab, mapl->lst_a))
    {
        free(mapl->lst_a);
        free_tab((void **)tab);
        return (0);
    }
    if (!duplic_check(mapl->lst_a, mapl->a_size))
    {
        free(mapl->lst_a);
        free_tab((void **)tab);
        return (0);
    }
    free_tab((void **)tab);
    return (1);
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