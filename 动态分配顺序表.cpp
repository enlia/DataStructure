#include"动态分配顺序表.h"

int vmain() {
	// 首先创建一个动态分配顺序表
	SeqList L;
	InitList(L);
	PrintList(L);
	for (int i = 1; i <= 7; i++) {
		ListInsert(L, i, i);
	}
	PrintList(L);
	ListInsert(L, 3, 7);    //ok
	PrintList(L);
	//DestroyList(L);   //ok
	PrintList(L);
	ElemType e = -9;
	int Len = Length(L);
	cout << "Len" << Len << endl;
	ListDelete(L, 3, e);
	cout << "e\t" << e << endl;
	PrintList(L);
	int index = LocateElem(L, 7);
	cout << "index\t" << index << endl;

	cout << "Empty\t" << Empty(L) << endl;
	cout << "DestroyList\t" << DestroyList(L) << endl;
	cout << "Empty\t" << Empty(L) << endl;
	return 0;
}

bool InitList(SeqList& L) {
	// 初始化动态顺序表，但因为在创建结构体的时候已经进行了初始，所以不用再初始化
	L.Length = 0;
	L.data = new ElemType[MaxLength];
	L.MaxSize = MaxLength;
	return true;
}

int Length(SeqList& L) {
	// 返回动态顺序表的长度
	return L.Length;
}

int LocateElem(SeqList& L, ElemType e) {
	// 返回动态顺序表中第一个与e相等的元素的位置(位序)，若不存在则返回0
	for (int i = 0; i < L.Length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}

bool GetElem(SeqList& L, int i, ElemType& e) {
	// 返回位序为i的元素
	if (i < 1 or i > L.Length) {
		// 先检查i是否合法
		return false;  // 不合法
	}
	e = L.data[i - 1];  // 通过引用传回对应的元素
	return true;
}

bool ListInsert(SeqList& L, int i, ElemType e) {
	// 将元素e插入位序为i的位置
	// 先检查空间是否足够
	if (i<1 or i>L.Length + 1) {
		cout << "插入位置超过了最大长度" << endl;
		return false;
	}
	if (L.Length >=
		L.MaxSize) {  // 后续进行处理，如果空间不够，进行扩容，然后插入元素。若扩容失败再返回false;
		cout << "容量不足" << endl;
		// todo
		cout << "尝试扩容" << endl;
		if (ExpansionList(L) == false) {
			cout << "扩容失败" << endl;
			return false;
		}
		cout << "扩容成功" << endl;
		// PrintList(L);  // 测试使用，后续删除
	}
	// 将i及以后的元素依次后移1位，从后往前
	for (int j = L.Length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;  // 将输入插入对应位置
	L.Length++;         // 更新顺序表长度
	return true;
}

bool ListDelete(SeqList& L, int i, ElemType& e) {
	// 删除位序为i的元素，将元素的值通过引用参数e传回
	// 首先要判断位序是否合理
	if (i < 1 or i > L.Length) {  // 位序小于1或者超出当前元素个数
		return false;
	}
	e = L.data[i - 1];  // 将对应的元素赋值给e
	for (int j = i - 1; j < L.Length - 1; j++) {
		L.data[j] = L.data[j + 1];  // 将后一位依次赋值给前一位，从前往后
	}
	L.Length--;  // 更新顺序表长度
	return true;
}

bool PrintList(SeqList& L) {
	// 格式化输出顺序表内容
	// 首先输出顺序表参数
	cout << "----------------------------------------" << endl;
	cout << "L.Length:>>" << L.Length << endl;
	cout << "L.MaxSize:>>" << L.MaxSize << endl;
	// 格式化输出表内容
	cout << "L.data:>>" << endl;
	for (int i = 0; i < L.Length; i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		cout << L.data[i] << '\t';
	}
	cout << endl << "----------------------------------------" << endl;
	return true;
}

bool Empty(SeqList& L) {
	// 判断L是否为空表
	if (L.Length == 0) {
		return true;
	}
	return false;
}

bool DestroyList(SeqList& L) {
	// 释放顺序表的空间
	if (L.data != nullptr) {  // 当指针所指内容不是空指针时，开始释放
		free(L.data);
		L.Length = 0;	//长度重置为0
		return true;
	}
	return false;
}

bool ExpansionList(SeqList& L, float ratio) {
	// 对顺序表进行增容
	int nextLevel = (int)(L.MaxSize * (1 + ratio));  // 扩容后大小
	ElemType* temp = new ElemType[nextLevel];        //
	if (temp == nullptr) {                           // 空间开辟失败，返回空指针
		return false;
	}
	for (int i = 0; i < L.Length; i++) {
		temp[i] = L.data[i];  // 将原顺序表中所有内容搬运到新的空间中
	}
	free(L.data);           // 释放原空间
	L.data = temp;          // 原指针指向新空间
	L.MaxSize = nextLevel;  // 更新最大尺寸
	return true;
}