//// msgbox项目
//# include <windows.h>				// 标准的include
//// 告诉连接器与包括MessageBox API函数的user32库进行连接
//# pragma comment(lib,"user32.lib")
//// 这是一个可以弹出信息框然后退出的筒单的应用程序
//int APIENTRY WinMain(HINSTANCE	hInstance,
//	HINSTANCE	hPrevInstance,
//	LPSTR		lpCmdLine,
//	int			nCmdShow)
//{
//	::MessageBox(
//		NULL, 							// 没有父窗口
//		"Hello,Windows 2019", 			// 消息框中的文本
//		"Greetings", 					// 消息框标题
//		MB_OK);						// 其中只有一个OK按钮
//	// 返回0以便通知系统不进入消息循环
//	return(0);
//}


//
//// prochandle项目
#include<stdlib.h>
//# include <windows.h>
//# include <iostream>
//// 确定自己的优先权的简单应用程序
//void main()
//{
//	// 从当前进程中提取句柄
//	HANDLE hProcessThis = ::GetCurrentProcess();
//	// 请求内核提供该进程所属的优先权类
//	DWORD dwPriority = ::GetPriorityClass(hProcessThis);
//	// 发出消息，为用户描述该类
//	std::cout << "Current process priority:";
//	switch (dwPriority)
//	{
//	case HIGH_PRIORITY_CLASS:
//		std::cout << "High";
//		break;
//	case NORMAL_PRIORITY_CLASS:
//		std::cout << "Normal";
//		break;
//	case IDLE_PRIORITY_CLASS:
//		std::cout << "Idle";
//		break;
//	case REALTIME_PRIORITY_CLASS:
//		std::cout << "Realtime";
//		break;
//	default:
//		std::cout << "<unknown>";
//		break;
//	}
//	std::cout << std::endl;
//	system("pause");
//}


//
//// proclist项目
//# include <windows.h>
//# include <tlhelp32.h>
//# include <iostream>
//// 当在用户模式和内核模式下都提供所耗时间时，在内核模式下进行所耗时间的64位计算的帮助方法
//DWORD GetKernelModePercentage(const FILETIME & ftKernel,
//	const FILETIME & ftUser)
//{
//	// 将FILETIME结构转化为64位整数
//	ULONGLONG qwKernel = (((ULONGLONG)ftKernel.dwHighDateTime) << 32) +
//		ftKernel.dwLowDateTime;
//	ULONGLONG qwUser = (((ULONGLONG)ftUser.dwHighDateTime) << 32) +
//		ftUser.dwLowDateTime;
//	// 将消耗时间相加，然后计算消耗在内核模式下的时间百分比
//	ULONGLONG qwTotal = qwKernel + qwUser;
//	DWORD dwPct = (DWORD)(((ULONGLONG)100 * qwKernel) / qwTotal);
//	return(dwPct);
//}
//// 以下是将当前运行进程名和消耗在内核模式下的时间百分数都显示出来的应用程序
//void main()
//{
//	// 对当前系统中运行的进程拍取"快照"
//	HANDLE hSnapshot = ::CreateToolhelp32Snapshot(
//		TH32CS_SNAPPROCESS,		// 提取当前进程
//		0);							// 如果是当前进程，就将其忽略
//	// 初始化进程入口
//	PROCESSENTRY32 pe;
//	::ZeroMemory(&pe, sizeof(pe));
//	pe.dwSize = sizeof(pe);
//	// 按所有进程循环
//	BOOL bMore = ::Process32First(hSnapshot, &pe);
//	while (bMore)
//	{
//		// 打开用于读取的进程
//		HANDLE hProcess = ::OpenProcess(
//			PROCESS_QUERY_INFORMATION,		// 指明要得到信息
//			FALSE,							// 不必继承这一句柄
//			pe.th32ProcessID);				// 要打开的进程
//		if (hProcess != NULL)
//		{
//			// 找出进程的时间
//			FILETIME ftCreation, ftExit, ftKernelMode, ftUserMode;
//			::GetProcessTimes(
//				hProcess,					// 所感兴趣的进程
//				&ftCreation,					// 进程的启动时间 (绝对的)
//				&ftExit,						// 结束时间 (如果有的话)
//				&ftKernelMode,				// 在内核模式下消耗的时间
//				&ftUserMode);				// 在用户模式下消耗的时间
//			// 计算内核模式消耗的时间百分比
//			DWORD dwPctKernel = ::GetKernelModePercentage(
//				ftKernelMode,				// 在内核模式上消耗的时间
//				ftUserMode);					// 在用户模式下消耗的时间
//			// 向用户显示进程的某些信息
//			std::cout << "Process ID:" << pe.th32ProcessID
//				<< ",EXE file:" << pe.szExeFile
//				<< ",%in kernel mode:" << dwPctKernel
//				<< std::endl;
//			// 消除句柄
//			::CloseHandle(hProcess);
//		}
//		// 转向下一个进程
//		bMore = ::Process32Next(hSnapshot, &pe);
//	}
//	system("pause");
//}


