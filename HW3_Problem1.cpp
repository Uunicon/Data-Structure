#include<iostream>
#include<string>
using namespace std;

struct Stack
{
	int stacksize;
	int *base; //Õ»µ×
	int *top;  //Õ»¶¥
	int *s;    //Ö¸Ïò¶¯Ì¬ÉêÇëµÄÕ»
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
	if (t->base == t->top)
		cout << "Stack is Empty" << endl;
	else
	{
		x = *--t->top;
		cout << x << endl;
	}
	return  t;
}


Stack *Push_Stack(Stack *t,int x)
{
	if (t->top - t->base == t->stacksize)
		cout << "Stack is Full"<<endl;
	else
	{
		*(t->top) = x;
		t->top++;
	}
	return t;
}

Stack *Pop_All(Stack *t)
{
	while (t->top-t->base>0)
	{
		--t->top;
		cout << *(t->top) << " ";
	}
	return t;
}

int main()
{
	Stack *s;
	int n;
	string op;
	cin >> n;
	s = Create_Stack(n);
	while (op!="quit")
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
	s = Pop_All(s);
	return 0;
}