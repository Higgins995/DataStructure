#include <stdio.h>
#include <stdlib.h>
#include "CirLinkList.h"

int main() {
	PNode list1 = NULL, list2 = NULL;
	list1 = createEmptyLinkList();
	list2 = createEmptyLinkList();
	
	printf("请输入 5 个数据创建循环链表: ");
	buildCirLinkList(5, list1);
	printf("请输入 5 个数据创建循环链表: ");
	buildCirLinkList(5, list2);
	
	list1 = mergeTwoCirLinkList(list1, list2);
	printCirLinkList(list1);
	
	/********** 延伸拓展 **********/
	
	printf("\n");
	return 0;
}