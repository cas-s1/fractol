/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:30:29 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/26 20:16:22 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;
	unsigned char		uc;
	size_t				i;

	uc = (unsigned char) c;
	a = s;
	i = 0;
	while (i < n)
	{
		if (a[i] == uc)
			return ((void *) &a[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	teststr[] = "aaaaaaaaaaaaaabaaaa";
	char	*ptr;

	ptr = ft_memchr(teststr, 98, 20);
	if (ptr)
		printf("%s\n", ptr);
	return (0);
}
*/
