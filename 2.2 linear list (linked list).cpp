#include<iostream>
using namespace std;
struct LNode {
	int data;
	struct LNode *next;
};

int num;//ȫ�ֱ��������˫��ѭ�������ڵ�Ԫ������
struct DuLNode
{
	int data;
	struct DuLNode *prior;
	struct DuLNode *next;
};

int Cnum;//ȫ�ֱ�������ŵ���ѭ�������ڵ�Ԫ������
struct CirLNode
{
	int data;
	struct CirLNode *next;
};

//--------------------------------------------------------------------------------------------------------
//��������
//��������
LNode *CreateList_L(int n)
{
	LNode *Head, *p, *L;
	Head = new LNode;
	Head->next = NULL;
	L = Head;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data;
		if (Head == L)
		{
			L->next = p; p->next = NULL;
			L = p;
		}
		else
		{
			p->next = L;
			Head->next = p;
			L = p;
		}
	}
	return Head;
}//CreateList

//���ҽ��
LNode *FindKth(int k, LNode *head)
{
	LNode *p = head;
	int i = 1;
	while (p != NULL&&i < k)
	{
		p = p->next;
		i++;
	}
	if (i == k)return p;
	else return NULL;
}//FindKth

//����
LNode *Insert(int X, int i, LNode*h)
{
	LNode *p, *s;
	if (i == 1)
	{
		s = new LNode;
		s->data = X;
		s->next = h->next;
		h->next = s;
		for (p = h->next; p; p = p->next)
			cout << p->data << " ";
		return h;
	}
	p = FindKth(i - 1, h->next);
	if (p == NULL)
	{
		cout << "����ʧ��";
		return h;
	}
	else
	{
		s = new LNode;
		s->data = X;
		s->next = p->next;
		p->next = s;
		cout << "��ǰ����Ϊ��" << endl;
		for (p = h->next; p; p = p->next)
			cout << p->data << " ";
		cout << endl;
		return h;
	}
}//Insert

//ɾ��
LNode *Delete(int i, LNode *head)
{
	LNode *p,*q;
	p = head;
	int j = 0;
	while (p->next&&j<i-1)
	{
		p = p->next; ++j;
	}
	if(!(p->next)||j>i-1)
	{
		cout << "ɾ��ʧ��" ;
		return head;
	}
	q = p->next; p->next = q->next;
	delete q;
	cout << "��ǰ����Ϊ��" << endl;
	for (p = head->next; p; p = p->next)
		cout << p->data << " ";
	cout << endl;
	return head;
}

//���������
LNode *ReverseList_L(LNode *head)
{
	LNode *H_t, *p, *L, *q;
	H_t = new LNode;
	H_t->next = NULL;
	L = H_t;
	for (q = head->next; q; q = q->next)
	{
		p = new LNode;
		p->data = q->data;
		if (H_t == L)
		{
			L->next = p; p->next = NULL;
			L = p;
		}
		else
		{
			p->next = L;
			H_t->next = p;
			L = p;
		}
	}
	return H_t;
}

//ɾ���������ظ�Ԫ��
LNode *DeleteRe(LNode *head)
{
	LNode *p = head;
	LNode *h1 = head;  //���ڱ���Ŀ�������ڵ�����Ԫ��
	LNode *s;        //ָ���ɾ���Ľڵ�
	p = p->next;    //����ͷ��㣬��ָ����ڵ�һ��Ԫ�ش�
	h1 = h1->next;
	int n = 1;  //nΪ��ǰ������Ԫ������
	int j;
	while (p->next)
	{
		for (j = 0; j < n; j++) // ����һ��Ԫ���뵱ǰ����������Ԫ�ؽ��бȽ�
		{
			if (h1->data == p->next->data) //�����ɾȥ�ýڵ�
			{
				s = p->next;             //���´�ɾ���Ľ�� 
				if (p->next->next != NULL)
					p->next = p->next->next;
				else p->next = NULL;    //���ýڵ�Ϊ���һ���ڵ㣬��next��Ϊ�� 
				delete s;
				break;
			}
			h1 = h1->next;
		}
		if (j == n)
		{
			p = p->next;
			n++;
		}
		h1 = head->next;       //ÿ�β��ҽ�����h1�ص���һ��Ԫ�ص�λ��
	}
	for (p = head->next; p; p = p->next)
		cout << p->data << " ";
	cout << endl;
	return head;
}//DeleteRe

//��ֵ���ң������±�
LNode *Find(int X, LNode *head)
{
	LNode *p = head;
	int i = 0;
	while (p->data != X)
	{
		p = p->next;
		i++;
		if (p == NULL)break;
	}
	if (p==NULL)
	{
		cout << "δ�ҵ�" << endl;
		return head;
	}
	else
	{
		cout <<"��Ԫ��Ϊ�� "<<i<<" ��Ԫ��"<<endl;
		return head;
	}
}//Find

//ͳ��Ԫ�ظ���
int Count(LNode *head)
{
	int i = 0;
	LNode *p = head;
	for (; p; p = p->next)
		i++;
	return i-1;
}

//--------------------------------------------------------------------------------------------------------

//˫��ѭ��������
//��������
DuLNode *CreateList_DUL(int n)
{
	DuLNode *Head, *p;
	Head = p = new DuLNode;
	cin >> Head->data;
	Head->next = Head;
	Head->prior = Head;
	for (int i = 1; i < n; i++)
	{
		p->next = new DuLNode;
		p->next->prior = p;
		p = p->next;
		cin >> p->data;
	}
	p->next = Head;
	Head->prior = p;
	return Head;
}//CreateList

 //����λ�ã�����һ����
