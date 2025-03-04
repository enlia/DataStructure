#include<iostream>
#include "单链表-有头结点.h"


//主函数入口
int main_danlianbiao() {
	LinkList L = nullptr;	//创建时指向空
	InitList(L);		//初始化单链表
	for (int i = 0;i < 10;i++) {
		ListInsert(L, 0, i);	//头插法插入数据
	}
	ListPrint(L);	//打印数据:>
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

//头节点尾插
bool ListInsert(LinkList L, int i, ElemType e) {
	if (L == nullptr) {	//链表头结点地址非法
		return false;
	}
	LNode* t = new LNode;	//申请一个新的节点
	if (t == nullptr) {	//空间申请失败
		return false;
	}
	int j = 0;
	while (j < i - 1 || L->next != nullptr) {	//找到第i-1个节点
		L = L->next;
		j++;
	}
	if (j < i - 1) {	//没有找到第i-1个节点
		return false;
	}
	t->data = e;	//将值赋给节点
	t->next = L->next;	//新节点指向第一个数据节点
	L->next = t;	//头节点指向新节点
	return true;
}

//打印单链表
bool ListPrint(LinkList& L) {
	cout << "----------------------------------------------------" << endl;
	if (L == nullptr) {	//传入的地址非法
		cout << "链表首地址非法\t" << endl;
		return false;
	}
	cout << "开始打印:>" << endl;
	for (LNode* t = L->next;t != nullptr;t = t->next) {
		cout << t->data << '\t';
	}
	cout << endl;
	return true;
}

//计算链表的长度
int Length(LinkList& L) {
	int len = 0;
	for (LNode* t = L->next;t != nullptr;t = t->next) {
		len++;
	}
	return len;
}

//按序号查找节点
LNode* GetElem(LinkList& L, int i) {
	if (L == nullptr) {	//传入节点非法
		return nullptr;
	}
	LNode* t = L->next;	//用于遍历的节点
	for (int j = 1;j < i; j++) {
		if (t == nullptr) {	//链表长度不超过i
			return nullptr;
		}
		t = t->next;	//指向下一个节点
	}
	return t;	//t就是第i个节点
}

//返回值为e的节点
LNode* LocateElem(LinkList L, ElemType e) {
	for (LNode* t = L->next;t != nullptr;t = t->next) {
		if (t->data == e) {	//找到了值为e的节点
			return t;
		}
	}
	return nullptr;	//没有找到返回空指针
}

//删除第i个节点(位序),删除的值通过引用e返回
bool ListDelete(LinkList L, int i, ElemType& e) {
	if (L == nullptr) {	//传入的地址不合法
		return false;
	}
	//先找到第i-1个节点
	LNode* t = L;
	int j = 0;
	while (j < i - 1 && t->next != nullptr) {
		t = t->next;
		j++;
	}
	LNode* d = t->next;	//待删除
	if (d == nullptr || j != i - 1) {	//如果 链表长度不足i-1(位序) 或者 要删除节点是空地址,非法,无法删除
		return false;
	}
	t->next = d->next;
	e = d->data;	//返回删除的值
	//free(d);	//释放d节点的空间
	delete d;
	return true;
}

bool List_TailInsert(LinkList L,ElemType e) {
	if (L == nullptr) {	//链表地址非法
		return false;
	}
	LNode* t = new LNode;
	if (t == nullptr) {	//申请内存失败
		return false;
	}
	t->next = nullptr;	//设置新节点内容
	t->data = e;
	while (L->next != nullptr) {	//找到最后一个节点,将新节点插入到这个节点后
		L = L->next;
	}
	L->next = t;	//将新节点连接到链表最后的位置
	return true;
}