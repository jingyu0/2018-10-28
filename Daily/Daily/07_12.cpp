#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
//int main()
//{
//	string s, t;
//	double count = 0;
//	int i, j;
//	getline(cin,s);
//	getline(cin,t);
//	for (i = 0; i < s.length(); i++)
//	{
//		for (j = 0; j < t.length(); j++)
//		{
//			if (i == j)
//				count++;
//		}
//	}
//	if (count != 0)
//		count = count / (t.length());
//	else
//		count = 0;
//	cout << count << endl;
//	system("pause");
//	return 0;
//}

//
////KMP算法
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//#include<algorithm>
//#include<iostream>
//#include<queue>
//#include<stack>
//using namespace std;
//char s1[1010], s2[1010];
//int t[1010];
//int KMP()
//{
//	int i = 0, j = 0, c = 0;
//	int a = strlen(s1);
//	int b = strlen(s2);
//	while (i<a)
//	{
//		if (j == -1 || s1[i] == s2[j])
//		{
//			++i, ++j;
//			if (j == b)
//			{
//				j = 0;
//				c++;
//			}
//		}
//		else
//			j = t[j];
//	}
//	return c;
//}
//void getnext(char *s2, int m)
//{
//	int i = 0, j = 0;
//	t[0] = -1;
//	j = t[i];
//	while (i<m)
//	{
//		if (j == -1 || s2[i] == s2[j])
//			t[++i] = ++j;
//		else
//			j = t[j];
//	}
//}
//int main()
//{
//	while (~scanf_s("%s", s1) && s1[0] != '#')
//	{
//		scanf_s("%s", s2);
//		int a = strlen(s1);
//		int b = strlen(s2);
//		getnext(s2, b);
//		printf("%d\n", KMP());
//	}
	system("pause");
//	return 0;
//}

​
//#include<stdio.h>
//int main()
//{
//	int n, i, x, y;
//	long long sum;
//	long long a[85];
//	a[1] = 1; a[2] = 1;
//	for (i = 3; i <= 80; i++)
//		a[i] = a[i - 1] + a[i - 2];
//	while (scanf("%d%d", &x, &y) != EOF)
//	{
//		sum = 0;
//		for (i = x; i <= y; i++)
//		{
//			sum += a[i];
//		}
//		printf("%lld\n", sum);
//	}
//	return 0;
//}

​