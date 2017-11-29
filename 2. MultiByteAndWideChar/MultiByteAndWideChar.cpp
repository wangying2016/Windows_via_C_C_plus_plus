#include <iostream>
#include <cstdlib>
#include <windows.h>

int main()
{
	// 将一个多字节字符串转换为 Unicode 形式的步骤
	// int MultiByteToWideChar (
	//		UINT uCodePage,
	//		DWORD dwFlags,
	//      PCSTR pMultiByteStr,
	//      int cbMultiByte,
	//      PWSTR pWideCharStr,
	//      int cchWideChar);
	// 1. 调用 MultiByteToWideChar，为 pWideCharStr 参数传入 NULL，
	// 为 cchWideChar 参数传入 0， ,为 cbMultiByte 参数传入 -1
	char* szMultiByteStr = "hello world";
	INT nChCount = MultiByteToWideChar(CP_ACP, 0, szMultiByteStr, -1, NULL, 0);
	// 2. 分配一块足以容纳转换后的 Unicode 字符串的内存。它的大小是上
	// 一个 MultiByteToWideChar 调用的返回值乘以 sizeof(wchar_t)
	wchar_t* szWideCharStr = new wchar_t[nChCount];
	wmemset(szWideCharStr, 0, nChCount);
	// 3. 再次调用 MultiByteToWideChar，这一次将缓冲区地址作为 pWideCharStr
	// 参数的值传入，将第一次 MultiByteToWideChar 调用的返回值乘以 sizeof(wchar_t)
	// 后得到的大小作为 cchWideChar 参数的传入
	MultiByteToWideChar(CP_ACP, 0, szMultiByteStr, -1, szWideCharStr, nChCount * sizeof(wchar_t));
	// 4. 使用转换后的字符串
	std::wcout << szWideCharStr << std::endl;
	// 5. 释放 Unicode 字符串占用的内存块
	delete[] szWideCharStr;



	// 将一个宽字符字符串转换为多字节字符串
	// int WideCharToMultiByte(
	//		UINT uCodePatge,
	//		DWORD dwFlags,
	//		PCWSTR pWideCharStr,
	//		int cchWideChar,
	//		PSTR pMultiByteStr,
	//		int cbMultiByte,
	//		PCSTR pDefaultChar,
	//		PBOOL pfUseDefaultChar);
	// 1. 调用 WideCharToMultiByte，为 pMultiByteStr 参数传入 NULL,
	// 为 cbMultiByte 参数传入 0，为 cchWideChar 参数传入 -1
	wchar_t* szWideCharStr2 = L"wang ying";
	INT nCbCount = WideCharToMultiByte(CP_ACP, 0, szWideCharStr2, -1, NULL, 0, NULL, NULL);
	// 2. 分配一块足以容纳转换后的多字节字符串的内存。它的大小直接就是上
	// 一次调用 WideCharToMultiByte 的返回值（直接就是字节数）
	char* szMultiByte2 = new char[nCbCount];
	memset(szMultiByte2, 0, nCbCount);
	// 3. 再次调用 WideCharToMultiByte，这一次将缓冲区地址作为 pMultiByteStr
	// 参数的值传入，将第一次 WideCharToMultiByte 调用的返回值作为 cbMultiByte
	// 参数的值传入
	WideCharToMultiByte(CP_ACP, 0, szWideCharStr2, -1, szMultiByte2, nCbCount, NULL, NULL);
	// 4. 使用转换后的字符串
	std::cout << szMultiByte2 << std::endl;
	// 5. 释放多字节字符串占用的内存块
	delete[] szMultiByte2;

	// 窗口暂停显示
	system("pause");
	return 0;
}