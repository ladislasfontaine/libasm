/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lafontai <lafontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 08:52:40 by lafontai          #+#    #+#             */
/*   Updated: 2020/05/29 14:09:15 by lafontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char    *ft_strdup(const char *s1);

// vérifier la variable errno contient bien l'erreur

int     main(void)
{
	char    dest[10] = "bonjour!!";

	printf("Result strcmp: %d\n", ft_strcmp("bondour", "bonjour"));
	printf("Result: %s\n", ft_strcpy(dest, "salut"));
	printf("Result: %zu\n", ft_write(1, "hello\n", 6));
	printf("Result: %zu\n", ft_strlen("bonjour!"));
	return (0);
}