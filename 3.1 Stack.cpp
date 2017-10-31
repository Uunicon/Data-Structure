#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//˳��ջ-------------------------------------------------------------------------------------------------------------
struct Stack
{
	int stacksize;
	int *base; //ջ��
	int *top;  //ջ��
	int *s;    //ָ��̬�����ջ
};

//˳��ջ��ʼ��
Stack *Create_Stack(int n)
{
	Stack *t;
	t = new Stack;
	t->s = new int[n];
	t->stacksize = n;
	t->base = t->top = &(t->s[0]);
	return t;
}

//˳��ջ��ջ
Stack *Pop_Stack(Stack *t)
{
	int x;
	if (t->base == t->top)
		cout << "Stack is Empty" << endl;
	else
	{
		x = *--t->top;
		cout << x << endl;
	}
	cout << endl;
	return  t;
}

//˳��ջ��ջ
Stack *Push_Stack(Stack *t, int x)
{
	if (t->top - t->base == t->stacksize)
		cout << "Stack is Full" << endl;
	else
	{
		*(t->top) = x;
		t->top++;
	}
	cout << endl;
	return t;
}

//˳��ջ POP ����Ԫ��
Stack *Pop_All(Stack *t)
{
	while (t->top - t->base>0)
	{
		--t->top;
		cout << *(t->top) << " ";
	}
	cout << endl;
	return t;
}

//��ջ----------------------------------------------------------------------------------------------------------------
int Ch_MAX; //��¼��ջ��Ԫ��
int Ch_n;   //��¼Ŀǰ��ջ���浥Ԫ��
			//��ջ
struct Chain_Stack
{
	int data;
	Chain_Stack *next;
};

//��ջ��ʼ��
Chain_Stack *Ch_Create_Stack(int MAX)
{
	Chain_Stack *t, *s;
	t = new Chain_Stack;
	t->next = NULL;             //ջ�����һ��ָ��Ϊ��
	for (int i = 1; i < MAX; i++)
	{
		s = new Chain_Stack;
		s->next = t;
		t = s;
	}
	Ch_n = 0;                      //ջ��Ԫ��Ϊ0
	return t;
}


//��ջ��ջ
Chain_Stack *Ch_Pop_Stack(Chain_Stack *t)
{
	Chain_Stack *s;
	if (Ch_n == 0)
		cout << "Stack is Empty" << endl;
	else
	{
		s = t;
		t = t->next;
		cout << s->data << endl;
		delete s;
		Ch_n--;
	}
	cout << endl;
	return  t;
}

//��ջ��ջ
Chain_Stack *Ch_Push_Stack(Chain_Stack *t, int x)
{
	Chain_Stack *p, *s;
	if (Ch_n == Ch_MAX)
		cout << "Stack is Full" << endl;
	else
	{
		s = new Chain_Stack;
		s->next = t;
		s->data = x;
		t = s;
		Ch_n++;
	}
	cout << endl;
	return t;
}

//��ջ POP����Ԫ��
Chain_Stack *Ch_Pop_All(Chain_Stack *t)
{
	Chain_Stack *s;
	while (Ch_n)
	{
		s = t;
		t = t->next;
		cout << s->data << endl;
		Ch_n--;
		delete s;
	}
	cout << endl;
	return t;
}


//����ת��-----------------------------------------------------------------------------------------------------------------------

Stack *CV_Pop_Stack(Stack *t)
{
	int x;
	x = *--t->top;
	cout << x << endl;
	return  t;
}

Stack *CV_Push_Stack(Stack *t, int x)
{
	*(t->top) = x;
	t->top++;
	return t;
}

Stack *CV_Pop_All(Stack *t)
{
	int x;
	while (t->top - t->base>0)
	{
		--t->top;
		x = *(t->top);
		if (x >= 0 && x <= 9)cout << char(x + 48);
		else cout << char(x + 55);
	}
	cout << endl;
	return t;
}
int main()
{
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;
	cout << endl;
	cout << "˳��ջ:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;

	Stack *s;
	int n;
	string op;
	cout << "������ջ��Ԫ�ظ�����";
	cin >> n;
	s = Create_Stack(n);
	cout << "�������������" << endl;
	cout << "**********  pop : ��ջ  **********  push X : �� X ��ջ  **********  quit : POP����Ԫ��  **********" << endl;
	while (op != "quit")
	{
		cin >> op;
		if (op == "pop") s = Pop_Stack(s);
		if (op == "push")
		{
			int x;
			cin >> x;
			s = Push_Stack(s, x);
		}
	}
	cout << endl;
	cout << "ջ������Ԫ��Ϊ��" << endl;
	cout << endl;
	s = Pop_All(s);

	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;
	cout << endl;
	cout << "��ջ:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;

	Chain_Stack *Ch_s;
	string Ch_op;
	cout << "������ջ��Ԫ�ظ�����";
	cin >> Ch_MAX;
	Ch_s = Ch_Create_Stack(Ch_MAX);
	cout << "�������������" << endl;
	cout << "**********  pop : ��ջ  **********  push X : �� X ��ջ  **********  quit : POP����Ԫ��  **********" << endl;
	while (Ch_op != "quit")
	{
	
		cin >> Ch_op;
		if (Ch_op == "pop") Ch_s = Ch_Pop_Stack(Ch_s);
		if (Ch_op == "push")
		{
			int x;
			cin >> x;
			Ch_s = Ch_Push_Stack(Ch_s, x);
		}
	}
	cout << endl;
	cout << "ջ������Ԫ��Ϊ��" << endl;
	cout << endl;
	Ch_s = Ch_Pop_All(Ch_s);

	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;
	cout << endl;
	cout << "����ת��:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //��ʽ����
	cout << endl;
	cout << "������ת��ǰ���� ת��������:" << endl;
	cout << "***** �磺 2 10 *****:" << endl;
	cout << endl;
	int t1, t2; //t1Ϊת��ǰ����   t2Ϊת��������
	Stack *CV_s;
	CV_s = Create_Stack(15);

	cin >> t1 >> t2;
	int a = 0;     //��xת��Ϊ10���Ʒ���a��
	int len;
	int temp;
	char x[10000];    //xΪ��ת������
	cout << "�������ת������:" << endl;
	cout << endl;
	cin >> x;
	len = strlen(x);
	for (int i = 0; i < len; i++)
	{
		if (x[i] >= '0' && x[i] <= '9') temp = int(x[i]) - 48;
		else  temp = int(x[i]) - 55;
		a = a + temp*pow(t1, len - i - 1);
	}
	while (a != 0)
	{
		CV_s = CV_Push_Stack(CV_s, a%t2);
		a = a / t2;
	}
	cout << endl;
	cout << "���Ϊ��" << endl;
	cout << endl;
	CV_s = CV_Pop_All(CV_s);
	return 0;
}