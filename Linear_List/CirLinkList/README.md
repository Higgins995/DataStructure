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

1. `DataType search_Mid(PNode head)` : 输出单循环链有序链表的中位元素.
2. `void combine(PNode head1, PNode head2)` : 合并两个有序链表, 一个递增, 一个递减, 并要求在创建链表时用户可乱序输入数据. *head1 递增, head2 递减* .

### 测试用例及结果

1. 基础部分
2. 延伸拓展部分