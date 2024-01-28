/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:00:46 by co-neill          #+#    #+#             */
/*   Updated: 2023/03/27 15:11:18 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *) str);
	i = 0;
	j = 0;
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && i + j < n)
			{
				if (to_find[j + 1] == '\0')
					return ((char *) str + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
/*.
int main()
{
	char test1[] = "Hello goodbye";
	char test2[] = "goodby";

	printf("%s\n", ft_strnstr(test1, test2, 10)); 
	Segfaults are caused not by strnstr but by printf attempting to return
	a null pointer to the string format specifier in certain cases.
	return (0);
}
*/
