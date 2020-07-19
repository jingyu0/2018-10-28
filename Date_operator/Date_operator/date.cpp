////求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case
////等关键字及条件判断语句（A ? B : C）
//#include<iostream>
//using namespace std;
//class Sum
//{
//public:
//	Sum()
//	{
//		++n;
//		sum += n;
//	}
//	static void Reset()
//	{
//		n = 0; sum = 0;
//	}
//	static unsigned int GetSum()
//	{
//		return sum;
//	}
//private:
//	static unsigned int n;
//	static unsigned int sum;
//};
//unsigned int Sum::n = 0;
//unsigned int Sum::sum = 0;
//
//unsigned int Sum_Solution(unsigned int n)
//{
//	Sum::Reset();
//	Sum* a = new Sum[n];
//	delete[]a;
//	a = NULL;
//	return Sum::GetSum();
//}
//int main()
//{
//	int n = 3;
//	cout << Sum_Solution(n) << endl;
//	system("pause");
//	return 0;
//}

//根据输入的日期，计算是这一年的第几天。
//#include<iostream>
//using namespace std;
//int main()
//{
//	int nyear, nmonth, nday;
//	int day;
//	int a[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	while (cin >> nyear >> nmonth >> nday)
//	{
//		day = a[nmonth - 1] + nday;
//		if (nmonth > 2 && nyear % 4 == 0 && nyear % 100 != 0 || nyear % 400 == 0)
//		{
//			day++;
//		}
//		cout << day << endl;
//	}
//	system("pause");
//	return 0;
//}