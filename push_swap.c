/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 22:23:32 by cjang             #+#    #+#             */
/*   Updated: 2021/08/24 00:14:44 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			i;
	t_cd_list	*lst_top_a;
	t_cd_list	*lst_top_b;

	i = 0;
	if (argc < 2)
		return (1);
	make_stack(argc, argv, &lst_top_a);
	if (check_sort(lst_top_a) == 0)
		quick_sort(&lst_top_a, &lst_top_b, ft_cdlist_len(lst_top_a), 4);
	ft_cdlst_del_all(&lst_top_a);
	ft_cdlst_del_all(&lst_top_b);
}
