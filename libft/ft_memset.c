/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:23:55 by co-neill          #+#    #+#             */
/*   Updated: 2023/03/21 21:44:46 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*x;
	size_t			i;

	x = s;
	i = 0;
	while (i < n)
	{
		*x++ = (unsigned char) c;
		i++;
	}
	return (s);
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
	ft_memset(array, 9, sizeof(array));
	i = 0;
	while (i < 10)
	{
		printf("%d ", array[i]);
		i++;
	}
	return (0);
}
*/
