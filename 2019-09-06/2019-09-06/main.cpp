//
//����⣺
//
//1.�������s = 3!+ 5!+ 7!
#include "stdio.h"
int main()
{
	int t = 1;
	int s = 0;
	for (int i = 1; i <= 7; i++)
	{
		t *= i;
		if (i % 2 == 1)
		{
			s += t;
		}
	}
	printf("%d\n", s - 1);
	system("pause");
}

//2.����һ���ַ������ֱ�ͳ�����еĴ�д��ĸ��Сд��ĸ�������ַ��������ַ��ĸ�����
#include<stdio.h>
#include<string.h>
void main()
{
	char ch[100];
	int a = 0, b = 0, c = 0, d = 0, i = 0;
	printf("������ :");
	gets_s(ch);
	while (ch[i] != '\0')
	{
		if (ch[i] >= 'A'&&ch[i] <= 'Z')a++;
		else if (ch[i] >= 'a'&&ch[i] <= 'z')b++;
		else if (ch[i] >= '0'&& ch[i] <= '9')c++;
		else d++;
		i++;
	}
	printf("��д��ĸ��%d\n", a);
	printf("Сд��ĸ��%d\n", b);
	printf("������ĸ��%d\n", c);
	printf("������ĸ��%d\n", d);
	system("pause");
}

