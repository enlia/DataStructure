#pragma once
//ͷ�ļ�
#include<iostream>
//�����ռ�
using namespace std;
//��������
typedef int ElemType;

typedef struct DNode {      //˫����������
    ElemType data;          //������
    struct DNode* prior;    //ǰ��ָ��
    struct DNode* next;     //���ָ��
} DNode,*DLinkList;

bool InitList(DLinkList& L);

bool ListInsert(DLinkList L, ElemType e);

bool ListPrint(DLinkList L);

bool ListDelete(DLinkList L);
