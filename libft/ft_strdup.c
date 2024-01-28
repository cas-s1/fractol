/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:56:59 by co-neill          #+#    #+#             */
/*   Updated: 2023/03/21 22:39:16 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		length;
	int		i;
	char	*dest;

	length = ft_strlen(s);
	dest = malloc(sizeof(char) * length + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	initialTestStr[] = "This is so epic";
	char	*copiedTestStr;

	copiedTestStr = ft_strdup(initialTestStr);
	printf("%s\n", initialTestStr);
	printf("%s\n", copiedTestStr);
	return (0);
}
*/
