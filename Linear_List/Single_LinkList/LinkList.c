#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

LinkList setNullList_Link() {
	LinkList head = (LinkList)malloc(sizeof(struct Node));
	
	if (head != NULL) head->next = NULL;
	else printf("Alloc Failure!");
	
	return head;  //返回头指针
}

int isNull_Link(LinkList llist) {  // 判断链表是否为空
	return (llist->next == NULL);
}

void createList_Head(PNode head) {  // 用头插法建立单链表
	PNode p = NULL;
	int data = 0;
	printf("请输入整型数据建立链表, 以 -1 结束: \n");
	scanf("%d", &data);
	
	while (data != -1) {
		p = (struct Node*)malloc(sizeof(struct Node));
		p->data = data;        // 对数据域赋值
		p->next = head->next;  // 对 next 域赋值
		head->next = p;
		scanf("%d", &data);
	}
}

void createList_Tail(PNode head) {  // 用尾插法建立单链表
	PNode p = NULL, q = head;
	int data;
	
	printf("请输入整型数据建立链表, 以 -1 结束: \n");
	scanf("%d", &data);
	
	while (data != -1) {
		p = (struct Node*)malloc(sizeof(PNode));
		p->data = data;
		p->next = NULL;
		q->next = p;
		q = p;
		scanf("%d", &data);
	}
}

int insertPost_Link(LinkList llist, PNode p, DataType x) {
	// 在 llist 链表中的 p 位置之后插入值为 x 的结点
	PNode q = (PNode)malloc(sizeof(struct Node));
	
	if (p == NULL) {
		printf("Parameter Failure!\n");
		return 0;
	}
	
	if (q == NULL) {
		printf("Alloc Failure!\n");
	} else {
		q->data = x;
		q->next = p->next;
		p->next = q;
		return 1;
	}
}

void delNode_Link(PNode head, int data) {
	// 删除第一个与输入参数相等的结点
	PNode p = head->next, beforeP = head;
	
	while (p != NULL) {
		if (p->data == data) {
			beforeP->next = p->next;
			free(p);
			break;
		} else {
			beforeP = p;
			p = p->next;
		}
	}
}

PNode locate_Link(LinkList llist, DataType x) {
	// 在 llist 链表中查找值为 x 的结点,并返回在内存中的位置
	if (llist == NULL) return NULL;
	PNode p = llist->next;
	
	while (p != NULL && p->data != x)
		p = p->next;
	
	return p;
}

void print(LinkList head) {  // 输出单链表
	PNode p = head->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void destoryList_Link(LinkList head) {  // 释放单链表
	PNode pre = head, p = pre->next;
	while (p) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

/********** 延伸拓展 **********/

void insertPost_Link_Value(PNode head, int finddata, int insertdata) {
	// 在链表值为 finddata 的元素的后面插入一个新的值为 insertdata 的结点
}

void delValue_Link_All(LinkList llist, int x) {
	// 删除单链表中所有值为 x 的元素
}

void delValue_Link_j_k(LinkList llist, int j, int k) {
	// 删除单链表中从第 j 个元素开始的连续 k 个元素
}

// DataType search_Mid(LinkList llist) {
	
// }