/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:43:37 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/18 01:43:40 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "pushswap.h"
#include "ft_printf.h"

void ft_puterr(char *err)
{
    ft_putstr_fd("Error\n", 2);
    ft_printf("%s\n", err);
}

void free_tab(char **tab)
{
    int c;

    c = 0;
    while (tab[c] != NULL)
    {
        free(tab[c]);
        c++;
    }
    free(tab);
}

void simp_lst(mlist *mapl)
{
    int c;
    int i;

    c = 0;
    while (c < (mapl->a_size - mapl->b_size))
    {
        i = 0;
        while (i < (mapl->a_size - mapl->b_size))
        {
            if (mapl->lst_a[c] == mapl->lst_c[i])
                mapl->lst_a[c] = i;
            i++;
        }
        c++;
    }
}

void ft_lintcpy(long long int *dest, long long int *src, int n)
{
    int			i;

    i = 0;
    if (!n || dest == src)
        return ;
    while (n--)
    {
        dest[i] = src[i];
        i++;
    }
}

void ft_sort_linttab(long long int *tab, int size)
{
    int		i;
    int		j;
    long long int	temp;

    j = 0;
    while (!(j))
    {
        i = 0;
        j = 1;
        while (i < (size - 1))
        {
            ++i;
            if (tab[i - 1] > tab[i])
            {
                temp = tab[i - 1];
                tab[i - 1] = tab[i];
                tab[i] = temp;
                j = 0;
            }
        }
    }
}
