/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: marlou <marlou@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 13:21:18 by marlou        #+#    #+#                 */
/*   Updated: 2022/11/28 17:43:15 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	dest = (malloc((srclen + 1) * sizeof(char)));
	if (dest)
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
