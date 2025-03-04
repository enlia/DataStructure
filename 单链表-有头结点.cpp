#include<iostream>
#include "单链表-有头结点.h"


//主函数入口
int main() {
	LinkList L = nullptr;	//创建时指向空
	InitList(L);		//初始化单链表

	return 0;
}

//单链表初始化
bool InitList(LinkList& L) {
	//L = (LNode*)malloc(sizeof(LNode));
	L = new LNode;
	if (L == nullptr) {	//内存申请失败
		return false;
	}
	L->next = NULL;	//初始化的头结点指向NULL
	return true;
}

bool ListInsert(LinkList& L, int i, ElemType e) {	//头插
	LNode* t = new LNode;	//申请一个新的节点
	if (t == nullptr) {	//空间申请失败
		return false;
	}
	t->data = e;	//将值赋给节点
	t->next = L->next;	//新节点指向第一个数据节点
	L->next = t;	//头节点指向新节点
	return true;
}

bool ListPrint(LinkList& L) {
	if (L == nullptr) {	//传入的地址非法
		return false;
	}
	for (LNode* t = L->next;t != nullptr;t = t->next) {
		cout << t->data << '\t';
	}
	cout << endl;
	return true;
}