//// msgbox��Ŀ
//# include <windows.h>				// ��׼��include
//// ���������������MessageBox API������user32���������
//# pragma comment(lib,"user32.lib")
//// ����һ�����Ե�����Ϣ��Ȼ���˳���Ͳ����Ӧ�ó���
//int APIENTRY WinMain(HINSTANCE	hInstance,
//	HINSTANCE	hPrevInstance,
//	LPSTR		lpCmdLine,
//	int			nCmdShow)
//{
//	::MessageBox(
//		NULL, 							// û�и�����
//		"Hello,Windows 2019", 			// ��Ϣ���е��ı�
//		"Greetings", 					// ��Ϣ�����
//		MB_OK);						// ����ֻ��һ��OK��ť
//	// ����0�Ա�֪ͨϵͳ��������Ϣѭ��
//	return(0);
//}


//
//// prochandle��Ŀ
#include<stdlib.h>
//# include <windows.h>
//# include <iostream>
//// ȷ���Լ�������Ȩ�ļ�Ӧ�ó���
//void main()
//{
//	// �ӵ�ǰ��������ȡ���
//	HANDLE hProcessThis = ::GetCurrentProcess();
//	// �����ں��ṩ�ý�������������Ȩ��
//	DWORD dwPriority = ::GetPriorityClass(hProcessThis);
//	// ������Ϣ��Ϊ�û���������
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
//// proclist��Ŀ
//# include <windows.h>
//# include <tlhelp32.h>
//# include <iostream>
//// �����û�ģʽ���ں�ģʽ�¶��ṩ����ʱ��ʱ�����ں�ģʽ�½�������ʱ���64λ����İ�������
//DWORD GetKernelModePercentage(const FILETIME & ftKernel,
//	const FILETIME & ftUser)
//{
//	// ��FILETIME�ṹת��Ϊ64λ����
//	ULONGLONG qwKernel = (((ULONGLONG)ftKernel.dwHighDateTime) << 32) +
//		ftKernel.dwLowDateTime;
//	ULONGLONG qwUser = (((ULONGLONG)ftUser.dwHighDateTime) << 32) +
//		ftUser.dwLowDateTime;
//	// ������ʱ����ӣ�Ȼ������������ں�ģʽ�µ�ʱ��ٷֱ�
//	ULONGLONG qwTotal = qwKernel + qwUser;
//	DWORD dwPct = (DWORD)(((ULONGLONG)100 * qwKernel) / qwTotal);
//	return(dwPct);
//}
//// �����ǽ���ǰ���н��������������ں�ģʽ�µ�ʱ��ٷ�������ʾ������Ӧ�ó���
//void main()
//{
//	// �Ե�ǰϵͳ�����еĽ�����ȡ"����"
//	HANDLE hSnapshot = ::CreateToolhelp32Snapshot(
//		TH32CS_SNAPPROCESS,		// ��ȡ��ǰ����
//		0);							// ����ǵ�ǰ���̣��ͽ������
//	// ��ʼ���������
//	PROCESSENTRY32 pe;
//	::ZeroMemory(&pe, sizeof(pe));
//	pe.dwSize = sizeof(pe);
//	// �����н���ѭ��
//	BOOL bMore = ::Process32First(hSnapshot, &pe);
//	while (bMore)
//	{
//		// �����ڶ�ȡ�Ľ���
//		HANDLE hProcess = ::OpenProcess(
//			PROCESS_QUERY_INFORMATION,		// ָ��Ҫ�õ���Ϣ
//			FALSE,							// ���ؼ̳���һ���
//			pe.th32ProcessID);				// Ҫ�򿪵Ľ���
//		if (hProcess != NULL)
//		{
//			// �ҳ����̵�ʱ��
//			FILETIME ftCreation, ftExit, ftKernelMode, ftUserMode;
//			::GetProcessTimes(
//				hProcess,					// ������Ȥ�Ľ���
//				&ftCreation,					// ���̵�����ʱ�� (���Ե�)
//				&ftExit,						// ����ʱ�� (����еĻ�)
//				&ftKernelMode,				// ���ں�ģʽ�����ĵ�ʱ��
//				&ftUserMode);				// ���û�ģʽ�����ĵ�ʱ��
//			// �����ں�ģʽ���ĵ�ʱ��ٷֱ�
//			DWORD dwPctKernel = ::GetKernelModePercentage(
//				ftKernelMode,				// ���ں�ģʽ�����ĵ�ʱ��
//				ftUserMode);					// ���û�ģʽ�����ĵ�ʱ��
//			// ���û���ʾ���̵�ĳЩ��Ϣ
//			std::cout << "Process ID:" << pe.th32ProcessID
//				<< ",EXE file:" << pe.szExeFile
//				<< ",%in kernel mode:" << dwPctKernel
//				<< std::endl;
//			// �������
//			::CloseHandle(hProcess);
//		}
//		// ת����һ������
//		bMore = ::Process32Next(hSnapshot, &pe);
//	}
//	system("pause");
//}


