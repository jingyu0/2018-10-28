/*1.
写一个函数返回参数二进制中 1 的个数
比如： 15 0000 1111 4 个 1
程序原型：
int count_one_bits(unsigned int value)
{
// 返回 1的位数
}*/

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>

//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	while (value)
//	{
//		if (value % 2 == 1)
//		{
//			count++;
//		}
//		value = value / 2;
//	}
//	return count;
//}
//int main()
//{
//	unsigned int x = 0;
//	int count = 0;
//	scanf("%d", &x);
//	count = count_one_bits(x);
//	printf("count=%d\n", count);
//	system("pause");
//	return 0;
//	
//}