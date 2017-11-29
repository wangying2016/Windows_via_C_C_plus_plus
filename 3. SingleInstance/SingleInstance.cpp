#include <tchar.h>
#include <windows.h>

int WINAPI _tWinMain(HINSTANCE hInstExe, HINSTANCE, PTSTR pszCmdLine,
	int nCmdShow) {
	HANDLE h = CreateMutex(NULL, FALSE,
		TEXT("{80A85553-1E05-4323-B4F9-43A4396A4507}"));
	if (GetLastError() == ERROR_ALREADY_EXISTS) {
		// There is already an instance of this application running.
		// Close the object and immediately return.
		MessageBox(NULL, TEXT("Another Instance Running."), TEXT("Tip"), MB_OK);
		CloseHandle(h);
		return 0;
	}

	// This is the first instance of this application running.
	// ...
	Sleep(10000);
	// Before exiting, close the object.
	CloseHandle(h);
	return 0;
}