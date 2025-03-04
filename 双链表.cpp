#include "双链表.h"

int main() {
	DLinkList L;	// 头指针
	InitList(L);	// 初始化双链表
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

bool InitList(DLinkList& L) {	//初始化双链表
	L = new DNode;	//创建头结点
	if (L == nullptr) {	// 内存不足，分配失败
		return false;
	}
	L->next = nullptr;	// 头结点后继指针为空
	L->prior = nullptr;	// 头结点前驱指针为空
	//L->next = L;	// 头结点后继指针为空
	//L->prior = L;	// 头结点前驱指针为空
	return true;
}

bool ListInsert(DLinkList L, ElemType e) {	//在传入节点后面插入元素e
	if (L == nullptr) {	//传入头结点为空，非法
		return false;
	}
	DNode* p = new DNode;
	if (p == nullptr) {	// 内存不足，分配失败
		return false;
	}
	p->data = e;
	p->next = L->next;
	p->prior = L;
	L->next = p;
	//下面一行很重要
	if (p->next != nullptr) {
		p->next->prior = p;
	}
	return true;
}

bool ListPrint(DLinkList L) {
	cout << "------------------------------------------------" << endl;
	if (L == nullptr) {
		cout << "链表为空" << endl;
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


bool ListDelete(DLinkList L) {	//删除当前节点
	// 检查链表是否为空，为空则无法进行删除操作。
	if (L == nullptr) {
		return false;
	}
	DNode* p = L;
	//循环链表
	if (L->next == nullptr) {	//当前节点已经是最后一个节点了
		L->prior->next = nullptr;
	}
	else {
		L->prior->next = L->next;	//前一个节点的后继节点指向当前节点的后继节点
		L->next->prior = L->prior;	//后一个节点的前驱节点指向当前节点的前驱节点
	}
	delete p;
	return true;
}