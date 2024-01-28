/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:52:29 by co-neill          #+#    #+#             */
/*   Updated: 2023/03/21 22:14:38 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		*p++ = 0;
		i++;
	}
}
/*
int	main(void)
{
	int	array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	ft_bzero(array, sizeof(array));
	i = 0;
	while (i < 10)
	{
		printf("%d ", array[i]);
		i++;
	}
	return (0);
}
*/
