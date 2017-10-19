#include <iostream>
using namespace std;

#define MAXSIZE 100
//���Ա��˳�򴢴�ʵ�� ��int��Ϊ��
struct List
{
	int Data[MAXSIZE];
	int last;           //���ڴ�����һ�����ݶ�Ӧ������
};
List *PtrL;

//�����յĹ̶��ռ�����Ա�
List *MakeEmpty(List *p)
{
	p = new List;
	p->last = 0;
	return p;
}

//�����̶��ռ�����Ա� (Ԫ������)
List *MakeEmptySeq(int n, List *p)
{
	p = new List;
	p->last = 0;
	int *t = new int[n];  //��ʱ�������
	cout << "This is another list,please input int array. Intput 0 to stop:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		if (t[i] == 0)break; //����0ֹͣ����
		p->last++;
	}
	int i, j, temp;
	for (i = 0; i<p->last - 1; i++) //��ʱ��������
		for (j = 0; j < p->last - 1 - i; j++)
		{
			if (t[j + 1] < t[j])
			{
				temp = t[j + 1]; t[j + 1] = t[j]; t[j] = temp;
			}
		}
	for (int i = 0; i < p->last; i++)//���ź��������������Ա���
	{
		p->Data[i] = t[i];
	}
	return p;
}


//����ڲ���һ����
void Insert(int X, int i, List *p)
{

	int j;
	if (p->last == MAXSIZE - 1)
	{
		cout << "����" << endl; return;
	}
	if (i<1 || i>p->last + 2)
	{
		cout << "λ�ò��Ϸ�" << endl; return;
	}
	for (j = p->last; j >= i - 1; j--) //jΪ�б��� iΪ������������λ��
		p->Data[j + 1] = p->Data[j];   //���ƶ��������ֵ
	p->Data[i - 1] = X;
	p->last++;
	return;
}

//����һ�������ҵ��򷵻ر��i��δ�ҵ��򷵻�NOT FIND
int Find(int X, List *p)
{
	int i = 0;
	while (i <= p->last && p->Data[i] != X) //��iС��last��δ�ҵ�X��i++
		i++;
	if (i > p->last)return -1;
	else return i + 1;
}

//ɾ����Ŷ�Ӧ����ֵ
void Delete(int i, List *p)
{
	if (i < 0 || i > p->last)
	{
		cout << "Number " << i << " element dosen't exist" << endl;
		return;
	}
	else
	{
		for (int j = i; j <= p->last; j++)
		{
			p->Data[j - 1] = p->Data[j];
		}
	}
	p->last--;
}

//�������һ����
void OrderInsert(int X, List *p)
{
	int i = 0;
	while (i < p->last&&p->Data[i] < X)i++;
	for (int j = p->last - 1; j >= i; j--)
		p->Data[j + 1] = p->Data[j];
	p->Data[i] = X;
	cout << "The subscript of the number:";
	cout << i + 1 << endl; //������������ڵ�λ��
	p->last++;
}
//ɾ��ָ��Ԫ��t
void Delete_num(int t, List *p)
{
	int i = 0, j = 0;
	for (j = 0; j < p->last; j++)
	{
		if (p->Data[j] == t)
		{
			for(int k=j;k<p->last-1;k++)
			p->Data[k] = p->Data[k+1];
			p->last--;
			break;
		}
	}
	cout << "Now,the array is:" << endl;
	for (j = 0; j < p->last; j++)cout << p->Data[j] << " ";
	cout << endl;
}
//ɾ������ָ��Ԫ��t
void Delete_num_all(int t, List *p)
{
	int i = 0, j = 0;
	int *a = new int[p->last];
	for (j = 0; j < p->last; j++)
	{
		if (p->Data[j] != t)
		{
			a[i] = p->Data[j];
			i++;
		}
	}
	if (i == j)cout << "-1";
	else
	{
		for (j = 0; j < i; j++)cout << a[j] << " ";
	}
	cout << endl;
}
//����ϲ��������Ա�
void MergeList(List La, List Lb, List Lc)
{
	int *pa = La.Data;
	int *pb = Lb.Data;
	int *pc = Lc.Data;
	int *t = Lc.Data;
	int *pa_last = La.Data + La.last - 1;
	int *pb_last = Lb.Data + Lb.last - 1;
	while (pa <= pa_last&&pb <= pb_last)
	{
		if (*pa <= *pb)*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last)*pc++ = *pa++;
	while (pb <= pb_last)*pc++ = *pb++;
	cout << "The merged array is:" << endl;
	for (int i = 0; t<pc; i++, t++)
	{
		cout << Lc.Data[i] << " ";
	}
	cout << endl;
}
//ɾ���ظ�Ԫ��
void Delete_rep(List *p)
{
	int k;
	int i = 1;
	int *a = new int[p->last]; //a[n]��Ž�� 
	a[0] = p->Data[0];         //����һ��Ԫ�ط���a[0] 
	for (int j = 1; j < p->last; j++) //j=1 �ӵ�2��Ԫ�ؿ�ʼ�Ƚ� 
	{
		for (k = 0; k < i; k++)
		{
			if (p->Data[j] == a[k])break; //���Data[j]����ǰ��Ԫ����ȣ�������Data[j] 
		}
		if (k == i)  //���û���ҵ����Ԫ�� ��Data[j]����a[i]�� 
		{
			a[i] = p->Data[j];
			i++;
		}
	}
	for (int k = 0; k < i; k++)
		cout << a[k] << " ";
	cout << endl;
}



