#include"��̬����˳���.h"

int vmain() {
	// ���ȴ���һ����̬����˳���
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
	// ��ʼ����̬˳�������Ϊ�ڴ����ṹ���ʱ���Ѿ������˳�ʼ�����Բ����ٳ�ʼ��
	L.Length = 0;
	L.data = new ElemType[MaxLength];
	L.MaxSize = MaxLength;
	return true;
}

int Length(SeqList& L) {
	// ���ض�̬˳���ĳ���
	return L.Length;
}

int LocateElem(SeqList& L, ElemType e) {
	// ���ض�̬˳����е�һ����e��ȵ�Ԫ�ص�λ��(λ��)�����������򷵻�0
	for (int i = 0; i < L.Length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}

bool GetElem(SeqList& L, int i, ElemType& e) {
	// ����λ��Ϊi��Ԫ��
	if (i < 1 or i > L.Length) {
		// �ȼ��i�Ƿ�Ϸ�
		return false;  // ���Ϸ�
	}
	e = L.data[i - 1];  // ͨ�����ô��ض�Ӧ��Ԫ��
	return true;
}

bool ListInsert(SeqList& L, int i, ElemType e) {
	// ��Ԫ��e����λ��Ϊi��λ��
	// �ȼ��ռ��Ƿ��㹻
	if (i<1 or i>L.Length + 1) {
		cout << "����λ�ó�������󳤶�" << endl;
		return false;
	}
	if (L.Length >=
		L.MaxSize) {  // �������д�������ռ䲻�����������ݣ�Ȼ�����Ԫ�ء�������ʧ���ٷ���false;
		cout << "��������" << endl;
		// todo
		cout << "��������" << endl;
		if (ExpansionList(L) == false) {
			cout << "����ʧ��" << endl;
			return false;
		}
		cout << "���ݳɹ�" << endl;
		// PrintList(L);  // ����ʹ�ã�����ɾ��
	}
	// ��i���Ժ��Ԫ�����κ���1λ���Ӻ���ǰ
	for (int j = L.Length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;  // ����������Ӧλ��
	L.Length++;         // ����˳�����
	return true;
}

bool ListDelete(SeqList& L, int i, ElemType& e) {
	// ɾ��λ��Ϊi��Ԫ�أ���Ԫ�ص�ֵͨ�����ò���e����
	// ����Ҫ�ж�λ���Ƿ����
	if (i < 1 or i > L.Length) {  // λ��С��1���߳�����ǰԪ�ظ���
		return false;
	}
	e = L.data[i - 1];  // ����Ӧ��Ԫ�ظ�ֵ��e
	for (int j = i - 1; j < L.Length - 1; j++) {
		L.data[j] = L.data[j + 1];  // ����һλ���θ�ֵ��ǰһλ����ǰ����
	}
	L.Length--;  // ����˳�����
	return true;
}

bool PrintList(SeqList& L) {
	// ��ʽ�����˳�������
	// �������˳������
	cout << "----------------------------------------" << endl;
	cout << "L.Length:>>" << L.Length << endl;
	cout << "L.MaxSize:>>" << L.MaxSize << endl;
	// ��ʽ�����������
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
	// �ж�L�Ƿ�Ϊ�ձ�
	if (L.Length == 0) {
		return true;
	}
	return false;
}

bool DestroyList(SeqList& L) {
	// �ͷ�˳���Ŀռ�
	if (L.data != nullptr) {  // ��ָ����ָ���ݲ��ǿ�ָ��ʱ����ʼ�ͷ�
		free(L.data);
		L.Length = 0;	//��������Ϊ0
		return true;
	}
	return false;
}

bool ExpansionList(SeqList& L, float ratio) {
	// ��˳����������
	int nextLevel = (int)(L.MaxSize * (1 + ratio));  // ���ݺ��С
	ElemType* temp = new ElemType[nextLevel];        //
	if (temp == nullptr) {                           // �ռ俪��ʧ�ܣ����ؿ�ָ��
		return false;
	}
	for (int i = 0; i < L.Length; i++) {
		temp[i] = L.data[i];  // ��ԭ˳������������ݰ��˵��µĿռ���
	}
	free(L.data);           // �ͷ�ԭ�ռ�
	L.data = temp;          // ԭָ��ָ���¿ռ�
	L.MaxSize = nextLevel;  // �������ߴ�
	return true;
}