//3.��д����ʵ������ͼ�������Ρ�ͼ���������
//  *
// ***
//******
// ***
//  *
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x, y, z;
	//��3��
	for (x = 1; x <= 5; x += 2)//��ѭ������ѭ������(��3��)
	{
		for (y = (5 - x) / 2; y >= 1; y--)//����ÿ���пո�ĸ���
		{
			printf(" ");//��������ո�
		}
		for (z = 1; z <= x; z++)//������ѭ���е�x��ֵ����z(Ҳ����ÿ��"*"�ĸ���)
		{
			printf("*");//�ڿո�������ÿ�е�"*"
		}
		printf("\n");//ÿ���һ�к��У��Է��������һ��
	}
	//��2��(��������3�����ƣ�������ע��)
	for (x = 3; x >= 1; x -= 2)
	{
		for (y = (5 - x) / 2; y >= 1; y--)
		{
			printf(" ");
		}
		for (z = 1; z <= x; z++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

//4.  ��дһ��ѡƱͳ�Ƶĳ��򡣹����������£�
//��С�ţ�С�С����С��4���˺�ѡ�˲μӾ�ѡ��
//ÿ��ͶƱ��ֻ�������ĸ����м�ѡȡ������Ͷ��ȨƱ��
//��Ʒ�����������ÿ����ѡ�ߵĵ�Ʊ���Լ���ȨƱ����
//������е���ߵ�Ʊ�ˡ�
//

//5.����10���������ҵ���10�����е����������С���Լ��������ڵ��±�λ�á�
#include <stdio.h>

int main()
{
	int a[10], i, min = 0, max = 0;

	for (i = 0; i < 10; i++) {
		scanf_s("%d", a + i);
		if (a[min] > a[i])
			min = i;
		else if (a[max] < a[i])
			max = i;
	}
	printf("�������%d���±���%d����С����%d���±���%d\n", a[max], max, a[min], min);
	system("pause");
	return 0;
}

//6.	��̴Ӽ������������ַ�, ֱ�������ַ���*��Ϊֹ, ͳ�����е���ĸ�ַ��������ַ����ո���������ַ��ĸ��������ͳ�ƽ����
//�������20��int���͵�����Ԫ�أ�����ð�����򷨰��������С�
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void bubblesort(int a[], int n)//nΪ����a��Ԫ�ظ���
{
	int i, j, k, temp;
	for (j = 0; j<n - 1; j++)
	{
		for (i = 0; i<n - 1 - j; i++)
		{
			if (a[i]>a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
	printf("������:");
	for (k = 0; k < n; k++)
	{
		printf("%d ", a[k]);
	}
	printf("\n");
}
void main()
{
	int i, num[20];
	//�������20����
	srand((int)time(NULL));
	for (i = 0; i < 20; i++)
	{
		num[i] = rand() % 1000;
	}
	//����
	bubblesort(num, 20);
	system("pause");
}

//7.��һ���Ѿ��ź��������a�в���һ������Ҫ�����������԰�ԭ���Ĺ�������Ȼ���ٽ�������ĵ�3��Ԫ��ɾ����
//����ʵ�ָò�������ʾ�����ɾ���Ժ�����顣
#include<stdio.h>
int main()
{
	int c, i, b, a[5] = { 1, 2, 3, 5, 6 }, s[6];
	scanf_s("%d", &c);
	printf("ԭ���� ");
	for (i = 0; i<5; i++)
		printf("%d ", a[i]);
	for (i = 0; i <= 5; i++)
	{
		if (a[i]>c)   //�ҵ�Ӧ�ò����λ��
			break;
		else s[i] = a[i];
	}
	s[i] = c;   //a[3]=4
	for (b = i; b <= 5; b++)
	{
		s[b + 1] = a[b];
	}
	printf("\n�����");
	for (i = 0; i <= 5; i++)
		printf("%d ", s[i]);
	printf("\n");
	int  j = 0, k = 0;
	for (j = 2; j <= 4; j++)
		s[j] = s[j + 1];
	printf("ɾ��������Ϊ ");
	for (k = 0; k <= 4; k++)
	{
		printf("%d ", s[k]);
	}
	system("pause");
	return 0;
}


//�����⣺

/*1.*/
#include "stdio.h"
main()
{
	char s[] = "ABCDE", *p;
	for (p = s; p <= s + 4; p = p + 2)
		printf("%s\n", p);
}

//��������
//ABCDE
//CDE
//E

/*2.*/
#include "stdio.h"
main()
{
	int i, k = 0, s = 0, a[10];
	scanf("%d", &a[k]);
	while (a[k] != 0)
	{
		s = s + a[k];
		k++;
		scanf("%d", &a[k]);
	}
	printf("sum = %d\n", s);
}

//����ʱ���룺1 2 3 4 5 6 7 8 9 0
//�����45

/*3.*/ 
#include "stdio.h"
main()
{
	int a[10] = { 2, 5, 12, 13, 23, 25, 26, 87, 113, 123 }, x, *q;
	q = a; x = *q;
	while (q<a + 9)
	{
		*q = *(q + 1); q++;
	}
	*q = x;
	for (q = a; q<a + 10; q++)
		printf("% 4d", *q);
}

//�����5 12 13 23 25 26 87 113 123   2

/*4��*/
void f(int x)
{
	int i = 1;
	static int m = 1;
	i = i + x; m = m + x;
	printf("%d, %d\n", i, m);
	return;
}
main()
{
	int i;
	for (i = 1; i <= 3; i++)
		f(i);
}

//��������2��2
//3��4
//4��7

/*5.*/
int x = 100, y = 200;
int sub(int y)
{
	y = x<y ? x : y;
	return y;
}
main()
{
	{ int x = 50;
	printf("%d\n", sub(x));
	}
	printf("%d, %d\n", x, y);
}

//��������50
//100��200

//6.
# include ��stdio.h��
main()
{
	int n[2], i, j, k;
	for (i = 0; i<2; i++)  n[i] = 0;
	k = 2;
	for (i = 0; i<k; i++)
	for (j = 0; j<k; j++)  n[j] = n[i] + 1;
	printf("%d\n", n[k]);
}

//��������n[k]ʵ���ϳ��������鷶Χ�������ʱ��n[2]ֻ��0��1�����±꣬����k = 2��n[k
//]�����ڣ���ȷ��ֵ��
//�����м��ѭ����ͬ���裬û�й�ϵ��


/*7.*/
#include"stdio.h"
void  covf(int *s, int n);
main()
{
	int i;
	int a[10];
	for (i = 0; i<10; i++)
		a[i] = i + i;
	covf(a, 10);
	for (i = 0; i<10; i++)
		printf(" % 5d", a[i]);
}
void  covf(int *s, int n)
{
	int *p, *q, t;
	p = s; q = s + n - 1;
	while (p<q)
	{
		t = *p; *p = *q; *q = t;
		p++; q--;
	}
	return;
}

//��������18 16 14 12 10 8 6 4 2 0

/*8.*/
#include"stdio.h"
int fac(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n*fac(n - 1);
}
main()
{
	int s = 0, i;
	for (i = 1; i<5; i++)
		s += fac(i);
	printf("sum = %d\n", s);
}

//���н����sum = 33

/*9.*/
#include"stdio.h"
int f(int b[], int n)
{
	int i, r;
	r = 1;
	for (i = 0; i <= n; i++)   r = r*b[i];
	return r;
}
main()
{
	int x, a[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
	x = f(a, 3);
	printf("%d\n", x);
}

//���н����120

/*10��*/
#include"stdio.h"
int x = 30, y = 50;
int sub(int x, int y)
{
	y = x>y ? x : y;
	return y;
}
main()
{
	{ int x = 100;
	printf("%d\n", sub(x, y));
	}
	printf("%d, %d\n", x, y);
}

//���н��:100
//	30, 50
