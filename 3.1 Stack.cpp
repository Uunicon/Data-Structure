#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//顺序栈-------------------------------------------------------------------------------------------------------------
struct Stack
{
	int stacksize;
	int *base; //栈底
	int *top;  //栈顶
	int *s;    //指向动态申请的栈
};

//顺序栈初始化
Stack *Create_Stack(int n)
{
	Stack *t;
	t = new Stack;
	t->s = new int[n];
	t->stacksize = n;
	t->base = t->top = &(t->s[0]);
	return t;
}

//顺序栈出栈
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

//顺序栈入栈
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

//顺序栈 POP 所有元素
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

//链栈----------------------------------------------------------------------------------------------------------------
int Ch_MAX; //记录链栈单元数
int Ch_n;   //记录目前链栈储存单元数
			//链栈
struct Chain_Stack
{
	int data;
	Chain_Stack *next;
};

//链栈初始化
Chain_Stack *Ch_Create_Stack(int MAX)
{
	Chain_Stack *t, *s;
	t = new Chain_Stack;
	t->next = NULL;             //栈底最后一个指针为空
	for (int i = 1; i < MAX; i++)
	{
		s = new Chain_Stack;
		s->next = t;
		t = s;
	}
	Ch_n = 0;                      //栈内元素为0
	return t;
}


//链栈出栈
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

//链栈入栈
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

//链栈 POP所有元素
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


//数制转换-----------------------------------------------------------------------------------------------------------------------

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
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;
	cout << endl;
	cout << "顺序栈:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;

	Stack *s;
	int n;
	string op;
	cout << "请输入栈的元素个数：";
	cin >> n;
	s = Create_Stack(n);
	cout << "请输入操作符：" << endl;
	cout << "**********  pop : 出栈  **********  push X : 将 X 入栈  **********  quit : POP所有元素  **********" << endl;
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
	cout << "栈内所有元素为：" << endl;
	cout << endl;
	s = Pop_All(s);

	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;
	cout << endl;
	cout << "链栈:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;

	Chain_Stack *Ch_s;
	string Ch_op;
	cout << "请输入栈的元素个数：";
	cin >> Ch_MAX;
	Ch_s = Ch_Create_Stack(Ch_MAX);
	cout << "请输入操作符：" << endl;
	cout << "**********  pop : 出栈  **********  push X : 将 X 入栈  **********  quit : POP所有元素  **********" << endl;
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
	cout << "栈内所有元素为：" << endl;
	cout << endl;
	Ch_s = Ch_Pop_All(Ch_s);

	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;
	cout << endl;
	cout << "数制转换:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;
	cout << "请输入转换前数制 转换后数制:" << endl;
	cout << "***** 如： 2 10 *****:" << endl;
	cout << endl;
	int t1, t2; //t1为转换前数制   t2为转换后数制
	Stack *CV_s;
	CV_s = Create_Stack(15);

	cin >> t1 >> t2;
	int a = 0;     //将x转化为10进制放入a中
	int len;
	int temp;
	char x[10000];    //x为待转换的数
	cout << "请输入待转换的数:" << endl;
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
	cout << "结果为：" << endl;
	cout << endl;
	CV_s = CV_Pop_All(CV_s);
	return 0;
}