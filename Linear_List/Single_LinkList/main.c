#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main(int argc, char	*argv[]) {
	LinkList head = NULL;
	PNode p = NULL;
	head = setNullList_Link();
	
	printf("判断链表是否为空, 1 为空, 0 为非空: ");
	printf("%d\n",isNull_Link(head));
	
	// createList_Head(head);
	// printf("头插法建立完成后的链表: ");
	// print(head);
	
	createList_Tail(head);
	printf("尾插法建立完成后的链表: ");
	print(head);
	
	p = locate_Link(head, 5);
	printf("\n元素 5 在内存中的位置: ");
	printf("%p\n", p);
	
	insertPost_Link(head, p, 99);
	printf("在 5 后面插入 99 后的链表: ");
	print(head);
	
	delNode_Link(head, 99);
	printf("\n删除 99 后的链表: ");
	print(head);
	printf("\n");
	
	destoryList_Link(head);
	return 0;
}