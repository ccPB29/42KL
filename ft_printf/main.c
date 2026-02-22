// cc main.c -L. -lftprintf -o test
#include <stdio.h>    // 用于标准 printf
#include "ft_printf.h" // 替换为你的 ft_printf 头文件路径
#include <limits.h>

int main(void) {
    int ft_len, std_len;
    void *ptr = (void *)0x12345678;

    ft_len = ft_printf("%c%s%p%d%i%u%x%X%%", 'A', "42", ptr, 42, -42, 42, 42, 42);
    std_len = printf("%c%s%p%d%i%u%x%X%%", 'A', "42", ptr, 42, -42, 42, 42, 42);
    printf("ft_len = %d, std_len = %d\n\n", ft_len, std_len);

// " %p %p", 0, 0
// "%c%s%p%d%i%u%x%X%%", 'A', "42", ptr, 42, -42, 42, 42, 42

}