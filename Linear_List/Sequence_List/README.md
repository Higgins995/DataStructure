## 顺序表

### 本程序的文件结构

- 头文件

  - `SeqList.h` :顺序表头文件，提供了顺序表类型定义和相关接口说明.

- 源文件
  - `main.c` :顺序表接口的具体实现文件.
  - `SeqList.c` :主函数，对顺序表接口进行测试，因此需要包含 ==SeqList.h== 

 

### 延伸拓展

实现三个函数: 

1. `int delV_Seq(SeqList slist, int x)` : 删除顺序表中第一个值为 x 的元素，成功返回 1，否则返回 0.
2. `int delA_Seq(SeqList slist, int x)` : 删除顺序表中所有值为 x 的元素，成功返回 1，否则返回 0.
3. `void delete_j_k(SeqList slist, int j, int k)` : 删除顺序表中从第 j 个元素开始连续的 k 个元素.



### 测试用例及结果

![image-20220701213455928](C:\Users\韦宇敬\AppData\Roaming\Typora\typora-user-images\image-20220701213455928.png) 