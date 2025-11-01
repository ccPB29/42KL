#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int ft_isalpha(int c);
int isdigit(int c);
int isalnum(int c);
int isascii(int c);
int isprint(int c);
size_t strlen(const char *s);
void *memset(void *s, int c, size_t n);
void bzero(void *s, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
size_t	strlcpy(char *dst, const char *src, size_t size);
size_t	strlcat(char *dst, const char *src, size_t size);
int toupper(int c);
int tolower(int c);
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
int strncmp(const char *s1, const char *s2, size_t n);
void *memchr(const void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
char *	strnstr(const char *big, const char *little, size_t len);
int atoi(const char *nptr);

#endif