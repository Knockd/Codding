#include<Windows.h>
#include<tchar.h>
#include<stdio.h>
void TestCreateKey(HKEY hKey,LPCWSTR SubKey) {
	HKEY KeyResult;
	//LPSECURITY_ATTRIBUTES lpSecurityAttributes;
	int retCode = RegCreateKeyEx(hKey,SubKey, 0, 0, 0,0,NULL,&KeyResult, (LPDWORD)REG_CREATED_NEW_KEY);
	 if (retCode == ERROR_SUCCESS) {
		 printf("����ʧ����");
	 }
	 else {
		 printf("�����ɹ���");
	 }
		
}
int _tmain() {
	LPCWSTR SubKey = TEXT("a\\b\\c\\d");
	TestCreateKey(HEKY_CURRENT_USER, SubKey);
	return 0;

}