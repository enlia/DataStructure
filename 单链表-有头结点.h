#pragma once
//�����ռ䶨��
using namespace std;

//���Ͷ���
typedef int ElemType;

typedef struct LNode {	//������
	ElemType data;		//������
	struct LNode* next;	//������
}LNode, * LinkList;

//��������
bool InitList(LinkList& L);

bool ListInsert(LinkList& L, int i, ElemType e);

bool ListPrint(LinkList& L);
