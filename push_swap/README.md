*This project has been created as part of the 42 curriculum by <luli2>.*

# Description

## Goal
Sort a stack using the allowed operations while minimizing the total number of instructions.

## Overview

1. Implement the stack data structure and related stack functions.
2. Implement all required stack operations.
3. Validate the input by rejecting non-integer values, overflow values, and duplicates.
4. Sort the generated stack:
   - Assign an index to each value according to its sorted order.
   - Apply Binary Radix Sort:
     - If the current bit is `0`, execute `pb`.
     - If the current bit is `1`, execute `ra`.
     - After scanning all elements, move everything back using `pa`.

# Instructions

Compile the project:

```bash
make
```

Test correctness:

```bash
ARG=$(shuf -i 0-999 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

Performance tester:

```bash
git clone https://github.com/lmalki-h/push_swap_tester.git
cd push_swap_tester

bash tester.sh .. 100 100 --score
bash tester.sh .. 500 100 --score
```

# Resources

## AI Usage

AI was used for:

- Understanding the stack data structure.
- Breaking the project into smaller implementation steps.
- Writing testing programs.
- Learning common sorting algorithms.

## Sorting Algorithms

**Bubble Sort**

Repeatedly compares adjacent elements and swaps them if they are in the wrong order.

- Time Complexity: **O(n²)**
- Suitable for very small datasets.

**Selection Sort**

Repeatedly selects the smallest element and places it at the beginning.

- Time Complexity: **O(n²)**
- Suitable for very small datasets.

**Insertion Sort**

Inserts each element into its correct position by shifting larger elements to the right.

- Time Complexity: **O(n) ~ O(n²)**
- Efficient for nearly sorted data.

**Merge Sort**

Recursively splits the data until each group contains one element, then merges them back together.

- Time Complexity: **O(n log n)**
- Well suited for linked lists.

**Quick Sort**

Chooses a pivot and partitions elements into smaller and larger groups.

- Time Complexity:
  - Average: **O(n log n)**
  - Worst: **O(n²)**

**Heap Sort**

Builds a heap, then repeatedly extracts the maximum (or minimum).

- Time Complexity: **O(n log n)**
- Useful when repeatedly retrieving the largest or smallest element.

**Radix Sort**

Sorts integers digit by digit.

- Time Complexity: **O(d × n)**

## Why Linked Lists?

Stacks A and B could also be implemented using arrays.

However, arrays require shifting elements after every push and pop operation.

Using linked lists avoids these unnecessary memory movements.

## Why Binary Radix Sort?

Traditional radix sort distributes elements into ten buckets (0–9).

In this project, only two stacks are available, making Binary Radix Sort a natural fit by classifying elements according to binary digits:

- bit = 0 → `pb`
- bit = 1 → `ra`

After processing all elements of the current bit, every element is moved back with `pa`.

The main reason for choosing Radix Sort is the restriction imposed by the available stack operations. Although other algorithms can also work under these constraints, Binary Radix Sort matches the push_swap instruction set particularly well and requires only a few operations (`pa`, `pb`, and `ra`) for the main sorting process.

## Why Use Indexes?

Initially I considered sorting signed integers directly by flipping the sign bit using XOR.

However, this requires processing all 32 bits, resulting in many unnecessary iterations.

Using indexes compresses the values into the range `[0, n-1]`, greatly reducing the number of sorting passes.

### XOR Example

Original representation (8-bit):

```text
-2 = 11111110
-1 = 11111111
 0 = 00000000
 1 = 00000001
 2 = 00000010
```

After flipping the highest bit:

```text
-2 -> 01111110
-1 -> 01111111
 0 -> 10000000
 1 -> 10000001
 2 -> 10000010
```

This preserves the relative ordering when treated as unsigned integers, but still requires iterating through all 32 bits. Therefore, using indexes is more efficient for this project.

# Description
## 目标：
通过指令完成栈的排序，且目标为指令使用次数最少
## 概述：
1.搭建栈数据结构，存储栈的函数
2.编写指令函数
3.接收合法输入，排除非int或重复
4.对接收生成的栈进行排序：
	先进行index
	通过Radix比较二进制位数，位0的pb，位1的ra,读完再pa回。

# Instruction
make生成可执行文件。

ARG=$(shuf -i 0-999 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l

git clone https://github.com/lmalki-h/push_swap_tester.git
cd push_swap_tester
bash push_swap_tester/tester.sh . 100 100 --score
bash push_swap_tester/tester.sh . 500 100 --score

# Resources
AI used: 了解栈结构概念。拆分项目思路，编写测试程序。了解排序算法。

冒泡排序：不断比较相邻两个元素，如果顺序错了就交换。O(n²)。小数据。
选择排序：每次找最小值，放到前面。O(n²)。小数据。
插入排序：右侧比较后移。n-n²。基本有序的数据。
归并排序：一直拆到每组1个数，然后开始归并。适合链表。nlogn。
快速排序：随机选中一个数，小的放左大的放右。nlogn-n²。
堆排序：建堆n * 取最大值logn。当需要持续取最大/小值
基数排序：整数只需要n。d*n

因为要使用指定操作，栈A栈B也可以用数组，但是要不停移动。链表只是省去了移动的步骤。
Radix可以理解为按位分类，正常0-9 10个类。我们有AB两个桶，刚好可以按二进制的01去分。
选择Radix的主要原因还是题目的操作限制（在这种限制下不去考虑归并之类的，当然操作限制下也有其他算法），radix要求保持桶里的先进先出，总之和这些操作及题目要求是完美契合的。（几乎papb就够了）

处理负数本想异或，但是会固定做32位消耗大量无意义次数。做index
关于异或：
-2 = 11111110
-1 = 11111111
 0 = 00000000
 1 = 00000001
 2 = 00000010

翻转最高位：
-2 -> 01111110
-1 -> 01111111
 0 -> 10000000
 1 -> 10000001
 2 -> 10000010