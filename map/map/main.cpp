////字符串中找到最长连续数字串
////#include<iostream>
////#include<string>
////#include<stdlib.h>
////using namespace std;
////int main()
////{
////	string str;
////	string tmp;
////	string maxstr;
////	int maxsize = 0;
////	getline(cin, str);
////	for (int i = 0; i<str.size(); i++)
////	{
////		while (str[i] >= '0' && str[i] <= '9')
////		{
////			tmp += str[i];
////			i++;
////		}
////		if (tmp.size()>maxsize)
////		{
////			maxstr = tmp;
////			maxsize = tmp.size();
////		}
////		tmp.clear();
////	}
////	cout << maxstr << endl;
////	system("pause");
////	return 0;
////}
//
////n个数里出现次数大于等于n/2的数
//#include <vector> 
//#include <iostream> 
//using namespace std; 
//int main() 
//{    
//	int n;    
//	vector <int> vec;    
//	while(cin >> n)        
//		vec.push_back(n);        
//	int count = 1;    
//	int temp = vec[0];    
//	for(int i = 1; i < vec.size(); ++i)
//	{        
//		if(vec[i] == temp)            
//			count++;        
//		else            
//			count--;        
//		if (count == 0)
//		{
//			temp = vec[i];           
//			count++;
//		}
//	}        
//	cout << temp << endl;    
//	return 0;
//}