//#include<stdlib.h>
//#include<iostream>
//using std::cout;
////防止与库中std冲突，经常会这么用
//using std::endl;
////将常用的两个用std包起来
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
//		//支持范围for遍历
//	{
//		cout << e << "";
//	}
//	cout << endl;
//
//	//swap  两个树根据根节点的交换进行交换
//
//	auto it1 = std::find(s.begin(), s.end(), 5);//O(N)
//	auto it2 = s.find(5);//O(logN)，使用二叉搜索树来查找效率更高
//	if (it2 != s.end())
//	{
//		s.erase(it2);//确定将找到的it2的值删除
//	}
//
//	s.erase(5);//找到确定的值将其删除，找不到就不删
//	s.erase(1);
//	//s.clear();
//	for (auto e : s)
//	{
//		cout << e << "";
//	}
//	cout << endl;
//
//	system("pause");
//	//set:1.搜索二叉树在插入的同时对其进行排序
//	//2.去重  3.查找某值在或不在。
//}
//
//void test_multi_set()
//{
//	std::multiset<int>s;
//	//multiset相比set不支持去重，可单用于搜索，排序。
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
//	//当有许多重复数值时，先找到的是中序遍历的第一个2.
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