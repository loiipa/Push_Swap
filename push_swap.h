/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:43:06 by cjang             #+#    #+#             */
/*   Updated: 2021/09/26 21:29:24 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef ORDER_SIZE
#  define ORDER_SIZE 5
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef MIN_OF_INT
#  define MIN_OF_INT -2147483648
# endif

# ifndef MAX_OF_INT
#  define MAX_OF_INT 2147483647
# endif

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_circular_doubly_linked_list
{
	int										content;
	struct s_circular_doubly_linked_list	*prev;
	struct s_circular_doubly_linked_list	*next;
}											t_cd_list;

t_cd_list	*ft_cdlst_new(int content);
void		ft_cdlst_del_all(t_cd_list **lst);
void		ft_cdlst_add(t_cd_list **lst, t_cd_list *new);
t_cd_list	*ft_cdlist_cuttop(t_cd_list **lst);
int			ft_cdlist_len(t_cd_list *lst);

void		make_stack(int argc, char **argv, t_cd_list **lst_a);

void		push_swap_order(char *s, t_cd_list **lst_a, t_cd_list **lst_b);
void		checker_order(char *s, t_cd_list **lst_a, t_cd_list **lst_b);

void		ft_swap(t_cd_list **lst);
void		ft_push(t_cd_list **lst_1, t_cd_list **lst_2);
void		ft_rotate(t_cd_list **lst, char *s);

void		quick_sort(t_cd_list **lst_a, t_cd_list **lst_b, int len, int loc);
void		quick_sort_move(t_cd_list **lst_a, t_cd_list **lst_b, \
			int len, int loc);
void		quick_sort_move_half(t_cd_list **lst_a, t_cd_list **lst_b, \
			int len, int loc);

int			is_range_of_int(char *str);
int			check_str_num(char *s);
int			check_sort(t_cd_list *lst);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_issign(int c);
void		free_book(char **book, size_t index);
void		exit_message(char *s, int i);

int			ft_ischar(char *s, char c);
int			tok_line_back(char *s, char **next, char tok);

void		sort_three(t_cd_list **lst_a, t_cd_list **lst_b, int loc);

int			find_max_num(t_cd_list *lst, int len);
int			find_min_num(t_cd_list *lst, int len);
int			find_prev_num(t_cd_list *lst, int len, int num);
int			find_next_num(t_cd_list *lst, int len, int num);
int			find_half_num(t_cd_list *lst, int len);
int			find_onethird_num(t_cd_list *lst, int len);
int			find_twothird_num(t_cd_list *lst, int len);
#endif
