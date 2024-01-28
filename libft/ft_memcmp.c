/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:47:58 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/29 16:03:29 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	a = s1;
	b = s2;
	i = 0;
	while (i < n)
	{
		if (a[i] - b[i] > 0)
			return (a[i] - b[i]);
		if (a[i] - b[i] < 0)
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int	test1;
	int test2;

	test1 = ft_memcmp("Hezlo", "Helo", 3);
	test2 = memcmp("Hezlo", "Helo", 3);
	printf("%d\n", test1);
	printf("%d\n", test2);
	return (0);
}
*/
