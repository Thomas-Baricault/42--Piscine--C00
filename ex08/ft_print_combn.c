/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:26:20 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/05 10:52:30 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	char	tab[10];
	int		i;
	int		j;
	int		valid;

	if (n <= 0 || n >= 10)
		return ;
	i = -1;
	while (++i < n)
		tab[i] = '0' + i;
	valid = 1;
	while (valid)
	{
		write(1, tab, n);
		i = n - 1;
		while (i > 0 && tab[i] >= '9' - (n - i) + 1)
			i--;
		tab[i]++;
		while (++i < n)
			tab[i] = tab[i - 1] + 1;
		valid = tab[0] != '9' - n + 2;
		if (valid)
			write(1, ", ", 2);
	}
	return ;
}
