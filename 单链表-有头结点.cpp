#include<iostream>
#include "������-��ͷ���.h"


//���������
int main() {
	LinkList L = nullptr;	//����ʱָ���
	InitList(L);		//��ʼ��������

	return 0;
}

//�������ʼ��
bool InitList(LinkList& L) {
	//L = (LNode*)malloc(sizeof(LNode));
	L = new LNode;
	if (L == nullptr) {	//�ڴ�����ʧ��
		return false;
	}
	L->next = NULL;	//��ʼ����ͷ���ָ��NULL
	return true;
}

bool ListInsert(LinkList& L, int i, ElemType e) {	//ͷ��
	LNode* t = new LNode;	//����һ���µĽڵ�
	if (t == nullptr) {	//�ռ�����ʧ��
		return false;
	}
	t->data = e;	//��ֵ�����ڵ�
	t->next = L->next;	//�½ڵ�ָ���һ�����ݽڵ�
	L->next = t;	//ͷ�ڵ�ָ���½ڵ�
	return true;
}

bool ListPrint(LinkList& L) {
	if (L == nullptr) {	//����ĵ�ַ�Ƿ�
		return false;
	}
	for (LNode* t = L->next;t != nullptr;t = t->next) {
		cout << t->data << '\t';
	}
	cout << endl;
	return true;
}