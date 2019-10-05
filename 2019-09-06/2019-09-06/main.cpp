//
//编程题：
//
//1.编程序求s = 3!+ 5!+ 7!
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

//2.输入一个字符串，分别统计其中的大写字母、小写字母、数字字符及其它字符的个数。
#include<stdio.h>
#include<string.h>
void main()
{
	char ch[100];
	int a = 0, b = 0, c = 0, d = 0, i = 0;
	printf("请输入 :");
	gets_s(ch);
	while (ch[i] != '\0')
	{
		if (ch[i] >= 'A'&&ch[i] <= 'Z')a++;
		else if (ch[i] >= 'a'&&ch[i] <= 'z')b++;
		else if (ch[i] >= '0'&& ch[i] <= '9')c++;
		else d++;
		i++;
	}
	printf("大写字母：%d\n", a);
	printf("小写字母：%d\n", b);
	printf("数字字母：%d\n", c);
	printf("其他字母：%d\n", d);
	system("pause");
}

//3.编写程序实现下列图案“菱形”图案的输出。
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
	//上3行
	for (x = 1; x <= 5; x += 2)//外循环控制循环层数(共3层)
	{
		for (y = (5 - x) / 2; y >= 1; y--)//控制每行中空格的个数
		{
			printf(" ");//首先输出空格
		}
		for (z = 1; z <= x; z++)//根据外循环中的x的值限制z(也就是每行"*"的个数)
		{
			printf("*");//在空格后面输出每行的"*"
		}
		printf("\n");//每输出一行后换行，以方便输出下一行
	}
	//下2行(方法和上3行类似，不再作注释)
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

//4.  编写一个选票统计的程序。功能需求如下：
//有小张，小李，小王，小赵4个人候选人参加竞选。
//每个投票人只能在这四个人中间选取，可以投弃权票。
//设计方案，编程输出每个竞选者的得票数以及弃权票数。
//输出其中的最高得票人。
//

//5.输入10个整数，找到这10个数中的最大数、最小数以及它们所在的下标位置。
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
	printf("最大数是%d，下标是%d，最小数是%d，下标是%d\n", a[max], max, a[min], min);
	system("pause");
	return 0;
}

//6.	编程从键盘输入若干字符, 直到输入字符’*’为止, 统计其中的字母字符、数字字符、空格符及其他字符的个数并输出统计结果。
//随机产生20个int类型的数组元素，并用冒泡排序法按降序排列。
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void bubblesort(int a[], int n)//n为数组a的元素个数
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
	printf("排序结果:");
	for (k = 0; k < n; k++)
	{
		printf("%d ", a[k]);
	}
	printf("\n");
}
void main()
{
	int i, num[20];
	//随进产生20个数
	srand((int)time(NULL));
	for (i = 0; i < 20; i++)
	{
		num[i] = rand() % 1000;
	}
	//排序
	bubblesort(num, 20);
	system("pause");
}

//7.向一个已经排好序的数组a中插入一个数，要求插入后数组仍按原来的规律排序，然后再将该数组的第3个元素删除，
//请编程实现该操作并显示插入和删除以后的数组。
#include<stdio.h>
int main()
{
	int c, i, b, a[5] = { 1, 2, 3, 5, 6 }, s[6];
	scanf_s("%d", &c);
	printf("原数组 ");
	for (i = 0; i<5; i++)
		printf("%d ", a[i]);
	for (i = 0; i <= 5; i++)
	{
		if (a[i]>c)   //找到应该插入的位置
			break;
		else s[i] = a[i];
	}
	s[i] = c;   //a[3]=4
	for (b = i; b <= 5; b++)
	{
		s[b + 1] = a[b];
	}
	printf("\n排序后");
	for (i = 0; i <= 5; i++)
		printf("%d ", s[i]);
	printf("\n");
	int  j = 0, k = 0;
	for (j = 2; j <= 4; j++)
		s[j] = s[j + 1];
	printf("删除后数组为 ");
	for (k = 0; k <= 4; k++)
	{
		printf("%d ", s[k]);
	}
	system("pause");
	return 0;
}


//读程题：

/*1.*/
#include "stdio.h"
main()
{
	char s[] = "ABCDE", *p;
	for (p = s; p <= s + 4; p = p + 2)
		printf("%s\n", p);
}

//输出结果：
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

//运行时输入：1 2 3 4 5 6 7 8 9 0
//输出：45

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

//输出：5 12 13 23 25 26 87 113 123   2

/*4．*/
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

//输出结果：2，2
//3，4
//4，7

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

//输出结果：50
//100，200

//6.
# include 〈stdio.h〉
main()
{
	int n[2], i, j, k;
	for (i = 0; i<2; i++)  n[i] = 0;
	k = 2;
	for (i = 0; i<k; i++)
	for (j = 0; j<k; j++)  n[j] = n[i] + 1;
	printf("%d\n", n[k]);
}

//输出结果：n[k]实际上超出了数组范围，定义的时候n[2]只有0和1两个下标，于是k = 2，n[k
//]不存在，不确定值。
//所以中间的循环形同虚设，没有关系。


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

//输出结果：18 16 14 12 10 8 6 4 2 0

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

//运行结果：sum = 33

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

//运行结果：120

/*10．*/
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

//运行结果:100
//	30, 50
