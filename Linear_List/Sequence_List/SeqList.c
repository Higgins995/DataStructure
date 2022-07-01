#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

SeqList setNullList_Seq(int m) {
	// 申请结构体 List 空间
	SeqList slist = (SeqList)malloc(sizeof(struct List));
	
	if (slist != NULL) {
		// 申请顺序表空间,大小为 m 个 DataType 空间
		slist->elem = (DataType *)malloc(sizeof(DataType) * m);
		
		if (slist->elem) {
			slist->Max = m;
			slist->n = 0;
			return slist;
		} else {
			free(slist);
		}
	}
	
	printf("Out of Space!!\n");
	return NULL;
}

int isNullList_Seq(SeqList slist) {
	return (slist->n == 0); // 检查顺序表的长度是否为0
}

int insertPre_Seq(SeqList slist, int p, DataType x) {
	int q = 0;
	
	if (slist->n >= slist->Max) {  // 顺序表满,溢出
		printf("Overflow!\n");
		return 0;
	}
	
	if (p < 0 || p > slist->n) {
		printf("Not exist!\n");  // 插入的下标不合理
		return 0;
	}
	
	for (q = slist->n - 1; q >= p; --q)
		// 后移插入位置及之后的元素
		slist->elem[q + 1] = slist->elem[q];  
	
	slist->elem[p] = x;      // 插入 x
	slist->n = slist->n + 1; // 顺序表的长度加1
	return 1;
}

int delIndex_Seq(SeqList slist, int p) {
	int q = 0;
	
	if (p < 0 || p >= slist->n) {
		printf("Not exist!\n");  // 删除的下标不合理
		return 0;
	}
	
	for (q = p; q < slist->n - 1; ++q)
		// 前移删除位置之后的元素
		slist->elem[q] = slist->elem[q + 1];  
	
	slist->n = slist->n - 1;  // 顺序表的长度减1
	return 1;
}

int locate_Seq(SeqList slist, int x) {
	int q = 0;
	
	for (q = 0; q < slist->n; ++q)
		if (slist->elem[q] == x)
			// 查找成功,返回对应的下标
			return q;
			
	return -1;
}

void print(SeqList slist) {
	int i = 0;
	
	for (i = 0; i < slist->n; ++i)
		// 依次遍历顺序表,并输出
		printf("%d ", slist->elem[i]);
	
	printf("\n");
}

void destoryList_Seq(SeqList slist) {
	free(slist->elem);  // 先释放数据空间
	free(slist);        // 再释放顺序表
}

/********** 延伸拓展 **********/

int delV_Seq(SeqList slist, int x) {
	int i = 0, n = slist->n;
	
	for (i = 0; i < n; ++i)  // 找到第一个值 x 的下标
		if (slist->elem[i] == x)
			break;
	
	if (slist->elem[i] != x) return 0;
	
	// 删除并前移之后的元素
	for ( ; i < n - 1; ++i)
		slist->elem[i] = slist->elem[i + 1];
		
	slist->n = n - 1;  // 顺序表的长度减1
	return 1;
}

int delA_Seq(SeqList slist, int x) {
	int i = 0, j = 0, n = slist->n;
	
	for (i = 0; i < n; ++i)
		if (slist->elem[i] != x)
			// 双指针思路
			slist->elem[j++] = slist->elem[i];
	
	// 注意循环中的j++操作, 它会指向顺序表末尾的下一位
	if (j == n) return 0; // 说明未删除任一 x,
	slist->n = j;  // 更新顺序表长度

	return 1;
}

void delete_j_k(SeqList slist, int j, int k) {
	if (j + k - 1 >= slist->n) {
		printf("Erroe!想删除的区间不合理!!!\n");
		return;
	}
	
	if (k == 0) return;
	
	int i = j, q = j + k - 1;
	
	for ( ; q < slist->n ; ++q)
		slist->elem[i++] = slist->elem[q];
	
	slist->n = slist->n - k;
	return;
}