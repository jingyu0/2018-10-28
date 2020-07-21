//#include <iostream>
//#include<stdlib.h>
//using namespace std;
//int main()
//{
//	int m, n, A, B;
//	cin >> A >> B;
//	m = A; n = B;
//	if (n != 0)
//	{
//		int tmp = m%n;
//		m = n;
//		n = tmp;
//	}
//	cout << (A*B) / m << endl;
//	system("pause");
//	return 0;
//}

#include<stdio.h>
int main()
{
	int m, n, temp, i;
	printf("Input m & n:");
	scanf("%d%d", &m, &n);
	if (m<n)  /*比较大小，使得m中存储大数，n中存储小数*/
	{
		temp = m;
		m = n;
		n = temp;
	}
	for (i = m; i>0; i++)  /*从大数开始寻找满足条件的自然数*/
	if (i%m == 0 && i%n == 0)
	{/*输出满足条件的自然数并结束循环*/
		printf("The LCW of %d and %d is: %d\n", m, n, i);
		break;
	}

	return 0;
}