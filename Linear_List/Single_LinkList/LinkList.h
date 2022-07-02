#ifndef LINKLIST_H
#define LINKLIST_H

typedef int DataType;

struct Node {
	DataType data;      // 当前结点的数据值
	struct Node *next;  // 下一结点
};

typedef struct Node* PNode;     // 定义指向结构体的指针
typedef struct Node* LinkList;  // 定义链表类型

/*
* 函数功能: 创建带有头结点的空链表
* 输入参数: 无
* 返回值: 空链表
*/
LinkList setNullList_Link();

/*
* 函数功能: 判断链表是否为空
* 输入参数: 链表
* 返回值: 为空返回 1, 否则返回 0
*/
int isNull_Link(LinkList llist);

/*
* 函数功能: 用头插法建立单链表
* 输入参数 head : 链表头节点
* 返回值: 无
*/
void createList_Head(PNode head);

/*
* 函数功能: 用尾插法建立单链表
* 输入参数 head : 链表头结点
* 返回值: 无
*/
void createList_Tail(PNode head);

/*
* 函数功能: 在 llist 链表中的结点 p 之后插入一个值为 x 的结点
* 输入参数 llist : 链表
* 输入参数 p : 插入位置
* 输入参数 x : 待插入的元素
* 返回值: 成功返回 1, 否则返回 0
*/
int insertPost_Link(LinkList llist, PNode p, DataType x);

/*
* 函数功能: 删除第一个与输入参数相等的值的结点
* 输入参数 head : 链表头节点
* 输入参数 data : 待删除的元素
* 返回值: 无
*/
void delNode_Link(PNode head, int data);

/*
* 函数功能: 在 llsit 链表中查找值为 x 的结点
* 输入参数 llist : 链表
* 输入参数 x : 待查找的元素
* 返回值: 在内存中的位置
*/
PNode locate_Link(LinkList llist, DataType x);

/*
* 函数功能: 输出单链表
* 输入参数 head : 链表头节点
* 返回值: 无
*/
void print(LinkList head);

/*
* 函数功能: 释放单链表
* 输入参数 head : 链表头节点
* 返回值: 无
*/
void destoryList_Link(LinkList head);

/********** 延伸拓展 **********/

/*
* 函数功能: 在链表值为 finddata 的元素的后面
*           插入一个新的值为 insertdata 的结点
* 输入参数 head : 链表头节点
* 输入参数 finddata : 待插入的位置的前一个结点
* 输入参数 insertdata : 待插入的新值
* 返回值: 无
*/
void insertPost_Link_Value(PNode head, int finddata, int insertdata);

/*
* 函数功能: 删除单链表中所有值为 x 的元素
* 输入参数 llist : 链表
* 输入参数 x : 待删除的值
* 返回值: 无
*/
void delValue_Link_All(LinkList llist, int x);

/*
* 函数功能: 删除单链表中从第 j 个元素开始的连续 k 个元素
* 输入参数 llist : 链表
* 输入参数 j : 删除区间的起始下标
* 输入参数 k : 删除元素的个数
* 返回值: 无
*/
void delValue_Link_j_k(LinkList llist, int j, int k);

/*
* 函数功能: 以链表中的某个元素 x 对链表进行划分,将单链表以 x 
*           为分割点进行划分,比 x 小的在 x 的前面,
*           比 x 大的在 x 的后面
* 输入参数 llist : 链表
* 返回值: 分隔点的值
*/
DataType search_Mid(LinkList llist);

#endif