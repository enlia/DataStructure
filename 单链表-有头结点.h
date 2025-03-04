#pragma once
//头文件引用
#include<iostream>

//命名空间定义
using namespace std;

//类型定义
typedef int ElemType;

typedef struct LNode {	//单链表
	ElemType data;		//数据域
	struct LNode* next;	//数据域
}LNode, * LinkList;

//方法定义
bool InitList(LinkList& L);

bool ListInsert(LinkList L, int i, ElemType e);

bool ListPrint(LinkList& L);

int Length(LinkList& L);

LNode* GetElem(LinkList& L, int i);

LNode* LocateElem(LinkList L, ElemType e);

bool ListDelete(LinkList L, int i, ElemType& e);

bool List_TailInsert(LinkList L, ElemType e);
