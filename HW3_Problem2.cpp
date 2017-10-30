#include<iostream>
#include<cmath>
#include<string.h>
#define MAX 15
using namespace std;


struct Stack
{
	int stacksize;
	int *base; //ջ��
	int *top;  //ջ��
	int *s;    //ָ��̬�����ջ
};

Stack *Create_Stack(int n)
{
	Stack *t;
	t = new Stack;
	t->s = new int[n];
	t->stacksize = n;
	t->base = t->top = &(t->s[0]);
	return t;
}

Stack *Pop_Stack(Stack *t)
{
	int x;
	x = *--t->top;
	cout << x << endl;
	return  t;
}

Stack *Push_Stack(Stack *t, int x)
{
	*(t->top) = x;
	t->top++;
	return t;
}

Stack *Pop_All(Stack *t)
{
	int x;
	while (t->top - t->base>0)
	{
		--t->top;
		x = *(t->top);
		if (x >= 0 && x <= 9)cout << char(x + 48);
		else cout << char(x+55);
	}
	cout << endl;
	return t;
}

int main()
{
	int t1,t2; //t1Ϊת��ǰ����   t2Ϊת��������
	Stack *s;
	s = Create_Stack(MAX);
	cin >> t1 >> t2;
	int a=0;     //��xת��Ϊ10���Ʒ���a��
	int n = 0;  
	int len;
	int temp;
	char x[10000];    //xΪ��ת������
	cin >> x;
	len = strlen(x);
	for (int i = 0; i < len; i++)
	{
		if (x[i] >= '0' && x[i] <= '9') temp = int(x[i])-48;
		else  temp = int(x[i]) - 55;
		a = a + temp*pow(t1,len-i-1);
	}
	while (a != 0)
	{
		s = Push_Stack(s, a%t2);
		a = a / t2;
	}
	s = Pop_All(s);
	return 0;
}