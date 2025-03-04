#pragma once
//头文件
#include<iostream>
//命名空间
using namespace std;
//数据类型
typedef int ElemType;

typedef struct DNode {      //双链表结点类型
    ElemType data;          //数据域
    struct DNode* prior;    //前驱指针
    struct DNode* next;     //后继指针
} DNode,*DLinkList;

bool InitList(DLinkList& L);

bool ListInsert(DLinkList L, ElemType e);

bool ListPrint(DLinkList L);

bool ListDelete(DLinkList L);
