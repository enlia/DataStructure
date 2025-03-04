#include<iostream>
#include "������-��ͷ���.h"


//���������
int main_danlianbiao() {
	LinkList L = nullptr;	//����ʱָ���
	InitList(L);		//��ʼ��������
	for (int i = 0;i < 10;i++) {
		ListInsert(L, 0, i);	//ͷ�巨��������
	}
	ListPrint(L);	//��ӡ����:>
	//int len = Length(L);
	//cout << "----------------------------------------------------" << endl;
	//cout << "len\t" << len << endl;
	//cout << "----------------------------------------------------" << endl;
	//LNode* t = GetElem(L, 5);
	//cout << t->data << endl;
	//cout << "----------------------------------------------------" << endl;
	//t = LocateElem(L, 3);
	//cout << "locate(3):>\t" << t->data << endl;
	cout << "----------------------------------------------------" << endl;
	ElemType e;
	cout << ListDelete(L, 1, e) << endl;
	cout << "----------------------------------------------------" << endl;
	List_TailInsert(L, -1);
	for (int i = 0;i < 5;i++) {
		List_TailInsert(L, i);
	}
	ListPrint(L);
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

//ͷ�ڵ�β��
bool ListInsert(LinkList L, int i, ElemType e) {
	if (L == nullptr) {	//����ͷ����ַ�Ƿ�
		return false;
	}
	LNode* t = new LNode;	//����һ���µĽڵ�
	if (t == nullptr) {	//�ռ�����ʧ��
		return false;
	}
	int j = 0;
	while (j < i - 1 || L->next != nullptr) {	//�ҵ���i-1���ڵ�
		L = L->next;
		j++;
	}
	if (j < i - 1) {	//û���ҵ���i-1���ڵ�
		return false;
	}
	t->data = e;	//��ֵ�����ڵ�
	t->next = L->next;	//�½ڵ�ָ���һ�����ݽڵ�
	L->next = t;	//ͷ�ڵ�ָ���½ڵ�
	return true;
}

//��ӡ������
bool ListPrint(LinkList& L) {
	cout << "----------------------------------------------------" << endl;
	if (L == nullptr) {	//����ĵ�ַ�Ƿ�
		cout << "�����׵�ַ�Ƿ�\t" << endl;
		return false;
	}
	cout << "��ʼ��ӡ:>" << endl;
	for (LNode* t = L->next;t != nullptr;t = t->next) {
		cout << t->data << '\t';
	}
	cout << endl;
	return true;
}

//��������ĳ���
int Length(LinkList& L) {
	int len = 0;
	for (LNode* t = L->next;t != nullptr;t = t->next) {
		len++;
	}
	return len;
}

//����Ų��ҽڵ�
LNode* GetElem(LinkList& L, int i) {
	if (L == nullptr) {	//����ڵ�Ƿ�
		return nullptr;
	}
	LNode* t = L->next;	//���ڱ����Ľڵ�
	for (int j = 1;j < i; j++) {
		if (t == nullptr) {	//�����Ȳ�����i
			return nullptr;
		}
		t = t->next;	//ָ����һ���ڵ�
	}
	return t;	//t���ǵ�i���ڵ�
}

//����ֵΪe�Ľڵ�
LNode* LocateElem(LinkList L, ElemType e) {
	for (LNode* t = L->next;t != nullptr;t = t->next) {
		if (t->data == e) {	//�ҵ���ֵΪe�Ľڵ�
			return t;
		}
	}
	return nullptr;	//û���ҵ����ؿ�ָ��
}

//ɾ����i���ڵ�(λ��),ɾ����ֵͨ������e����
bool ListDelete(LinkList L, int i, ElemType& e) {
	if (L == nullptr) {	//����ĵ�ַ���Ϸ�
		return false;
	}
	//���ҵ���i-1���ڵ�
	LNode* t = L;
	int j = 0;
	while (j < i - 1 && t->next != nullptr) {
		t = t->next;
		j++;
	}
	LNode* d = t->next;	//��ɾ��
	if (d == nullptr || j != i - 1) {	//��� �����Ȳ���i-1(λ��) ���� Ҫɾ���ڵ��ǿյ�ַ,�Ƿ�,�޷�ɾ��
		return false;
	}
	t->next = d->next;
	e = d->data;	//����ɾ����ֵ
	//free(d);	//�ͷ�d�ڵ�Ŀռ�
	delete d;
	return true;
}

bool List_TailInsert(LinkList L,ElemType e) {
	if (L == nullptr) {	//�����ַ�Ƿ�
		return false;
	}
	LNode* t = new LNode;
	if (t == nullptr) {	//�����ڴ�ʧ��
		return false;
	}
	t->next = nullptr;	//�����½ڵ�����
	t->data = e;
	while (L->next != nullptr) {	//�ҵ����һ���ڵ�,���½ڵ���뵽����ڵ��
		L = L->next;
	}
	L->next = t;	//���½ڵ����ӵ���������λ��
	return true;
}