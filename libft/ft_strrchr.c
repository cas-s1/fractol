/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:24:09 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/26 21:45:06 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	size_t			i;

	uc = c;
	i = ft_strlen(s);
	while (i > 0 && s[i] != uc)
		i--;
	if (s[i] == uc)
		return ((char *) &s[i]);
	return (0);
}
/*
int	main(void)
{
	char	teststr[] = "baaaaaaaaaaaaaaaaaa";
	char	*ptr;

	ptr = ft_strrchr(teststr, 98);
	if (ptr)
		printf("%s\n", ptr);
	return (0);
}
*/
