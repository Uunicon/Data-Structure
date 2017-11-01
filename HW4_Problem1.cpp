#include<iostream>
#include<string>
using namespace std;
struct QNode   //���н��
{
	int data;
	struct QNode *next;
};
struct QPtr   //����ͷ��βָ��
{
	QNode *front;
	QNode *rear;
}LQ;
int Q_MAX;    //����Ԫ�����ֵ
int Q_n;      //��ǰ����Ԫ�ظ���
//��������ͷ�巨�������� 
void CreateQueue(int n)
{
	QNode *p,*L;
	LQ.front = new QNode;
	LQ.front->next = NULL;
	L = LQ.rear = LQ.front;
	Q_n = 0;
	for (int i = 0; i < n; i++)
	{
		p = new QNode;
		L->next = p;
		L = p;
	}
}//CreateQueue

void DeQueue()
{
	QNode *s;
	if (Q_n ==0 )
		cout << "Queue is Empty" << endl;
	else
	{
		s = LQ.front->next;
		if (Q_n == 1)
			LQ.rear = LQ.front;
		else
		    LQ.front->next = LQ.front->next->next; 
		cout << s->data << endl;
		Q_n--;
		delete s;
	}
}

void EnQueue(int x)
{
	QNode *p;
	if (Q_n == Q_MAX)
		cout << "Queue is Full" << endl;
	else
	{
		p = new QNode;
		p->data = x;
		LQ.rear->next = p;
		LQ.rear = p;
		Q_n++;
	}
}

void QuitQueue()
{
	QNode *p;
	while (Q_n)
	{
		p = LQ.front->next;
		LQ.front->next = LQ.front->next->next;
		cout << p->data << " ";
		delete p;
		Q_n--;
	}
}

int main()
{
	string Ch_op;
	cin >> Q_MAX;
	CreateQueue(Q_MAX);
	while (Ch_op != "quit")
	{
		cin >> Ch_op;
		if (Ch_op == "dequeue")DeQueue();
		if (Ch_op == "enqueue")
		{
			int x;
			cin >> x;
			EnQueue(x);
		}
	}
	QuitQueue();
	return 0;
}