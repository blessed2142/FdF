/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:14:33 by rphoebe           #+#    #+#             */
/*   Updated: 2021/04/14 21:40:59 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

// int main()
// {
// 	char dst[10] = "0123456789";
// 	ft_memmove(&dst[4], &dst[3], 3);
// 	printf("%s\n", dst);
// 	// char dst1[10] = "1234567890";
// 	// memmove(&dst1[4], &dst1[3], 3);
// 	// printf("%s\n", dst1);
// 	return (0);
// }
