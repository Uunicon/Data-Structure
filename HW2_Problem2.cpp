#include<iostream>
using namespace std;

int num;//ȫ�ֱ��������˫��ѭ�������ڵ�Ԫ������
struct DuLNode 
{
	int data;
	struct DuLNode *prior;
	struct DuLNode *next;
};
//��������
DuLNode *CreateList_L(int n)
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
DuLNode *Insert(int X, int i, DuLNode*h)
{
	DuLNode *p, *s;//s����½�ָ��
	int t = i;           //��i�����ж��Ƿ�Ϊ1
	if (i<1 || i>num+1)  //������ڵ�i������Ҫ�����-1
	{
		cout << "-1";
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
	for (p = h, i = 0; i<num; p = p->next, i++)
		cout << p->data << " ";
	return h;
}

//����λ�ã�ɾ��һ����
DuLNode *Delete(int i, DuLNode *head)
{
	DuLNode *p, *q;
	p = head;
	if (i<1 || i>num)  //������ڵ�i������Ҫ�����-1
	{
		cout << "-1";
		return head;
	}
	for (int j = 1; j < i; j++) //��p�ƶ�������λ�õĺ�һ�ڵ�
		p = p->next;
	if (p == head) head = p->next; //��ɾ����һ��Ԫ�أ����ƶ�head
	p->next->prior = p->prior;
	p->prior->next = p->next;
	
	delete p;
	num--;
	for (q = head, i = 0; i<num; q = q->next, i++)
		cout << q->data << " ";
	return head;
}

DuLNode *Find(int X, DuLNode *head)
{
	DuLNode *p = head;
	int i;
	for ( i = 1; i <= num; i++,p=p->next)
		if (p->data == X)
		{
			cout << i << endl;
			break;
		}
	if (i > num) cout << "-1" << endl;
	return head;
}

int main()
{
	DuLNode *Head, *p;
	int n,i;
	cin >> n;
	num = n;
	Head = CreateList_L(n);
	for (p = Head,i=0; i<num; p = p->next,i++)
		cout << p->data << " ";

	cout << endl;
	int j, X;
	cin >> j >> X;
	Head = Insert(X, j, Head);
	cout << endl;

	int d;
	cin >> d;
	Head = Delete(d, Head);
	cout << endl;

	int X1;
	cin >> X1;
	Head = Find(X1, Head);
	cout << num << endl;
	return 0;
}