int main()
{

	void Inster(int X, int i, List *p);
	void Delete(int i, List *p);
	int Find(int X, List *p);

	PtrL = MakeEmpty(PtrL);              //�����ձ�
	int X, i = 1, t;                     //XΪĿ������iΪ�±꣬tΪ�ж�����

										 //������ֵ
	do
	{
		cout << "Please input the target number you want to insert��  ";
		cin >> X;
		Insert(X, i, PtrL);
		i++;
		cout << "Insert  again  input  1 , otherwise  input  0 ��     ";
		cin >> t;
		cout << endl;
	} while (t);
	cout << endl;

	//�����ǰ�������
	cout << "Now,the list is:" << endl;
	for (int i = 0; i < PtrL->last; i++)
		cout << PtrL->Data[i] << "  ";
	cout << endl;
	cout << "The list has " << PtrL->last << " records" << endl;
	cout << endl;

	//������ֵ
	cout << "Please input the target number you want to find :";
	int t1, r1;                          //t1: target number  r1:return
	cin >> t1;
	r1 = Find(t1, PtrL);
	if (r1 == -1)cout << "NOT FIND." << endl;
	else cout << "The subscript of the target number is " << r1 << endl; //���Բ��Һ�����������ֵ�����±�
	cout << endl;

	//ɾ����ֵ
	cout << "Please input the subscript of the number you want to delete : ";
	int t2;
	cin >> t2;
	Delete(t2, PtrL);              //delete number
	cout << "Now,the list is:" << endl;
	for (int i = 0; i < PtrL->last; i++)
		cout << PtrL->Data[i] << "  ";
	cout << endl;
	cout << "The list has " << (PtrL->last)<< " records" << endl;

	//ɾ�����Ա�
	delete PtrL;                   //delete PtrL

	//ѡ�����ݣ�

	//�����µķǽ���˳���
	List l1, l2,l3,l4,l5;
	List *La, *Lb, *Lc,*Ld,*le;
	La = &l1; Lb = &l2; Lc = &l3; Ld = &l4;
	cout << endl << endl;
	cout << "Ordered array :La" << endl;
	La = MakeEmptySeq(MAXSIZE, La);
	//����һ����
	int X1;     //X1ΪĿ����
	cout << endl;
	cout << "Please input the number you want to insert into La��";
	cin >> X1;
	OrderInsert(X1, La);
	cout << endl;

	//ɾ��ָ��Ԫ��t
	int t11;
	cout << "Please input the number you want to delete from La��";
	cin >> t11;
	Delete_num(t11, La);
	//����ϲ�����
	cout << "Please input array,Lb,then you'll get Lc which is La merged with Lb" << endl;
	Lb = MakeEmptySeq(MAXSIZE, Lb);
	Lc = MakeEmpty(Lc);
	MergeList(*La, *Lb, *Lc);
	//ɾ������ָ��Ԫ��t
	cout << endl << "Delete all target numbers :" << endl;
	Ld = MakeEmptySeq(MAXSIZE, Ld);
	int t12;
	cout << "Please input the number you want to delete all from La��";
	cin >> t12;
	Delete_num_all(t12, Ld);
	cout << endl;

	//ɾ���ظ�Ԫ��
	cout << endl << "Delete all repeated numbers :" << endl;
	Ld = MakeEmptySeq(MAXSIZE, Ld);
	Delete_rep(Ld);
	cout << endl;
	cout << "END"<<endl;
	return 0;
}
