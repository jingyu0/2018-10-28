//// constructing vectors 
//#include <iostream> 
//#include <vector>
//
//int main() 
//{  
//	// constructors used in the same order as described above:  
//	std::vector<int> first;                                
//	// empty vector of ints  
//	std::vector<int> second (4,100);                      
//	// four ints with value 100  
//	std::vector<int> third (second.begin(),second.end());  
//	// iterating through second  
//	std::vector<int> fourth (third);                       
//	// a copy of third
//
//	// �����漰��������ʼ���Ĳ��֣�����ѧϰ��������������ⲿ��  
//	// the iterator constructor can also be used to construct from arrays:  
//	int myints[] = {16,2,77,29};  
//	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
//
//	std::cout << "The contents of fifth are:";
//	for (std::vector<int>::iterator it = fifth.begin();it != fifth.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//
//void PrintVector(const vector<int>& v)
//{
//	//ʹ��const���������б���
//	vector<int>::const_iterator it = v.cbegin();
//	while (it != v.cend())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
////int main()
////{
////	//ʹ��push_back����4������
////	vector<int> v;
////	v.push_back(1);
////	v.push_back(2);
////	v.push_back(3);
////	v.push_back(4);
////
////	//ʹ�õ��������б�����ӡ
////	vector<int>::iterator it = v.begin();
////	while (it != v.end())
////	{
////		cout << *it << " " ;
////		++it;
////	}
////	cout << endl;
////
////	//ʹ�õ����������޸�
////	it = v.begin();
////	while (it != v.end())
////	{
////		*it *= 2;
////		++it;
////	}
////
////	//ʹ�÷�����������б����ٴ�ӡ
////	vector<int>::reverse_iterator rit = v.rbegin();
////	while (rit != v.rend())
////	{
////		cout << *rit << " ";
////		++rit;
////	}
////	cout << endl;
////
////	PrintVector(v);
////	system("pause");
////	return 0;
////}
//
//int main()
//{
//	////size_t sz;
//	////std::vector<int> foo;
//	////sz = foo.capacity();
//	////std::cout << "making foo grow:\n";
//	////for (int i = 0; i < 100; ++i)
//	////{
//	////	foo.push_back(i);
//	////	if (sz != foo.capacity())
//	////	{
//	////		sz = foo.capacity();
//	////		std::cout << "capacity changed: " << sz << '\n';
//	////	}
//	////}
//	//
//	//
//	//std::vector<int>myvector;
//	//for (int i = 1; i < 10; i++)
//	//{
//	//	myvector.push_back(i);
//	//}
//	//myvector.resize(5);
//	//myvector.resize(8, 100);
//	//myvector.resize(12);
//	//std::cout << "myvector contains:";
//	//for (int i = 0; i < myvector.size(); i++)
//	//	std::cout << ' ' << myvector[i];
//	//std::cout << '\n';
//	
//	//push_back/pop_back
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	v.pop_back();
//	v.pop_back();
//
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//		system("pause");
//		return 0;
//}

//find/insert/erase
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	
//	//ʹ��find����3����λ�õ�iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//
//	//��posλ��֮ǰ����30
//	v.insert(pos,30);
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	pos = find(v.begin(), v.end(), 3);
//	//ɾ��posλ�õ�����
//	v.erase(pos);
//
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

// operator[]+index �� C++11��vector����ʽfor+auto�ı��� 
// vectorʹ�������ֱ�����ʽ�ǱȽϱ�ݵġ�
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	
	////ͨ��[]��д��0��λ��
	//v[0] = 10;
	//cout << v[0] << endl;

	////ͨ��[i]�ķ�ʽ����vector
	//for (size_t i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << " ";
	//}
	//cout << endl;

	//vector<int> swapv;
	//swapv.swap(v);

	//cout << "v data:";
	//for (size_t i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << " ";
	//}
	//cout << endl;

	//cout << "swapv data:";
	//for (size_t i = 0; i < swapv.size(); ++i)
	//{
	//	cout << swapv[i] << " ";
	//}
	//cout << endl;

	//C++֧�ֵ���ʽ����
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}