#include<iostream>
using namespace std;

int Cnum;//ȫ�ֱ�������ŵ���ѭ�������ڵ�Ԫ������
struct CirLNode
{
	int data;
	struct CirLNode *next;
};
//��������
CirLNode *CreateList_Cir(int n)
{
	CirLNode *Head, *p;
	Head = p = new CirLNode;
	cin >> Head->data;
	Head->next = Head;
	for (int i = 1; i < n; i++)
	{
		p->next = new CirLNode;
		p = p->next;
		cin >> p->data;
	}
	p->next = Head;
	return Head;
}//CreateList

 //����λ�ã�����һ����
CirLNode *Insert_Cir(int X, int i, CirLNode*h)
{
	CirLNode *p, *s;//s����½�ָ��
	int t = i;           //��i�����ж��Ƿ�Ϊ1
	if (i<1 || i>Cnum + 1)  //������ڵ�i������Ҫ�����-1
	{
		cout << "����ʧ��";
		return h;
	}
	if (i == 1) //��iǡ�ò��뵽��һ���ڵ�֮ǰ��������Ϊ�嵽���һ���ڵ�֮��
		i = i + Cnum;
	p = h;
	s = new CirLNode;
	s->data = X;
	for (int j = 1; j < i - 1; j++) //��p�ƶ�������λ�õĺ�һ�ڵ�
		p = p->next;
	s->next = p->next;
	p->next = s;
	Cnum++;
	if (t == 1) h = s; //�������Ϊ1����ı�ͷ���
	cout << "��ǰ����Ϊ��" << endl;
	for (p = h, i = 0; i<Cnum; p = p->next, i++)
		cout << p->data << " ";
	cout << endl;
	return h;
}

//����λ�ã�ɾ��һ����
CirLNode *Delete_Cir(int i, CirLNode *head)
{
	CirLNode *p, *q, *s;
	p = head;
	if (i<1 || i>Cnum)  //������ڵ�i������Ҫ�����-1
	{
		cout << "ɾ��ʧ��";
		return head;
	}
	if (i == 1)
	{
		while (p->next != head)
			p = p->next;
		s = head;
		p->next = head->next;
		head = head->next;
		delete s;
	}
	else
	{
		for (int j = 1; j < i - 1; j++) //��p�ƶ���ɾ��λ�õĺ�һ�ڵ�
			p = p->next;
		s = p->next;
		p->next = p->next->next;
		delete s;
	}
	Cnum--;
	cout << "��ǰ����Ϊ��" << endl;
	for (q = head, i = 0; i<Cnum; q = q->next, i++)
		cout << q->data << " ";
	cout << endl;
	return head;
}

// ��ֵ���ң������±�
CirLNode *Find_Cir(int X, CirLNode *head)
{
	CirLNode *p = head;
	int i;
	for (i = 1; i <= Cnum; i++, p = p->next)
		if (p->data == X)
		{
			cout << "��Ԫ��Ϊ�� " << i << " ��Ԫ��" << endl;
			break;
		}
	if (i > Cnum) cout << "δ�ҵ�" << endl;
	return head;
}


int main()
{
	CirLNode *CHead, *Cp;
	int Cn, Ci;
	cout << "�����봴���ĵ������Ԫ�ظ�����";
	cin >> Cn;
	Cnum = Cn;
	cout << endl;
	cout << "���������Ԫ�أ��ո�ָ����س�������" << endl;
	CHead = CreateList_Cir(Cn);
	cout << endl;
	cout << "��ǰ����Ϊ��" << endl;
	for (Cp = CHead, Ci = 0; Ci<Cnum; Cp = Cp->next, Ci++)
		cout << Cp->data << " ";

	cout << endl;
	int Cj, CX;
	cout << "�����������ֵ���±ꡢ�������ֵ��";
	cin >> Cj >> CX;
	CHead = Insert_Cir(CX, Cj, CHead);
	cout << endl;

	int Cd;
	cout << "�������ɾ�������±꣺";
	cin >> Cd;
	CHead = Delete_Cir(Cd, CHead);
	cout << endl;

	int CX1;
	cin >> CX1;
	cout << "����������ҵ���ֵ��";
	CHead = Find_Cir(CX1, CHead);
	cout << "��ǰ�����Ԫ�ظ���Ϊ�� ";
	cout << Cnum << endl;
	return 0;
}