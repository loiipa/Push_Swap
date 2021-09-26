/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_num_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:53:00 by cjang             #+#    #+#             */
/*   Updated: 2021/08/19 23:27:22 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_onethird_num(t_cd_list *lst, int len)
{
	int			num;
	int			i;

	if (!lst)
		exit_message("find_onethird_num error", 1);
	num = find_min_num(lst, len);
	i = 1;
	while (i < len / 3)
	{
		num = find_next_num(lst, len, num);
		i++;
	}
	return (num);
}

int	find_twothird_num(t_cd_list *lst, int len)
{
	int			num;
	int			i;

	if (!lst)
		exit_message("find_twothird_num error", 1);
	num = find_max_num(lst, len);
	i = 1;
	while (i < (len + 2) / 3)
	{
		num = find_prev_num(lst, len, num);
		i++;
	}
	return (num);
}
