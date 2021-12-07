/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 08:20:36 by dchonvil          #+#    #+#             */
/*   Updated: 2021/12/04 08:20:41 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void free_tab(void **tab)
{
    int c;

    c = 0;
    while (tab[c])
    {
        free(tab[c]);
        c++;
    }
    free(tab);
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

