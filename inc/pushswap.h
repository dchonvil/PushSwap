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

# define SPLIT "The list is empty or null."
# define IS_NOT_NUM "One of arguments is not a number."
# define IS_NOT_INT "One of arguments is not a simple integer."
# define IS_DUPLICATE "There is a duplicate in the argument list."
# define ALLOCATION "The program could not allocate the necessary memory."

typedef struct s_mlist
{
    int a_size;
    int b_size;
    int r_size;
    int *render;
    long long int *lst_a;
    long long int *lst_b;
    long long int *lst_c;
} mlist;

void ft_puterr(char *err);
void free_tab(char **tab);
void good_end(mlist *mapl);
void simp_lst(mlist *mapl);
void method_a3(mlist *mapl);
void method_b3(mlist *mapl);
void list_render(mlist *mapl);
void method_biga(mlist *mapl);
int check_render(mlist *mapl);
void method_sobiga(mlist *mapl);
void s_move(mlist *mapl, char name);
void r_move(mlist *mapl, char name);
void rr_move(mlist *mapl, char name);
void p_move(mlist *mapl, char name);
int check_sarg(char *av, mlist *mapl);
int need_sort(mlist *mapl, char name);
void check_smove(mlist *mapl, int *c);
void check_rmove(mlist *mapl, int *c);
void check_rrmove(mlist *mapl, int *c);
void ft_sort_linttab(long long int *tab, int size);
void depil_treat(mlist *mapl, long long int chk, int m);
void ft_lintcpy(long long int *dest, long long int *src, int n);

#endif