DuLNode *Insert_DUL(int X, int i, DuLNode*h)
{
	DuLNode *p, *s;//s����½�ָ��
	int t = i;           //��i�����ж��Ƿ�Ϊ1
	if (i<1 || i>num + 1)  //������ڵ�i������Ҫ�����-1
	{
		cout << "����ʧ��";
		return h;
	}
	if (i == num + 1) //��iǡ�ò��뵽���һ���ڵ�֮�󣬽�����Ϊ�嵽��һ���ڵ�֮ǰ
		i = i - num;
	p = h;
	s = new DuLNode;
	s->data = X;
	for (int j = 1; j < i; j++) //��p�ƶ�������λ�õĺ�һ�ڵ�
		p = p->next;
	p->prior->next = s;
	s->next = p;
	s->prior = p->prior;
	p->prior = s;
	num++;
	if (t == 1) h = s; //�������Ϊ1����ı�ͷ���
	cout << "��ǰ����Ϊ��" << endl;
	for (p = h, i = 0; i<num; p = p->next, i++)
		cout << p->data << " ";
	cout << endl;
	return h;
}

//����λ�ã�ɾ��һ����
DuLNode *Delete_DUL(int i, DuLNode *head)
{
	DuLNode *p, *q;
	p = head;
	if (i<1 || i>num)  //������ڵ�i������Ҫ�����-1
	{
		cout << "ɾ��ʧ��";
		return head;
	}
	for (int j = 1; j < i; j++) //��p�ƶ�������λ�õĺ�һ�ڵ�
		p = p->next;
	if (p == head) head = p->next; //��ɾ����һ��Ԫ�أ����ƶ�head
	p->next->prior = p->prior;
	p->prior->next = p->next;

	delete p;
	num--;
	cout << "��ǰ����Ϊ��" << endl;
	for (q = head, i = 0; i<num; q = q->next, i++)
		cout << q->data << " ";
	cout << endl;
	return head;
}
//��ֵ���ң������±�
DuLNode *Find_DUL(int X, DuLNode *head)
{
	DuLNode *p = head;
	int i;
	for (i = 1; i <= num; i++, p = p->next)
		if (p->data == X)
		{
			cout << "��Ԫ��Ϊ�� " << i << " ��Ԫ��" << endl;
			break;
		}
	if (i > num) cout << "δ�ҵ�" << endl;
	return head;
}

//---------------------------------------------------------------------------------------------------------

//����������
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
	
	LNode *Head, *p;
	//��������
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;
	cout << endl;
	cout << "��������:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;

	
	int n;
	cout << "�����봴���ĵ������Ԫ�ظ�����";
	cin >> n;
	cout << endl;
	cout << "���������Ԫ�أ��ո�ָ����س�������" << endl;
	Head = CreateList_L(n);        //���򴴽�����
	cout << endl;
	cout << "��ǰ����Ϊ��" << endl;
	for (p = Head->next; p; p = p->next)
		cout << p->data << " ";
	cout << endl;

	cout << endl;
	cout << "�����������ֵ���±ꡢ�������ֵ��";
	int i, X;
	cin >> i >> X;
	Head = Insert(X, i, Head);      //������ֵ
	cout << endl;

	cout << "�������ɾ�������±꣺";
	int d;
	cin >> d;
	Head = Delete(d, Head);           //ɾ����ֵ
	cout << endl;

	cout << "���ú������Ϊ��" << endl;
	Head = ReverseList_L(Head);
	for (p = Head->next; p; p = p->next)
		cout << p->data << " ";
	cout << endl;
	cout << endl;

	cout << "ȥ�غ������Ϊ��" << endl;
	Head = DeleteRe(Head);
	cout << endl;


	cout << "����������ҵ���ֵ��";
	int X1;
	cin >> X1;
	Head = Find(X1,Head);

	cout << endl;
	cout << "��ǰ�����Ԫ�ظ���Ϊ�� ";
	cout << Count(Head) << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;

	cout << endl;
	cout << endl;
	cout << "˫��ѭ������:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;
	//˫��ѭ������
	DuLNode *DHead, *Dp;
	int Dn, Di;
	cout << "�����봴���ĵ������Ԫ�ظ�����";
	cin >> Dn;
	num = Dn;
	cout << endl;
	cout << "���������Ԫ�أ��ո�ָ����س�������" << endl;
	DHead = CreateList_DUL(Dn);
	cout << endl;
	cout << "��ǰ����Ϊ��" << endl;
	for (Dp = DHead, Di = 0; Di<num; Dp = Dp->next, Di++)
		cout << Dp->data << " ";

	cout << endl;
	int Dj, DX;
	cout << "�����������ֵ���±ꡢ�������ֵ��";
	cin >> Dj >> DX;
	DHead = Insert_DUL(DX, Dj, DHead);
	cout << endl;

	int Dd;
	cout << "�������ɾ�������±꣺";
	cin >> Dd;
	DHead = Delete_DUL(Dd, DHead);
	cout << endl;

	int DX1;
	cout << "����������ҵ���ֵ��";
	cin >> DX1;
	DHead = Find_DUL(DX1, DHead);
	cout << "��ǰ�����Ԫ�ظ���Ϊ�� ";
	cout << num << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;

	cout << endl;
	cout << endl;
	cout << "����ѭ������:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;
	//����ѭ������
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
	cout << "����������ҵ���ֵ��";
	cin >> CX1;
	CHead = Find_Cir(CX1, CHead);
	cout << "��ǰ�����Ԫ�ظ���Ϊ�� ";
	cout << Cnum << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;
	return 0;
}