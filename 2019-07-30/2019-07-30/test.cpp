////��Ӿ������ؼ�������м�ֵ��ѡ��Ϊ�˾����ܴ�ֻ����ȥ����Сֵ����ʣ�µ�����һ���о�������ֵ����м�ֵ
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		long long sum = 0;
//		vector<int> v(3 * n);
//		for (int i = 0; i < 3 * n; i++)
//			cin >> v[i];
//		sort(v.begin(), v.end());
//		//Ϊ�õ����ƽ��ֵ��ȡ�δ����Ϊ��ֵ
//		//������ѡ�ֵ�ˮƽ��������ȡ[0,n-1]n������Ϊ��Сֵ��ʣ�µ�����һ�飬ȡ���еĴ�������ֵ��
//		//�δ��(�±�Ϊn,n+2,...,3*n-2)���м�ֵ���������Ǽ�������
//		for (int j = 0; j <= 3 * n - 2; j += 2)
//		{
//			sum += v[j];
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

////ɾ�������ַ�
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int hashtable[256] = { 0 };
//	
//	for (int i = 0; i < str2.size(); i++)
//	{
//		// ʹ�ù�ϣӳ��˼���Ƚ�str2���ַ����ֵĴ���ͳ�ơ�
//		hashtable[str2[i]]++;
//	}
//	// ����str1��str1[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ���    
//	// str2��û�г��ֹ�������+=��ret��    
//	// ������ò�Ҫstr1.erases(i),��Ϊ�߱�������erase�����׳���  
//	string ret;
//	for (int j = 0; j < str1.size(); j++)
//	{
//		if (hashtable[str1[j]] == 0)//˵������ַ���str2��û�г��ֹ�
//			ret += str1[j];
//	}
//	cout << ret << endl;
//	return 0;
//}

////����������
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> v(n);
//		for (int i = 0; i < n; i++)
//			cin >> v[i];
//		int ret = 1;
//		for (int i = 1; i < n - 1; i++)
//		{
//			//�ҳ����岨��
//			if ((v[i]>v[i - 1] && v[i]>v[i + 1])
//				|| (v[i] < v[i - 1] && v[i] < v[i + 1]))
//			{
//				ret++;
//				//һ����������������Ҫ����Ϊ2������������,
//				if (i != n - 3)
//					i++;
//			}
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}


//�����ַ���
//
//�ڶ�˼·��һ���Ƚ����ɵ�˼·��ֱ������cin >> s�������룬�����ո�ͽ����ˣ�
//��Ȼ�ͷָ��ÿ�����ʣ���ν�ÿ�ν��յ��ĵ���ƴ�ӵ�֮ǰ����ǰ������ù����ˡ�
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1,s2;
	cin >> s2;
	while (cin >> s1)
	{
		s2 = s1 + " " + s2;
	}
	cout << s2 << endl;
	return 0;
}

//�������Ƚ������ַ������ù������ٱ����ַ������ҳ�ÿ�����ʣ��Ե������á�
//��������ʹ����stl�㷨�е� reverse����������ʹ�õ���������string��
#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std;
int main()
{
	string s;
	// ע������Ҫʹ��getline��cin>>s�����ո�ͽ��ս�����    
	getline(cin, s);
	// ��ת��������    
	reverse(s.begin(), s.end());
	// ��ת����    
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;

		reverse(start, end);
		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;
	system("pause");
	return 0;
}
