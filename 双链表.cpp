#include "˫����.h"

int main() {
	DLinkList L;	// ͷָ��
	InitList(L);	// ��ʼ��˫����
	ListPrint(L);
	//DNode* t = L;
	for (int i = 0;i < 10;i++/*,t = t->next*/) {
		ListInsert(L, i);
	}
	ListPrint(L);
	ListDelete(L->next->next->next);
	ListPrint(L);
	return 0;
}

bool InitList(DLinkList& L) {	//��ʼ��˫����
	L = new DNode;	//����ͷ���
	if (L == nullptr) {	// �ڴ治�㣬����ʧ��
		return false;
	}
	L->next = nullptr;	// ͷ�����ָ��Ϊ��
	L->prior = nullptr;	// ͷ���ǰ��ָ��Ϊ��
	//L->next = L;	// ͷ�����ָ��Ϊ��
	//L->prior = L;	// ͷ���ǰ��ָ��Ϊ��
	return true;
}

bool ListInsert(DLinkList L, ElemType e) {	//�ڴ���ڵ�������Ԫ��e
	if (L == nullptr) {	//����ͷ���Ϊ�գ��Ƿ�
		return false;
	}
	DNode* p = new DNode;
	if (p == nullptr) {	// �ڴ治�㣬����ʧ��
		return false;
	}
	p->data = e;
	p->next = L->next;
	p->prior = L;
	L->next = p;
	//����һ�к���Ҫ
	if (p->next != nullptr) {
		p->next->prior = p;
	}
	return true;
}

bool ListPrint(DLinkList L) {
	cout << "------------------------------------------------" << endl;
	if (L == nullptr) {
		cout << "����Ϊ��" << endl;
		return false;
	}
	DNode* p = L;
	while (p->next != nullptr && p->next != L) {
		p = p->next;
		cout << p->data << "\t";
	}
	cout << endl;
	return true;
}


bool ListDelete(DLinkList L) {	//ɾ����ǰ�ڵ�
	// ��������Ƿ�Ϊ�գ�Ϊ�����޷�����ɾ��������
	if (L == nullptr) {
		return false;
	}
	DNode* p = L;
	//ѭ������
	if (L->next == nullptr) {	//��ǰ�ڵ��Ѿ������һ���ڵ���
		L->prior->next = nullptr;
	}
	else {
		L->prior->next = L->next;	//ǰһ���ڵ�ĺ�̽ڵ�ָ��ǰ�ڵ�ĺ�̽ڵ�
		L->next->prior = L->prior;	//��һ���ڵ��ǰ���ڵ�ָ��ǰ�ڵ��ǰ���ڵ�
	}
	delete p;
	return true;
}