//#include<stdlib.h>
//#include<iostream>
//using std::cout;
////��ֹ�����std��ͻ����������ô��
//using std::endl;
////�����õ�������std������
//
//#include<map>
//#include<set>
//
//void test_set()
//{
//	std::set<int>s;
//	s.insert(2);
//	s.insert(3);
//	s.insert(1);
//	s.insert(5);
//	s.insert(4);
//	s.insert(5);
//	s.insert(5);
//	s.insert(5);
//	s.insert(5);
//
//	std::set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << "";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : s)
//		//֧�ַ�Χfor����
//	{
//		cout << e << "";
//	}
//	cout << endl;
//
//	//swap  ���������ݸ��ڵ�Ľ������н���
//
//	auto it1 = std::find(s.begin(), s.end(), 5);//O(N)
//	auto it2 = s.find(5);//O(logN)��ʹ�ö���������������Ч�ʸ���
//	if (it2 != s.end())
//	{
//		s.erase(it2);//ȷ�����ҵ���it2��ֵɾ��
//	}
//
//	s.erase(5);//�ҵ�ȷ����ֵ����ɾ�����Ҳ����Ͳ�ɾ
//	s.erase(1);
//	//s.clear();
//	for (auto e : s)
//	{
//		cout << e << "";
//	}
//	cout << endl;
//
//	system("pause");
//	//set:1.�����������ڲ����ͬʱ�����������
//	//2.ȥ��  3.����ĳֵ�ڻ��ڡ�
//}
//
//void test_multi_set()
//{
//	std::multiset<int>s;
//	//multiset���set��֧��ȥ�أ��ɵ���������������
//	/*typedef std::multiset<int>::iterator msiter;*/
//	s.insert(3);
//	s.insert(3);
//	s.insert(1);
//	s.insert(2);
//	s.insert(3);
//	s.insert(5);
//	s.insert(4);
//
//	/*std::multiset<int>::iterator it = s.begin();*/
//	/*msiter it = s.begin();*/
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << "";
//		++it;
//	}
//	cout << endl;
//	
//	it = s.find(2);
//	//��������ظ���ֵʱ�����ҵ�������������ĵ�һ��2.
//	cout << *it << endl;
//	++it;
//	cout << *it << endl;
//	++it;
//	cout << *it << endl;
//	system("pause");
//}
//#include"BSTree.h"
//
//int main()
//{
//	/*test_set();*/
//	/*test_multi_set();*/
//	TestBSTree();
//	system("pause");
//	return 0;
//}