// proccreate项目
#define _CRT_SECURE_NO_WARNINGS  
//# include <windows.h>
//# include <iostream>
//# include <stdio.h>
//#include<string>
//// 创建传递过来的进程的克隆过程并赋于其ID值
//void StartClone(int nCloneID)
//{
//	// 提取用于当前可执行文件的文件名
//	TCHAR szFilename[MAX_PATH];
//	::GetModuleFileName(NULL, szFilename, MAX_PATH);
//	// 格式化用于子进程的命令行并通知其EXE文件名和克隆ID
//	TCHAR szCmdLine[MAX_PATH];
//	::sprintf_s(szCmdLine, "\"%s\"%d", szFilename, nCloneID);
//	// 用于子进程的STARTUPINFO结构
//	STARTUPINFO si;
//	::ZeroMemory(reinterpret_cast <void*> (&si), sizeof(si));
//	si.cb = sizeof(si);				// 必须是本结构的大小
//	// 返回的用于子进程的进程信息
//	PROCESS_INFORMATION pi;
//	// 利用同样的可执行文件和命令行创建进程，并赋于其子进程的性质
//	BOOL bCreateOK = ::CreateProcess(
//		szFilename,					// 产生这个EXE的应用程序的名称
//		szCmdLine,					// 告诉其行为像一个子进程的标志
//		NULL,						// 缺省的进程安全性
//		NULL,						// 缺省的线程安全性
//		FALSE,						// 不继承句柄
//		CREATE_NEW_CONSOLE,		// 使用新的控制台
//		NULL,						// 新的环境
//		NULL,						// 当前目录
//		&si,						// 启动信息
//		&pi);						// 返回的进程信息
//	// 对子进程释放引用
//	if (bCreateOK)
//	{
//		::CloseHandle(pi.hProcess);
//		::CloseHandle(pi.hThread);
//	}
//}
//int main(int argc, char* argv[])
//{
//	// 确定进程在列表中的位置
//	int nClone(0);
//	if (argc>1)
//	{
//		// 从第二个参数中提取克隆ID
//		::sscanf_s(argv[1], "%d", &nClone);
//	}
//	// 显示进程位置
//	std::cout << "Process ID:" << ::GetCurrentProcessId()
//		<< ",Clone ID:" << nClone << std::endl;
//	// 检查是否有创建子进程的需要
//	const int c_nCloneMax = 25;
//	if (nClone<c_nCloneMax)
//	{
//		// 发送新进程的命令行和克隆号
//		StartClone(++nClone);
//	}
//	// 在终止之前暂停一下，输入一个字符后，程序结束，以便观察
//	std::cout << "input a char:";
//	getchar();
//	std::cout << "I'm gone ... Bye-bye";
//	::Sleep(1000);
//	system("pause");
//	return 0;
//}

// version项目
# include <windows.h>
# include <iostream>
// 利用进程和操作系统的版本信息的简单示例
void main()
{   // 提取这个进程的ID号
	DWORD dwIdThis = ::GetCurrentProcessId();
	// 获得这一进程和报告所需的版本，也可以发送0以便指明这一进程
	DWORD dwVerReq = ::GetProcessVersion(dwIdThis);
	WORD wMajorReq = (WORD)(dwVerReq > 16);
	WORD wMinorReq = (WORD)(dwVerReq & 0xffff);
	std::cout << "Process ID:" << dwIdThis << ",requires OS:"
		<< wMajorReq << wMinorReq << std::endl;
	// 设置版本信息的数据结构，以便保存操作系统的版本信息
	OSVERSIONINFOEX osvix;
	::ZeroMemory(&osvix, sizeof(osvix));
	osvix.dwOSVersionInfoSize = sizeof(osvix);
	// 提取版本信息和报告
	::GetVersionEx(reinterpret_cast<LPOSVERSIONINFO>(&osvix));
	std::cout << "Running on OS:" << osvix.dwMajorVersion << "."
		<< osvix.dwMinorVersion << std::endl;
	// 显示进程当前优先级
	DWORD dwProcessP; GetPriorityClass(GetCurrentProcess());
	std::cout << "Current process priority is:";
	switch (dwProcessP){
	case HIGH_PRIORTY_CLASS:
		std::cout << "High";
		break;
	case NORMAL_PRIORTY_CLASS:
		std::cout << "Normal";
		break;
	case IDLE_PRIORTY_CLASS:
		std::cout << "Idle";
		break;
	case REALTIME_PRIORTY_CLASS:
		std::cout << "RealTime";
		break;
	default:
		std::cout << "unknow";
		break;
	}
	std::cout << std::endl;
	// 如果是NTS (Windows 2000) 系统，则提高其优先权
	if (osvix.dwPlatformld == VER_PLATFORM_WIN32_NT &&
		osvix.dwMajorVersion >= 5)
	{
		if (dwProcessP != HIGH_PRIORITY_CLASS){
			// 如果当前优先级不是high，则改变优先级
			::SetPriorityClass(
				::GetCurrentProcess(),		// 利用这一进程
				HIGH_PRIORITY_CLASS);		// 改变为high
			// 报告给用户
			dwProcessP = GetPriorityClass(GetCurrentProcess());
			std::cout << "The process priority have been changed to ";
			switch (dwProcessP)
			{
			case HIGH_PRIORITY_CLASS:
				std::cout << "High";
				break;
			case NORMAL_PRIORITY_CLASS:
				std::cout << "Normal";
				break;
			case IDLE_PRIORITY_CLASS:
				std::cout << "Idle";
				break;
			case REALTIME_PRIORITY_CLASS:
				std::cout << "Realtime";
				break;
			default:
				std::cout << "<unknow>";
				break;
			}
			std::cout << std::endl;
			system("pause");
		}
	}
}