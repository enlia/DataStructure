#pragma once
#include <iostream>

#define MaxLength 5

using namespace std;

typedef int ElemType;

//// �Ҽǵýṹ����� ����
//typedef struct {
//    int Length = 0;  // ��λ��Lengthλ���ϵ�Ԫ���ǿյģ�Length-1����Ԫ��
//    int MaxSize = MaxLength;  // �ռ��С����Length==MaxSizeʱ���Ѿ�˳����Ѿ�����
//    ElemType* data = new ElemType[MaxLength];  // ͨ��ָ��ָ��������ʵ�ֶ�̬˳���
//} SeqList;                                   // �ṹ�����

// �Ҽǵýṹ����� ����
typedef struct {
	int Length;
	int MaxSize;
	ElemType* data;
} SeqList;                                   // �ṹ�����

// ��������
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