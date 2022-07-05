#ifndef CIRLINKLIST_H
#define CIRLINKLIST_H

typedef int DataType;

struct Node {
	DataType data;
	struct Node* next;
};

typedef struct Node Node;
typedef struct Node* PNode;

// 函数功能: 创建一个空循环链链表
// 输入参数: 无
// 返回值: 指向循环链表的尾指针
PNode createEmptyLinkList();

// 函数功能: 从键盘读取 n 个数据构建单循环链表
// 输入参数 n : 单循环链表中的元素个数 
// 输入参数 tail : 循环链表尾指针
// 返回值: 指向循环链表的尾指针
PNode buildCirLinkList(int n, PNode tail);

// 函数功能: 合并两个循环链表构成一个有序循环链表, 同时去除重复元素
// 输入参数 tail1 : 第一个循环链表
// 输入参数 tail2 : 第二个循环链表
// 返回值: 指向合并后链表的尾指针
PNode mergeTwoCirLinkList(PNode tail1, PNode tail2);

// 函数功能: 输出链表中的元素
// 输入参数 tail : 循环链表
// 返回值: 无
void printCirLinkList(PNode tail);

/********** 延伸拓展 **********/



#endif // CIRLINKLIST_H