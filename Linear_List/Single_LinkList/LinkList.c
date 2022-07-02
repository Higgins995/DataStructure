#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

PNode setNullList_Link() {
	PNode head = (PNode)malloc(sizeof(struct Node));
	
	if (head != NULL) head->next = NULL;
	else printf("Alloc Failure!");
	
	return head;  //返回头指针
}

int isNull_Link(PNode head) {  // 判断链表是否为空
	return (head->next == NULL);
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

int insertPost_Link(PNode head, PNode p, DataType x) {
	// 在 head 链表中的 p 位置之后插入值为 x 的结点
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

PNode locate_Link(PNode head, DataType x) {
	// 在单链表中查找第一个值为 x 的结点,并返回在内存中的位置
	if (head == NULL) return NULL;
	PNode p = head->next;
	
	while (p != NULL && p->data != x)
		p = p->next;
	
	return p;
}

void print(PNode head) {  // 输出单链表
	PNode p = head->next;
	
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void destoryList_Link(PNode head) {  // 释放单链表
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
	// 在链表所有值为 finddata 的元素的后面插入一个新的值为 insertdata 的结点
	PNode p = head->next;
	
	while (p != NULL) {
		if (p->data == finddata) {
			PNode tmp = (PNode)malloc(sizeof(struct Node));
			tmp->data = insertdata;
			tmp->next = p->next;
			p->next = tmp;
		}
		
		p = p->next;
	}
}

void delValue_Link_All(PNode head, int x) {
	// 删除单链表中所有值为 x 的元素
	PNode p = head->next, beforeP = head;
	
	while (p != NULL) {
		if (p->data == x) {
			beforeP->next = p->next;
			free(p);
			p = beforeP->next;
			continue;
		}
		
		beforeP = p;
		p = p->next;
	}
}

void delValue_Link_j_k(PNode head, int j, int k) {
	// 删除单链表中从下标 j 开始的连续 k 个元素
	PNode p = head->next, beforeP = head;
	int len = 0, cnt = 0, i = 0;
	
	while (p != NULL) {
		++len;
		p = p->next;
	}
	
	if (j + k - 1 > len) {
		printf("Erroe!操作区间不合理!!!\n");
		return;
	}
	
	p = head->next;
	while (cnt < j) {  // 找到下标 j
		beforeP = p;
		p = p->next;
		++cnt;
	}
	
	for (i = 0; i < k; ++i) {
		p = p->next;
		free(beforeP->next);
		beforeP->next = p;
	}
}

DataType search_Mid(PNode head) {
	// 以第一个结点的值为分隔点
	// p 遍历单链表
	// h 为新链表的第一个结点, tail 为尾结点
	PNode p = head->next;
	PNode h = head->next;
	PNode tail = head->next;
	
	int x = p->data;
	head->next = p->next;
	p = p->next;
	h->next = NULL;
	
	while (p != NULL) {
		head->next = p->next;
		
		if (p->data <= x) {
			// 如果当前结点的值小于等于 x ,用头插法更新
			p->next = h;
			h = p;
		} else {
			// 用头插法更新
			tail->next = p;
			tail = p;
		}
		
		p = head->next;
	}
	
	head->next = h;  // 记得把 head 指向新链表
	
	return x;
}