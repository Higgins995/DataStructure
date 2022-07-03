## 单链表

### 本程序的文件结构

+ 头文件:

  - `LinkList.h` : 链表头文件，提供了链表的类型定义和相关接口说明.

- 源文件:
  - `LinkList.c` : 链表接口的具体实现文件.
  - `main.c` : 主函数，对链表接口进行测试，因此需要包含 *LinkList.h* .
  
- 自动化编译文件:
  - `Makefile` : 生成可执行文件 *main.exe* 

### 延伸拓展

1. `void insertPost_Link_value(PNode head, int finddata, int insertdata)` : 在链表 head 中值为 finddata 的元素的后面插入一个新的值为 insertdata 的结点.
2. `void delValue_Link_All(PNode head, int x)` : 删除单链表中所有值为 x 的元素.
3. `void delValue_Link_j_k(PNode head, int j, int k)` : 删除单链表中从第 j 个元素开始的连续 k 个元素.
4. `DataType search_Mid(PNode head)` : 以链表中的某个元素 x 对链表进行划分，将单链表以 x 为分割点进行划分，比 x 小的在 x 的前面，比 x 大的在 x 的后面.



> 疑惑：
>
> 1. 对于 `locate_Link()` 函数, 返回的只是单链表中第一个值为 x 的内存地址, 如果存在多个 x 怎么办?    **我暂时写成: 只查找第一个值为 x 的内存地址.** 
> 2. 对于拓展部分的 `insertPost_Link_Value()` 函数, 是想在第一个值为 finddata 的结点后插入 insertdata 值, 还是在所有值为 finddata 的结点后都插入 insertdata 值?    **我暂时写成: 在所有值为 finddata 的结点后都插入 insertdata 值.** 



### 测试用例及运行结果

1. 头插法测试结果

![image-20220702105033380](https://cdn.jsdelivr.net/gh/Higgins995/The-Photos-of-Blog//DataStructure/LinkList_01.png) 

2. 尾插法测试结果

![image-20220702105053752](https://cdn.jsdelivr.net/gh/Higgins995/The-Photos-of-Blog//DataStructure/LinkList_02.png) 

3. 延伸拓展测试结果

![](https://raw.githubusercontent.com/Higgins995/The-Photos-of-Blog/master/DataStructure/LinkList_03.png))