/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lafontai <lafontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:00:08 by lafontai          #+#    #+#             */
/*   Updated: 2020/06/02 15:28:34 by lafontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

#define CGREEN "\033[32m"
#define CRED "\033[31m"
#define CCOLOR "\033[0m"
#define BUFFER_SIZE 4096

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char    *ft_strdup(const char *s1);

static void strlen_test(const char *s, const char *test)
{
    int     or;
    int     ft;

    or = strlen(s);
    ft = ft_strlen(s);
    if (or == ft)
        printf("%s :" CGREEN "[OK]\n" CCOLOR, test);
    else
        printf("%s :" CRED "[KO]\n" CCOLOR, test);
}

static void strcpy_test(const char *src, const char *test)
{
	char	dest1[BUFFER_SIZE];
	char	dest2[BUFFER_SIZE];

	bzero(dest1, BUFFER_SIZE);
	bzero(dest2, BUFFER_SIZE);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	if (!strcmp(dest1, dest2))
		printf("%s :" CGREEN "[OK]\n" CCOLOR, test);
	else
		printf("%s :" CRED "[KO]\n" CCOLOR, test);
}

static void strcmp_test(const char *s1, const char *s2, const char *test)
{
	int		or = strcmp(s1, s2);
	int		ft = ft_strcmp(s1, s2);

	if (ft == or)
		printf("%s :" CGREEN "[OK]\n" CCOLOR, test);
	else
		printf("%s :" CRED "[KO]\n" CCOLOR, test);
}

static void write_test(int fd, char *buf, size_t count, const char *test)
{
    int     or;
    int     ft;
    int		ft_err;
    int		or_err;

    or = write(fd, buf, count);
    or_err = errno;
    ft = ft_write(fd, buf, count);
    ft_err = errno;
    if (or == ft)
        printf("%s :" CGREEN "[OK]\n" CCOLOR, test);
    else
        printf("%s :" CRED "[KO]\n" CCOLOR, test);
    if (ft == -1 || or == -1)
    {
    	if (ft_err == or_err)
    		printf("ERRNO [FT:%d]||[OR:%d] : %s" CGREEN "[OK]\n" CCOLOR, ft_err, or_err, test);
    	else
    		printf("ERRNO [FT:%d]||[OR:%d] : %s" CGREEN "[KO]\n" CCOLOR, ft_err, or_err, test);
    }
}

static void read_test(int fd, size_t count, const char *test)
{
	int		or;
	int		ft;
	int		ft_err;
	int		or_err;
	char	buf1[BUFFER_SIZE];
	char	buf2[BUFFER_SIZE];

	bzero(buf1, BUFFER_SIZE);
	bzero(buf2, BUFFER_SIZE);
	or = read(fd, buf1, count);
	or_err = errno;
	ft = ft_read(fd, buf2, count);
	ft_err = errno;
	if (or == ft && strcmp(buf1, buf2) == 0)
        printf("%s :" CGREEN "[OK]\n" CCOLOR, test);
    else
        printf("%s :" CRED "[KO]\n" CCOLOR, test);
    if (ft == -1 || or == -1)
    {
    	if (ft_err == or_err)
    		printf("ERRNO [FT:%d]||[OR:%d] : %s" CGREEN "[OK]\n" CCOLOR, ft_err, or_err, test);
    	else
    		printf("ERRNO [FT:%d]||[OR:%d] : %s" CGREEN "[KO]\n" CCOLOR, ft_err, or_err, test);
    }
}

static void strdup_test(const char *src, const char *test)
{
	char	*str1;
	char	*str2;

	str1 = ft_strdup(src);
	str2 = strdup(src);
	if (!strcmp(str1, str2))
		printf("%s :" CGREEN "[OK]\n" CCOLOR, test);
	else
		printf("%s :" CRED "[KO]\n" CCOLOR, test);
	free(str1);
	free(str2);
}

int main(void)
{
    /* STRLEN TESTS */ 
    printf("FT_STRLEN TESTS :\n");
	strlen_test("Hello world", "basic1");
	strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate. In hac habitasse platea dictumst. In a nibh ", "long");
	strlen_test("", "empty");
	strlen_test("\n", "new line");
	strlen_test("\n\n", "new line2");
	strlen_test("111+}Te'st!wi/th*[<<As:c2ii3", "strange string");
    printf("-------------------------------------------------\n");
    
    /* STRCPY TESTS */ 
    printf("FT_STRCPY TESTS :\n");
    strcpy_test("Hello world", "basic1");
	strcpy_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate. In hac habitasse platea dictumst. In a nibh ", "long");
	strcpy_test("", "empty");
	strcpy_test("\n", "new line");
	strcpy_test("\n\n", "new line2");
	strcpy_test("111+}Te'st!wi/th*[<<As:c2ii3", "strange string");
	printf("-------------------------------------------------\n");

	/* FT_STRCMP TESTS */	
	printf("FT_STRCMP TESTS \n");
	strcmp_test("hello World", "hello World", "basic1");
	strcmp_test("hello World", "Hello World", "basic2");
	strcmp_test("hello World", "", "empty1");
	strcmp_test("", "", "empty2");
	strcmp_test("", "Hello world", "empty3");
	strcmp_test("", "\n", "new line 1");
	strcmp_test("\n", "Hello world", "new line 2");
	strcmp_test("\n", "\n", "new line 3");
	strcmp_test("111+}Te'st!wi/th*[<<As:c2ii3", "111+}Te'st!wi/th*[<<As:c2ii3" ,"strange strings");
	printf("-------------------------------------------------\n");
	
	/* FT_WRITE TESTS */
	printf("FT_WRITE TESTS \n");
	int		fd;

	fd = open("tests", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("open() error");
		return 1;
	}
	write_test(fd, "Hello_world\n", 12, "basic");
	write_test(-2, "Hello_world", 11, "bad fd");
	write_test(fd, NULL, 11, "NULL ptr");
	write_test(fd, "Hello_world", -2, "bad len");
	write_test(fd, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", 200, "long write");
	printf("-------------------------------------------------\n");
	/* FT_READ TESTS */
	printf("FT_READ TESTS \n");
	read_test(fd, 4, "basic");
	read_test(-2, 11, "bad fd");
	read_test(fd, 2000, "big read");
	read_test(fd, -2, "bad len");
	if (close(fd) == -1)
	{
		printf("close() error");
		return 1;
	}
	printf("-------------------------------------------------\n");
	/* FT_STRDUP TESTS */
	printf("FT_STRDUP TESTS \n");
	strdup_test("Hello world", "basic1");
	strdup_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate. In hac habitasse platea dictumst. In a nibh ", "long");
	strdup_test("", "empty");
	strdup_test("\n", "new line");
	strdup_test("\n\n", "new line2");
	strdup_test("111+}Te'st!wi/th*[<<As:c2ii3", "strange string");
	printf("-------------------------------------------------\n");
    return (0);
}