#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain() {
	HKEY hMainKey = HKEY_CURRENT_USER;
	HKEY hSubKey;

	LONG ReturnValue = RegOpenKeyEx(hMainKey,TEXT("Control Panel"),0L,
		KEY_ENUMERATE_SUB_KEYS,&hSubKey);
	if (ReturnValue == ERROR_SUCCESS) {
		FILETIME ftLastWriteTime;
		SYSTEMTIME sysTime;
		TCHAR tcKeyName[128];
		DWORD dwKeyNameSize = 128;
		int i = 0, retCode = 0;
		printf("%-30s%-30s","键名","最后一次写入时间");
		printf("\n");
		CHAR tcBuffer[256] = { 0 };
		while (1) {
			retCode = RegEnumKeyEx(hSubKey, i, tcKeyName, &dwKeyNameSize,
				NULL,NULL,NULL,&ftLastWriteTime);
			if (retCode == ERROR_NO_MORE_ITEMS) {
				break;
			}
			//将文件时间转化为系统时间
			FileTimeToSystemTime(&ftLastWriteTime, &sysTime);
			sprintf_s(tcBuffer, "%02d-%02d-%02d  %02d:%02d:%02d", sysTime.wYear,
				sysTime.wMonth, sysTime.wDay, sysTime.wHour, sysTime.wMinute,
				sysTime.wSecond);
			printf("%-30ls%-30s", tcKeyName, tcBuffer);
			printf("\n");
			dwKeyNameSize = 128;
			i++;
		}
	}
	return 0;

}