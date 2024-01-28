/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:02:35 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/26 22:01:42 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			i;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (us1[i] != us2[i] || !(us1[i]))
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int	test1;
	int test2;

	test1 = ft_strncmp("Hello", "Helo", 4);
	test2 = strncmp("Hello", "Helo", 4);
	printf("%d\n", test1);
	printf("%d\n", test2);
	return (0);
}
*/
