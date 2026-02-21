*This project has been created as part of the 42 curriculum by luli2*

# Description
**ft_printf** The goal is to recode the printf function from the C standard library.

# Instruction

* **`va_list A`**: Declare cursor.
* **`va_start(A, B)`**: `A` points to the next argument after `B`.
* **`va_arg(A, type)`**: Retrieve what `A` points to in the format of `type`, return it, and advance `A` to the next.
* **`va_end(A)`**: Destroy `A`.


```c
typedef struct {
    unsigned int gp_offset;       // offset for general-purpose registers
    unsigned int fp_offset;       // offset for floating-point registers
    void *overflow_arg_area;      // pointer to overflow arguments on the stack (arguments that do not fit in registers)
    void *reg_save_area;          // pointer to the register save area (arguments secretly saved by the compiler)
} va_list[1];
Requires register information, hence it can only point to variadic arguments
```
##
**ft_printf.c**
Iterate through format. When reading '%', move one position back to the specifier, (handle) print the argument, and increase the return length by the argument's length. Destroy the va_list object when the string ends.

handle: call different printing functions based on the object type**
* **c**: putchar if null it is '\0', write a single character
* **s**: putstr if it is a null string print (null)
* **p**: pointer if null print (nil), else print 0x + (long)putthex in hexadecimal
* **d|i**: putnbr if null print 0
* **u**: putusnbr same as nbr because two's complement doesn't need sign handling, write returns the number of written bytes, return value accumulates i at each level
* **x|X**: putthex second argument controls case, same as base 10 / 10 putchar outputs corresponding character in base[], return value accumulates count at each level
* **%**: directly write %
##
makefile:

	$(CC) $(CFLAGS) -c $< -o $@ -I$(includes)

-c: Tell the compiler to "compile only, do not link", generating the object file (.o).

$<: Represents the first prerequisite (i.e., the corresponding .c file).

$@: Represents the target (i.e., the corresponding .o file).

-I$(includes): Tell the compiler where to find header files.

    ar rcs $@ $^

ar: The exclusive command for archiving static libraries (Archive).

rcs: r (replace old files) c (create library) s (generate index to speed up linking).

$@: Represents the target, which is libftprintf.a.

$^: Represents all prerequisites (i.e., the space-separated list of all .o files).

# Resources
AI for explain Variadic function and offer test example.



<!--
va_list A 声明游标
va_start(A,B) A指向B的下一个
va_arg(A,B) 以B的格式取A所指并返回，并将A指向下一个
va_end（A）销毁A

typedef struct {
    unsigned int gp_offset;       // 通用寄存器的偏移量
    unsigned int fp_offset;       // 浮点寄存器的偏移量
    void *overflow_arg_area;      // 指向栈上溢出参数的指针（寄存器装不下的参数）
    void *reg_save_area;          // 指向寄存器保存区域的指针（编译器偷偷存下来的参数）
} va_list[1];
需要寄存器信息，因此只能指向可变参数

ft_printf.c
	遍历format，当读到%时，后移一位至标识符，（handle）打印参数，返回长度增加参数长度。字符串结束后销毁va_list对象。
	handle：根据对象类型调用不同打印函数
c putchar 空为‘\0’，write单个字符
s putstr 如果是空字符串打印(null)
p pointer 空打(nil)，打0x+(long)putthex十六进制
d|i putnbr 空打0
u putusnbr 同nbr因为补码不用处理符号，write返回写入字数，返回值为每层累加i
x|X putthex 第二位参数控制大小写， 同10进制/10putchar输出base[]对应字符，返回值每层累加count
% 直写%

makefile:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(includes)

-c: 告诉编译器“只编译，不链接”，生成目标文件（.o）。

$<: 代表第一个依赖项（也就是对应的 .c 文件）。

$@: 代表目标项（也就是对应的 .o 文件）。

-I$(includes): 告诉编译器去哪里找头文件。

	ar rcs $@ $^

ar: 打包静态库的专属命令（Archive）。

rcs: r(替换旧文件) c(创建库) s(生成索引以加快链接速度)。

$@: 代表目标，也就是 libftprintf.a。

$^: 代表所有的依赖项（也就是所有的 .o 文件空格隔开的列表）。

-->