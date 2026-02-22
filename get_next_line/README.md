*This project has been created as part of the 42 curriculum by luli2*

# Description
**get_next_line** Returns one line per call. Returns the read line, or NULL on EOF (End of File) or error.

# Instruction

## `read(A, B, C)`
* **Behavior**: Reads `C` bytes from file descriptor `A` into buffer `B`.
* **Returns**: 
    * `> 0`: The actual number of bytes read.
    * `== 0`: End of File (EOF), nothing more to read.
    * `-1`: Error occurred.
* **Internal Offset**: The OS kernel automatically creates an open file description (struct) to track the current offset position. The next `read()` will naturally continue from where the last one left off. You can use `lseek()` to manually change this offset (though not allowed in GNL).

## Static Variables
* **Lifespan**: Survives from the start of the program until the program terminates.
* **Scope**: Can only be accessed and modified by the function that defines it.

## Reading Logic based on `BUFFER_SIZE` (BS)
* If there is no `\n` in the read buffer: Continue reading.
* If there is 1 `\n` in the buffer: Output the line and update the static storage.
* If there are multiple `\n`s in the buffer: Output the first line, keep the rest in storage, and continue outputting line by line on subsequent calls until none are left.
* If there is nothing left to read (EOF): Output the remaining content in the storage, and update the storage to `NULL`.
* If the storage is `NULL` (and nothing is read): Return `NULL`.

---

## Architecture Flow

### `get_next_line`
1.  Check if `fd` and `BUFFER_SIZE` are valid.
2.  Read from the file and append to the static storage (`read_a_save`).
3.  If the storage is `NULL` after reading, return `NULL`.
4.  Extract and return the valid line (`extract_line`), then update the static storage for the next call (`new_savestr`).

### `read_a_save`
* Checks if `\n` is already present in the static storage. If yes, it skips reading.
* If no `\n` is found, it reads from the file until a `\n` or EOF is encountered, appending the newly read data to the static storage.
* Returns the updated static storage (the pending buffer).

### `extract_line`
* Extracts the exact line to be returned to the user, stopping right after the `\n` or at EOF.

### `new_savestr`
* If there is no `\n` in the current storage, it frees the storage and returns `NULL`.
* If a `\n` exists, it duplicates the content *after* the `\n` into a newly allocated string, frees the old storage, and returns the new string.

---

## Utility Functions (`utils`)
* **`ft_strlen`**: Calculates the length of a string.
* **`ft_strchr`**: Checks if a string contains a specific character (e.g., `\n`).
* **`ft_strjoin`**: Concatenates two strings together and automatically frees the old static storage to prevent memory leaks.


# Resources
AI for explain Static Variable and offer test example.



<!--
read(A,B,C)
    在A里读C个进B，返回>0实际读数 ==0无可读 -1error
    有内置偏移量，系统内核自动创建文件描述结构体记录当前偏移位置，下一次接着上次读。lseek()手动更改偏移量。
静态变量
    从程序启动存活至程序结束。只有定义它的函数能调用。

读给定BUFFER_SIZE：
    当BS内没有\n，继续读。
    当BS内有1个\n，输出行，更新存储。
    当BS内有多个\n，输出行，持续输出直至没有。
    当BS内无内容，输出剩余存储，并更新为null。
    当存储为null，输出null。


get_next_line
    1.fd和BS合法
    2.读取拼接缓存（read_a_save）
    2.缓存为null返回null
    3.返回line(extract_line), 更新缓存(new_savestr)

read_a_save
    判断缓存中有没有\n，有的话不读不更新。没有的话读到有\n或末尾为止并拼接。返回为待执行缓存。
extract_line
    仅提取line，提到\n或结束
new_savestr
    如果没有\n直接变null. 有\n则存储\n后的内容，并free待执行缓存

ft_strlen
    字符串长度
ft_strchr
    字符串是否含\n
ft_strjoin
    拼接并free旧缓存

-->