#pragma once
#include <iostream>

#define MaxLength 5

using namespace std;

typedef int ElemType;

//// 我记得结构体和类 相似
//typedef struct {
//    int Length = 0;  // （位序）Length位置上的元素是空的，Length-1才有元素
//    int MaxSize = MaxLength;  // 空间大小，当Length==MaxSize时，已经顺序表已经满了
//    ElemType* data = new ElemType[MaxLength];  // 通过指针指向数组来实现动态顺序表
//} SeqList;                                   // 结构体别名

// 我记得结构体和类 相似
typedef struct {
	int Length;
	int MaxSize;
	ElemType* data;
} SeqList;                                   // 结构体别名

// 函数声明
bool InitList(SeqList& L);

int Length(SeqList& L);

int LocateElem(SeqList& L, ElemType e);

bool GetElem(SeqList& L, int i, ElemType& e);

bool ListInsert(SeqList& L, int i, ElemType e);

bool ListDelete(SeqList& L, int i, ElemType& e);

bool PrintList(SeqList& L);

bool Empty(SeqList& L);

bool DestroyList(SeqList& L);

bool ExpansionList(SeqList& L, float ratio = 0.5);