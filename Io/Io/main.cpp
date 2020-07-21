﻿//C++根据文件内容的数据格式分为二进制文件和文本文件
//文件的操作步骤：
//1. 定义一个文件流对象 
//ifstream iﬁle(只输入用) 
//ofstream oﬁle(只输出用) 
//fstream ioﬁle(既输入又输出用)
//2. 使用文件流对象的成员函数打开一个磁盘文件，使得文件流对象和磁盘文件之间建立联系 
//3. 使用提取和插入运算符对文件进行读写操作，或使用成员函数进行读写 
//4. 关闭文件
//使用文件i/O流用文件及二进制方法演示读写配置文件
#pragma once
#include<iostream>
#include<string>
#include <fstream>
//fstream 文件流
#include<stdlib.h>
using namespace std;

struct ServerInfo
{
	char _ip[32];//ip
	int _port;//端口
};
struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}
	
	void WriteBin(const ServerInfo& info)
	{
		//使用二进制方式打开写
		ofstream ofs(_configfile, ifstream::in | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}

	void ReadBin(ServerInfo& info)
	{         
		// 这里注意使用二进制方式打开读        
		ifstream ifs(_configfile, ifstream::out | ifstream::binary);        
		ifs.read((char*)&info, sizeof(ServerInfo));        
		ifs.close();    
	}

	void WriteText(const ServerInfo& info)    
	{        
		// 这里会发现IO流写整形比C语言那套就简单多了，        
		// C 语言得先把整形itoa再写        
		ofstream ofs(_configfile);        
		ofs << info._ip << endl;        
		ofs << info._port << endl;        
		ofs.close();    
	}

	void ReadText(ServerInfo& info)
	{
	   // 这里会发现IO流读整形比C语言那套就简单多了，        
		// C 语言得先读字符串，再atoi        
		ifstream ifs(_configfile);        
		ifs >> info._ip;        
		ifs >> info._port;        
		ifs.close();    
	}

    private:    
		string _configfile; 
		// 配置文件
 };

    int main() 
	{
		ConfigManager cfgMgr;
        ServerInfo wtinfo;    
		ServerInfo rdinfo;    
		strcpy(wtinfo._ip, "127.0.0.1");    
		wtinfo._port = 80;

        // 二进制读写    
		cfgMgr.WriteBin(wtinfo);    
		cfgMgr.ReadBin(rdinfo);    
		cout << rdinfo._ip << endl;    
		cout << rdinfo._port << endl;

        // 文本读写    
		cfgMgr.WriteText(wtinfo);    
		cfgMgr.ReadText(rdinfo);    
		cout << rdinfo._ip << endl;    
		cout << rdinfo._port << endl;
		system("pause");
		return 0;
		}