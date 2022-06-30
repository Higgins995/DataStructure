#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

int main(int argc, char *argv[]) {
	SeqList seqlist;
	int max = 0, len = 0, i = 0, x = 0;
	printf("请输入顺序表的最大容量(<100) = ");
	scanf("%d", &max);
	seqlist = setNullList_Seq(max);  // 创建空的顺序表
	if (seqlist != NULL) {
		printf("输入顺序表的目标长度: ");
		scanf("%d", &len);
		if (len > max) {
			printf("Erroe! 顺序表的目标长度超过了最大容量!\n");
			return 0;
		}
		
		printf("请输入顺序表的元素: ");
		for (i = 0; i < len; ++i) {
			scanf("%d", &x);
			insertPre_Seq(seqlist, i, x);
		}
		
		printf("顺序表是否为空, 1为空, 0为非空: %d\n", 
			   isNullList_Seq(seqlist));
			   
		printf("当前顺序表的元素是: ");
		print(seqlist);
		delIndex_Seq(seqlist, 3);
		printf("删除下表为 3 的元素后的顺序表: ");
		print(seqlist);
		insertPre_Seq(seqlist, 2, 99);
		printf("在下标 2 位置之前插入 99 后的顺序表: ");
		print(seqlist);
		printf("查找值为 99 的元素下标: ");
		printf("%d\n", locate_Seq(seqlist, 99));
		destoryList_Seq(seqlist);
	} else {
		printf("空间分配失败!!!\n");
	}
	
	return 0;
}