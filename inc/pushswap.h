/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 03:07:00 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/30 03:08:39 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSHSWAP_H
# define PUSHSWAP_H

# define IS_NOT_NUM "One of arguments is not a number."
# define IS_NOT_INT "One of arguments is not a simple integer."
# define IS_DUPLICATE "There is a duplicate in the argument list."

typedef struct s_mlist
{
    int a_size;
    int b_size;
    int r_size;
    int *render;
    long long int *lst_a;
    long long int *lst_b;
} mlist;

void free_tab(void **tab);
int check_sarg(char *av, mlist *mapl);
int need_sort(mlist *mapl, char name);
void ft_lintcpy(long long int *dest, long long int *src, int n);





void s_move(mlist *mapl, char name);
void r_move(mlist *mapl, char name);
void rr_move(mlist *mapl, char name);
void p_move(mlist *mapl, char name);

#endif