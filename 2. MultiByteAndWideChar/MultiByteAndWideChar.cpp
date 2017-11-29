#include <iostream>
#include <cstdlib>
#include <windows.h>

int main()
{
	// ��һ�����ֽ��ַ���ת��Ϊ Unicode ��ʽ�Ĳ���
	// int MultiByteToWideChar (
	//		UINT uCodePage,
	//		DWORD dwFlags,
	//      PCSTR pMultiByteStr,
	//      int cbMultiByte,
	//      PWSTR pWideCharStr,
	//      int cchWideChar);
	// 1. ���� MultiByteToWideChar��Ϊ pWideCharStr �������� NULL��
	// Ϊ cchWideChar �������� 0�� ,Ϊ cbMultiByte �������� -1
	char* szMultiByteStr = "hello world";
	INT nChCount = MultiByteToWideChar(CP_ACP, 0, szMultiByteStr, -1, NULL, 0);
	// 2. ����һ����������ת����� Unicode �ַ������ڴ档���Ĵ�С����
	// һ�� MultiByteToWideChar ���õķ���ֵ���� sizeof(wchar_t)
	wchar_t* szWideCharStr = new wchar_t[nChCount];
	wmemset(szWideCharStr, 0, nChCount);
	// 3. �ٴε��� MultiByteToWideChar����һ�ν���������ַ��Ϊ pWideCharStr
	// ������ֵ���룬����һ�� MultiByteToWideChar ���õķ���ֵ���� sizeof(wchar_t)
	// ��õ��Ĵ�С��Ϊ cchWideChar �����Ĵ���
	MultiByteToWideChar(CP_ACP, 0, szMultiByteStr, -1, szWideCharStr, nChCount * sizeof(wchar_t));
	// 4. ʹ��ת������ַ���
	std::wcout << szWideCharStr << std::endl;
	// 5. �ͷ� Unicode �ַ���ռ�õ��ڴ��
	delete[] szWideCharStr;



	// ��һ�����ַ��ַ���ת��Ϊ���ֽ��ַ���
	// int WideCharToMultiByte(
	//		UINT uCodePatge,
	//		DWORD dwFlags,
	//		PCWSTR pWideCharStr,
	//		int cchWideChar,
	//		PSTR pMultiByteStr,
	//		int cbMultiByte,
	//		PCSTR pDefaultChar,
	//		PBOOL pfUseDefaultChar);
	// 1. ���� WideCharToMultiByte��Ϊ pMultiByteStr �������� NULL,
	// Ϊ cbMultiByte �������� 0��Ϊ cchWideChar �������� -1
	wchar_t* szWideCharStr2 = L"wang ying";
	INT nCbCount = WideCharToMultiByte(CP_ACP, 0, szWideCharStr2, -1, NULL, 0, NULL, NULL);
	// 2. ����һ����������ת����Ķ��ֽ��ַ������ڴ档���Ĵ�Сֱ�Ӿ�����
	// һ�ε��� WideCharToMultiByte �ķ���ֵ��ֱ�Ӿ����ֽ�����
	char* szMultiByte2 = new char[nCbCount];
	memset(szMultiByte2, 0, nCbCount);
	// 3. �ٴε��� WideCharToMultiByte����һ�ν���������ַ��Ϊ pMultiByteStr
	// ������ֵ���룬����һ�� WideCharToMultiByte ���õķ���ֵ��Ϊ cbMultiByte
	// ������ֵ����
	WideCharToMultiByte(CP_ACP, 0, szWideCharStr2, -1, szMultiByte2, nCbCount, NULL, NULL);
	// 4. ʹ��ת������ַ���
	std::cout << szMultiByte2 << std::endl;
	// 5. �ͷŶ��ֽ��ַ���ռ�õ��ڴ��
	delete[] szMultiByte2;

	// ������ͣ��ʾ
	system("pause");
	return 0;
}