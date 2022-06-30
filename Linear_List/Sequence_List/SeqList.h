#ifndef SEQLIST_H
#define SEQLIST_H

typedef int DataType;
struct List {
	int Max;        // 顺序表的最大容量
	int n;          // 顺序表的长度
	DataType *elem; // 存放顺序表元素的数组地址
};

typedef struct List *SeqList;

/*
* 函数功能: 创建空顺序表
* 输入参数 m : 顺序表的最大值 
* 返回值: 空的顺序表
*/
SeqList setNullList_Seq(int m);

/*
* 函数功能: 判断顺序表是否为空
* 输入参数 slist : 顺序表
* 返回值: 为空返回1,否则返回0
*/
int isNullList_Seq(SeqList slist);

/*
* 函数功能: 在线性表 slist 的 p 位置之前插入 x
* 输入参数 slist : 顺序表
* 输入参数 p : 插入位置
* 输入参数 x : 待插入的元素
* 返回值: 若成功返回1,否则返回0
*/
int insertPre_Seq(SeqList slist, int p, DataType x);

/*
* 函数功能: 删除下表为 p 的元素
* 输入参数 slist : 顺序表
# 输入参数 p : 删除位置
* 返回值: 若成功删除返回1,否则返回0
*/
int delIndex_Seq(SeqList slist, int p);

/*
* 函数功能: 查找函数值为 x 的元素
* 输入参数 slist : 顺序表
* 输入参数 x : 要查找的元素
* 返回值: 若查找成功返回元素在顺序表中的下标,否则返回-1
*/
int locate_Seq(SeqList slist, int x);

/*
* 函数功能: 输出顺序表
* 输入参数 slist : 顺序表
* 返回值: 无
*/
void print(SeqList slist);

/*
* 函数功能: 释放顺序表
* 输入参数 slist : 顺序表
* 返回值: 无
*/
void destoryList_Seq(SeqList slist);

#endif