// proccreate��Ŀ
#define _CRT_SECURE_NO_WARNINGS  
//# include <windows.h>
//# include <iostream>
//# include <stdio.h>
//#include<string>
//// �������ݹ����Ľ��̵Ŀ�¡���̲�������IDֵ
//void StartClone(int nCloneID)
//{
//	// ��ȡ���ڵ�ǰ��ִ���ļ����ļ���
//	TCHAR szFilename[MAX_PATH];
//	::GetModuleFileName(NULL, szFilename, MAX_PATH);
//	// ��ʽ�������ӽ��̵������в�֪ͨ��EXE�ļ����Ϳ�¡ID
//	TCHAR szCmdLine[MAX_PATH];
//	::sprintf_s(szCmdLine, "\"%s\"%d", szFilename, nCloneID);
//	// �����ӽ��̵�STARTUPINFO�ṹ
//	STARTUPINFO si;
//	::ZeroMemory(reinterpret_cast <void*> (&si), sizeof(si));
//	si.cb = sizeof(si);				// �����Ǳ��ṹ�Ĵ�С
//	// ���ص������ӽ��̵Ľ�����Ϣ
//	PROCESS_INFORMATION pi;
//	// ����ͬ���Ŀ�ִ���ļ��������д������̣����������ӽ��̵�����
//	BOOL bCreateOK = ::CreateProcess(
//		szFilename,					// �������EXE��Ӧ�ó��������
//		szCmdLine,					// ��������Ϊ��һ���ӽ��̵ı�־
//		NULL,						// ȱʡ�Ľ��̰�ȫ��
//		NULL,						// ȱʡ���̰߳�ȫ��
//		FALSE,						// ���̳о��
//		CREATE_NEW_CONSOLE,		// ʹ���µĿ���̨
//		NULL,						// �µĻ���
//		NULL,						// ��ǰĿ¼
//		&si,						// ������Ϣ
//		&pi);						// ���صĽ�����Ϣ
//	// ���ӽ����ͷ�����
//	if (bCreateOK)
//	{
//		::CloseHandle(pi.hProcess);
//		::CloseHandle(pi.hThread);
//	}
//}
//int main(int argc, char* argv[])
//{
//	// ȷ���������б��е�λ��
//	int nClone(0);
//	if (argc>1)
//	{
//		// �ӵڶ�����������ȡ��¡ID
//		::sscanf_s(argv[1], "%d", &nClone);
//	}
//	// ��ʾ����λ��
//	std::cout << "Process ID:" << ::GetCurrentProcessId()
//		<< ",Clone ID:" << nClone << std::endl;
//	// ����Ƿ��д����ӽ��̵���Ҫ
//	const int c_nCloneMax = 25;
//	if (nClone<c_nCloneMax)
//	{
//		// �����½��̵������кͿ�¡��
//		StartClone(++nClone);
//	}
//	// ����ֹ֮ǰ��ͣһ�£�����һ���ַ��󣬳���������Ա�۲�
//	std::cout << "input a char:";
//	getchar();
//	std::cout << "I'm gone ... Bye-bye";
//	::Sleep(1000);
//	system("pause");
//	return 0;
//}

// version��Ŀ
# include <windows.h>
# include <iostream>
// ���ý��̺Ͳ���ϵͳ�İ汾��Ϣ�ļ�ʾ��
void main()
{   // ��ȡ������̵�ID��
	DWORD dwIdThis = ::GetCurrentProcessId();
	// �����һ���̺ͱ�������İ汾��Ҳ���Է���0�Ա�ָ����һ����
	DWORD dwVerReq = ::GetProcessVersion(dwIdThis);
	WORD wMajorReq = (WORD)(dwVerReq > 16);
	WORD wMinorReq = (WORD)(dwVerReq & 0xffff);
	std::cout << "Process ID:" << dwIdThis << ",requires OS:"
		<< wMajorReq << wMinorReq << std::endl;
	// ���ð汾��Ϣ�����ݽṹ���Ա㱣�����ϵͳ�İ汾��Ϣ
	OSVERSIONINFOEX osvix;
	::ZeroMemory(&osvix, sizeof(osvix));
	osvix.dwOSVersionInfoSize = sizeof(osvix);
	// ��ȡ�汾��Ϣ�ͱ���
	::GetVersionEx(reinterpret_cast<LPOSVERSIONINFO>(&osvix));
	std::cout << "Running on OS:" << osvix.dwMajorVersion << "."
		<< osvix.dwMinorVersion << std::endl;
	// ��ʾ���̵�ǰ���ȼ�
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
	// �����NTS (Windows 2000) ϵͳ�������������Ȩ
	if (osvix.dwPlatformld == VER_PLATFORM_WIN32_NT &&
		osvix.dwMajorVersion >= 5)
	{
		if (dwProcessP != HIGH_PRIORITY_CLASS){
			// �����ǰ���ȼ�����high����ı����ȼ�
			::SetPriorityClass(
				::GetCurrentProcess(),		// ������һ����
				HIGH_PRIORITY_CLASS);		// �ı�Ϊhigh
			// ������û�
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