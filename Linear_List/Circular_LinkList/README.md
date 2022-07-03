## 循环链表

### 本程序的文件结构

- 头文件:
  - `DeduplicateLinkList.h` : 链表头文件, 提供了链表类型定义和相关接口说明.

- 源文件:
  - `DeduplicateLinkList.c` : 链表接口的具体实现文件.
  - `main.c` :  主函数, 调用合并两个单循环有序链表的算法, 因此需要包含 *DeduplicateLinkList.h* .
- 自动化编译文件:
  - `Makefile` : 生成可执行文件 *main.exe* .

### 延伸拓展

实现两个函数:

1. `DataType search_Mid(LinkList head)` : 
2. `void combine(LinkList head1, LinkList head2)` : 