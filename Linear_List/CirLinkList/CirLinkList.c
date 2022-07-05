#include <stdio.h>
#include <stdlib.h>
#include "CirLinkList.h"

PNode createEmptyLinkList() {
	PNode current;
	current = (PNode)malloc(sizeof(Node));
	current->next = NULL;
	current->data = -1;
	return current;
}

PNode buildCirLinkList(int n, PNode tail) {
	PNode current, prev;
	int i;
	prev = tail;  // 先将 tail 用作头结点
	
	for (i = 0; i < n; ++i) {
		current = (PNode)malloc(sizeof(Node));
		current->next = NULL;
		scanf("%d", &current->data);
		prev->next = current;
		prev = current;
	}
	
	// 让最后一个结点的 next 指向开头, 形成循环链表
	current->next = tail->next;
	tail->next = current;
	return tail;
}

PNode mergeTwoCirLinkList(PNode tail1, PNode tail2) {
	PNode current1 = NULL, current2 = NULL;
	PNode prev1 = NULL, prev2 = NULL, tmp = NULL;
	PNode last1 = NULL, last2 = NULL;
	int flag = 1;            // 用于标记链表 2 的状态
	last1 = tail1->next;     // 保留循环链表的头结点
	last2 = tail2->next;
	prev1 = last1;           // 前驱结点
	prev2 = last2;
	current1 = prev1->next;  // 用于遍历的结点
	current2 = prev2->next;
	
	do {
		if (flag && current2->data <= current1->data) {
			if (current2 == last2) {
				current2->next = prev1->next;
				prev1->next = current2;
				free(tail2);
				flag = 0;
			} else {
				prev2->next = current2->next;
				current2->next = prev1->next;
				prev1->next = current2;
				current2 = prev2->next;
			}
			
			prev1 = prev1->next;
		} else {
			current1 = current1->next;
			prev1 = prev1->next;
		}
	} while (current1 != last1->next);
	
	if (flag) {  // 将链表2中剩余的结点
		last2->next = last1->next;
		last1->next = current2;
		tail1->next = last2;
	}
	
	current1 = tail1->next;
	do {  // 这个算法我也不是很理解，为什么这么麻烦？？？
		while (current1->data == current1->next->data) {
			if (current1->next == tail1->next) {
				tail1->next = current1;
			}
			tmp = current1->next;
			current1->next = current1->next->next;
			free(tmp);
		}
		
		current1 = current1->next;
	} while (current1 != tail1->next);
	
	return tail1;
}


void printCirLinkList(PNode tail) {
	PNode current, last;
	last = tail->next;  // last 其实是头结点
	current = last->next;  // 从第二个结点(如果有的话)开始
	do {
		printf("%d ", current->data);
		current = current->next;
	} while (current != last->next);
}

/********** 延伸拓展 **********/

